#include "user_query.h"
#include "database.h"
#include <QSqlQuery>

int UserQuery::getUserId(const QString& username)
{
    Database::ensureDefaultConnection();

    QSqlQuery query;
    query.prepare("SELECT TOP 1 Id FROM Users WHERE Username = ?");
    query.addBindValue(username);
    query.exec(); query.next();
    return query.value(0).toInt();
}
