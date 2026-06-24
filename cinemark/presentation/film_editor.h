#pragma once

#include <QWidget>

class DatabaseConnectionDialog;

class FilmEditor : public QWidget
{
public:
    explicit FilmEditor(QWidget* parent = nullptr);

private:
    DatabaseConnectionDialog* connectionDialog;
};
