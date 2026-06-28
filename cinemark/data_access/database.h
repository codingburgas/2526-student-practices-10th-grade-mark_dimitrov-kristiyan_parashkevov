#pragma once

#include "db_connection_parameters.h"
#include <QString>

class Database
{
public:
    static bool ensureDefaultConnection(const database::ConnectionParameters& = {"localhost", database::SqlPassword, "glaresheen", "2PGn0vxiaV"});

private:
    static QString buildConnectionString(const database::ConnectionParameters&);
};
