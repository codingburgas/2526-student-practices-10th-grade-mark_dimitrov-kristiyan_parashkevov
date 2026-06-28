#include "database.h"
#include <QSqlDatabase>
#include <QMetaEnum>
#include <QStringBuilder>

bool Database::ensureDefaultConnection(const database::ConnectionParameters& params)
{
    static bool connected = false;

    if (connected)
        return true;

    QSqlDatabase connection = QSqlDatabase::addDatabase("QODBC");
    connection.setDatabaseName(buildConnectionString(params));

    return connected = connection.open(params.username, params.password);
}

QString Database::buildConnectionString(const database::ConnectionParameters& params)
{
    return "Driver=ODBC Driver 18 for SQL Server;"
           "Server=" % params.address %
           ";Encrypt=yes;TrustServerCertificate=yes;" %
           (params.authenticationType == database::Windows ? QString("Trusted_Connection=yes") : QString("Authentication=") % QMetaEnum::fromType<database::AuthenticationType>().valueToKey(params.authenticationType));
}
