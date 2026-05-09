#pragma once

#include <QSqlTableModel>

struct dbConnectionParameters
{
    QString address = QString();
    QString username = QString();
    QString password = QString();
    int port = 1433;
};

class FilmTableModel : public QSqlTableModel
{
public:
    static FilmTableModel* connect(const dbConnectionParameters&, QObject* parent = nullptr);

private:
    FilmTableModel(QObject* parent = nullptr);

    static bool ensureFilmsTable();
};
