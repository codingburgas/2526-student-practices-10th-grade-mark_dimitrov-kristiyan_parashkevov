#pragma once

#include "user.h"
#include <QString>

class UserController
{
public:
    static User getUser(const QString& username, const QString& password);
};
