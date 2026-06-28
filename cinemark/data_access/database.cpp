#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMetaEnum>
#include <QStringBuilder>

bool Database::ensureDefaultConnection(const database::ConnectionParameters& params)
{
    static bool connected = false;

    if (connected)
        return true;

    QSqlDatabase connection = QSqlDatabase::addDatabase("QODBC");
    connection.setDatabaseName(buildConnectionString(params));

    if (!connection.open(params.username, params.password))
        return false;

    return connected = ensureDefaultTables();
}

QString Database::buildConnectionString(const database::ConnectionParameters& params)
{
    return "Driver=ODBC Driver 18 for SQL Server;"
           "Server=" % params.address %
           ";Encrypt=yes;TrustServerCertificate=yes;" %
           (params.authenticationType == database::Windows ? QString("Trusted_Connection=yes") : QString("Authentication=") % QMetaEnum::fromType<database::AuthenticationType>().valueToKey(params.authenticationType));
}

bool Database::ensureDefaultTables()
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
