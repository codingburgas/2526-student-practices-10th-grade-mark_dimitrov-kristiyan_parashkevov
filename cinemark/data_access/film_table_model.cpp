#include "film_table_model.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringBuilder>
using namespace Qt::StringLiterals;

FilmTableModel::FilmTableModel(QObject* parent)
    : QSqlTableModel(parent)
{
    setTable(u"Films"_s);
    select();
}

FilmTableModel* FilmTableModel::connect(const dbConnectionParameters& params, QObject* parent)
{
    auto buildConnectionString = [&params]() -> QString
    {
        return u"Driver=ODBC Driver 18 for SQL Server;"
               u"Server="_s % params.address % QChar(',') % QString::number(params.port) %
               u";Encrypt=yes;TrustServerCertificate=yes;"_s %
               (params.username.isEmpty() ? u"Trusted_Connection=yes"_s : QString());
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
