#pragma once

#include "db_connection_parameters.h"
#include <QSqlTableModel>

class FilmTableModel : public QSqlTableModel
{
public:
    static FilmTableModel* connect(const database::ConnectionParameters&, QObject* parent = nullptr);

private:
    FilmTableModel(QObject* parent = nullptr);

    static bool ensureFilmsTable();
};
