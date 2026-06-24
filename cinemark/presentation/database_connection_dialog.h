#pragma once
#include <QDialog>

class QComboBox;
class QLineEdit;
class QSpinBox;

class DatabaseConnectionDialog : public QDialog
{
public:
    DatabaseConnectionDialog();

private:
    QLineEdit* addressBox;
    QSpinBox* portSpinBox;
    QComboBox* authenticationTypeBox;
    QLineEdit* usernameBox;
    QLineEdit* passwordBox;
};
