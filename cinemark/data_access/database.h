#pragma once

#include "db_connection_parameters.h"
#include <QString>

class Database
{
public:
    static bool ensureDefaultConnection(const database::ConnectionParameters& = {"localhost\\SQLEXPRESS", database::Windows});

private:
    static QString buildConnectionString(const database::ConnectionParameters&);
    static bool ensureDefaultTables();
};
