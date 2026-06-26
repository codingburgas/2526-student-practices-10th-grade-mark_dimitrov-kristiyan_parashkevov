#include "database_connection_dialog.h"
#include "db_connection_parameters.h"
#include <QMetaEnum>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QDialogButtonBox>
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
    QMetaEnum authenticationTypeEnum = QMetaEnum::fromType<database::AuthenticationType>();
    for (int i = 0; i < authenticationTypeEnum.keyCount(); i++)
    {
        authenticationTypeBox->addItem(authenticationTypeEnum.key(i));
    }

    portSpinBox->setMaximum(65535);

    QHBoxLayout* addressFieldsLayout = new QHBoxLayout;
    addressFieldsLayout->addWidget(addressBox);
    addressFieldsLayout->addWidget(portSpinBox);

    auto* buttonRow = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    QObject::connect(buttonRow, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QFormLayout* formLayout = new QFormLayout(this);
    formLayout->addRow("Address:", addressFieldsLayout);
    formLayout->addRow("Authentication type:", authenticationTypeBox);
    formLayout->addRow("Username:", usernameBox);
    formLayout->addRow("Password:", passwordBox);
    formLayout->addRow(buttonRow);
}

database::ConnectionParameters DatabaseConnectionDialog::createConnectionParameters() const
{
    database::ConnectionParameters parameters;
    parameters.address = addressBox->text();
    parameters.port = portSpinBox->value();
    parameters.authenticationType = (database::AuthenticationType)authenticationTypeBox->currentIndex();
    parameters.username = usernameBox->text();
    parameters.password = passwordBox->text();
    return parameters;
}
