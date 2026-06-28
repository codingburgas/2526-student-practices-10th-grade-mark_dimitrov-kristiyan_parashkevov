#include "user_controller.h"
#include "user_query.h"

User UserController::getUser(const QString& username, const QString& password)
{
    User user;
    user.id = UserQuery::getUserId(username);
    user.username = username;
    return user;
}
