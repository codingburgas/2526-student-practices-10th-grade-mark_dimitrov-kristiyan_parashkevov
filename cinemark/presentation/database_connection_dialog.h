#pragma once
#include <QDialog> // used for inheriting QDialog in the class below, shouldn't be moved to database_connection_dialog.cpp
class QLineEdit; // forward declaring (needed for the variables below)
class QSpinBox;

class DatabaseConnectionDialog : public QDialog
{
public:
    DatabaseConnectionDialog();
private:
    QLineEdit* nameLineEdit;
    QLineEdit* emailLineEdit;
    QSpinBox* ageSpinBox;
};