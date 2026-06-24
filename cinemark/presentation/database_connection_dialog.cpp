#include "database_connection_dialog.h"
#include "db_connection_parameters.h"
#include <QMetaEnum>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>

DatabaseConnectionDialog::DatabaseConnectionDialog(QWidget* parent)
    : QDialog(parent)
    , addressBox(new QLineEdit(this))
    , portSpinBox(new QSpinBox(this))
    , authenticationTypeBox(new QComboBox(this))
    , usernameBox(new QLineEdit(this))
    , passwordBox(new QLineEdit(this))
{
    QMetaEnum authenticationTypeEnum = QMetaEnum::fromType<database::ConnectionParameters>();
    for (int i = 0; i < authenticationTypeEnum.keyCount(); i++)
    {
        authenticationTypeBox->addItem(authenticationTypeEnum.key(i));
    }

    QHBoxLayout* addressFieldsLayout = new QHBoxLayout(this);
    addressFieldsLayout->addWidget(addressBox);
    addressFieldsLayout->addWidget(portSpinBox);

    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow("Address:", addressFieldsLayout);
    formLayout->addRow("Authentication type:", authenticationTypeBox);
    formLayout->addRow("Username:", usernameBox);
    formLayout->addRow("Password:", passwordBox);
}
