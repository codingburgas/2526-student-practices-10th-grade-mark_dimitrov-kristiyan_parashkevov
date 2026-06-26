#pragma once
#include "db_connection_parameters.h"
#include <QDialog>

class QComboBox;
class QLineEdit;
class QSpinBox;

class DatabaseConnectionDialog : public QDialog
{
public:
    explicit DatabaseConnectionDialog(QWidget* parent = nullptr);

    database::ConnectionParameters createConnectionParameters() const;

private:
    QLineEdit* addressBox;
    QSpinBox* portSpinBox;
    QComboBox* authenticationTypeBox;
    QLineEdit* usernameBox;
    QLineEdit* passwordBox;
};
