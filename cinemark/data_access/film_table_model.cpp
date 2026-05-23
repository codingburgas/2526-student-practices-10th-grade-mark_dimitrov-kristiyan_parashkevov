#include "film_table_model.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringBuilder>
#include <QMetaEnum>
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
    QSqlQuery(QStringLiteral(
        "IF OBJECT_ID(N'Films', N'U') IS NULL "
        "CREATE TABLE Films ("
        "   Poster NVARCHAR(MAX),"
        "   Title NVARCHAR(MAX))"));

    return true;
}

bool FilmTableModel::setHeaderData(int row, Qt::Orientation orientation, const QVariant& value, int role)
{
    if (orientation == Qt::Vertical)
    {
        if (!value.toBool())
        {
            blankedHeaderRows.insert(row, QHashDummyValue());
        }
        else
        {
            blankedHeaderRows.remove(row);
        }
        return true;
    }

    return QSqlTableModel::setHeaderData(row, orientation, value, role);
}

QVariant FilmTableModel::headerData(int row, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical && blankedHeaderRows.contains(row))
    {
        return QVariant();
    }

    return QSqlTableModel::headerData(row, orientation, role);
}
