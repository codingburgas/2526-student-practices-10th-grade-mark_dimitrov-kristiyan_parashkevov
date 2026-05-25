#include "database_connection_dialog.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>

DatabaseConnectionDialog::DatabaseConnectionDialog() {
    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow("Name:", nameLineEdit);
    formLayout->addRow("Email:", emailLineEdit);
    formLayout->addRow("Age:", ageSpinBox);
}