#pragma once

#include <qtmetamacros.h>
#include <QString>

namespace database {
    Q_NAMESPACE

enum AuthenticationType
{
    Windows,
    SqlPassword,
    ActiveDirectoryIntegrated,
    ActiveDirectoryInteractive,
    ActiveDirectoryMsi,
    ActiveDirectoryServicePrincipal
};
    Q_ENUM_NS(AuthenticationType)

struct ConnectionParameters
{
    QString address;
    AuthenticationType authenticationType;
    QString username;
    QString password;
    int port = 1433;
};

}
