#pragma once

#include <QSqlTableModel>

namespace database {
Q_NAMESPACE

enum AuthenticationType
{
    Windows,
    SqlPassword,
    ActiveDirectoryIntegrated,
    ActiveDirectoryInteractive,
    ActiveDirectoryMsi,
    ActiveDirectoryServicePrincipal
};
Q_ENUM_NS(AuthenticationType)

struct ConnectionParameters
{
    QString address;
    AuthenticationType authenticationType;
    QString username;
    QString password;
    int port = 1433;
};

class FilmTableModel : public QSqlTableModel
{
public:
    static FilmTableModel* connect(const ConnectionParameters&, QObject* parent = nullptr);

private:
    FilmTableModel(QObject* parent = nullptr);

    static bool ensureFilmsTable();
};

}
