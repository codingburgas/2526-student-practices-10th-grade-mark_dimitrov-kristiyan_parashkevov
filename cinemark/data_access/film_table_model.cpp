#include "film_table_model.h"
#include <QMetaEnum>
#include <QStringBuilder>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
using namespace Qt::StringLiterals;
using namespace database;

FilmTableModel::FilmTableModel(QObject* parent)
    : QSqlTableModel(parent)
{
    setEditStrategy(OnManualSubmit);
    setTable(u"Films"_s);
    select();
}

FilmTableModel* FilmTableModel::connect(const ConnectionParameters& params, QObject* parent)
{
    auto buildConnectionString = [&params]() -> QString
    {
        return u"Driver=ODBC Driver 18 for SQL Server;"
               u"Server="_s % params.address % QChar(',') % QString::number(params.port) %
               u";Encrypt=yes;TrustServerCertificate=yes;"_s %
               (params.authenticationType == Windows ? u"Trusted_Connection=yes"_s : u"Authentication="_s % QMetaEnum::fromType<AuthenticationType>().valueToKey(params.authenticationType));
    };

    QSqlDatabase connection = QSqlDatabase::addDatabase(u"QODBC"_s);
    connection.setDatabaseName(buildConnectionString());

    if (!connection.open(params.username, params.password) || !ensureFilmsTable())
    {
        return nullptr;
    }

    return new FilmTableModel(parent);
}

bool FilmTableModel::ensureFilmsTable()
{
    return !QSqlQuery(QStringLiteral(
        "IF OBJECT_ID(N'Films', N'U') IS NULL "
        "CREATE TABLE Films ("
        "   Id INT PRIMARY KEY IDENTITY,"
        "   Poster NVARCHAR(90),"
        "   Title NVARCHAR(40),"
        "   Genre NVARCHAR(20),"
        "   Projection NVARCHAR(20));"
        "IF OBJECT_ID(N'Users', N'U') IS NULL "
        "CREATE TABLE Users ("
        "   Id INT PRIMARY KEY IDENTITY,"
        "   Username NVARCHAR(20),"
        "   Password NVARCHAR(100));"
        "IF OBJECT_ID(N'Tickets', N'U') IS NULL "
        "CREATE TABLE Tickets ("
        "   Id INT PRIMARY KEY IDENTITY,"
        "   UserId INT FOREIGN KEY REFERENCES Users(Id),"
        "   FilmId INT FOREIGN KEY REFERENCES Films(Id),"
        "   SeatNumber INT)")).lastError().isValid();
}

bool FilmTableModel::insertRows(int count, int, const QModelIndex&)
{
    if (insertedRowsSeparatorIndex.isValid())
        return QSqlTableModel::insertRows(0, count);

    if (QSqlTableModel::insertRows(0, count + 1))
    {
        insertedRowsSeparatorIndex = index(count, 0);
        return true;
    }
    else
    {
        return false;
    }
}

bool FilmTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!QSqlTableModel::setData(index, value, role))
        return false;

    QModelIndex rowIndex = this->index(index.row(), 0);
    bool rowIsMarked = changedRows.contains(rowIndex);
    bool differentFromOriginal = data(index, role) != QSqlQueryModel::data(index, role);

    if (differentFromOriginal)
    {
        changedRows[rowIndex].insert(index.column(), QHashDummyValue());

        if (!rowIsMarked)
        {
            emit headerDataChanged(Qt::Vertical, index.row(), index.row());
        }
    }
    else if (rowIsMarked)
    {
        changedRows[rowIndex].remove(index.column());

        if (changedRows[rowIndex].isEmpty())
        {
            changedRows.remove(rowIndex);
            emit headerDataChanged(Qt::Vertical, index.row(), index.row());
        }
    }

    return true;
}

QVariant FilmTableModel::headerData(int row, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical && role == Qt::DisplayRole)
    {
        if (row == separatorRow())
        {
            return QVariant();
        }
        if (changedRows.contains(index(row, 0)))
        {
            return "*"_L1;
        }
    }

    return QSqlTableModel::headerData(row, orientation, role);
}

bool FilmTableModel::submitAll()
{
    clearChangeMarkers();
    return QSqlTableModel::submitAll();
}

void FilmTableModel::revertAll()
{
    clearChangeMarkers();
    QSqlTableModel::revertAll();
}

void FilmTableModel::clearChangeMarkers()
{
    changedRows.clear();
    insertedRowsSeparatorIndex = QPersistentModelIndex();
    emit headerDataChanged(Qt::Vertical, 0, rowCount() - 1);
}

int FilmTableModel::separatorRow() const
{
    return insertedRowsSeparatorIndex.row();
}
