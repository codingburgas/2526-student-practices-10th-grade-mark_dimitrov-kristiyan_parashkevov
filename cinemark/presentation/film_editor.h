#pragma once

#include <QWidget>

class FilmTableView;
class DatabaseConnectionDialog;

class FilmEditor : public QWidget
{
    Q_OBJECT

public:
    explicit FilmEditor(QWidget* parent = nullptr);

public slots:
    void connect();

private:
    FilmTableView* table;

    DatabaseConnectionDialog* connectionDialog;
};
