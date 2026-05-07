#include "database.h"
#include <QSqlDatabase>

Database::Database() {
    QSqlDatabase database = QSqlDatabase::addDatabase("QODBC");
    database.setDatabaseName("DRIVER=ODBC Driver 18 for SQL Server; TrustServerCertificate=Yes; Trusted_Connection=Yes; SERVER=localhost\\SQLEXPRESS");
    database.open();
}
