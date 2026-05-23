#pragma once

#include "db_connection_parameters.h"
#include <QHash>
#include <QSqlTableModel>

class FilmTableModel : public QSqlTableModel
{
public:
    static FilmTableModel* connect(const database::ConnectionParameters&, QObject* parent = nullptr);

    bool setHeaderData(int row, Qt::Orientation, const QVariant& value, int = Qt::EditRole) override;
    QVariant headerData(int row, Qt::Orientation, int = Qt::DisplayRole) const override;

private:
    FilmTableModel(QObject* parent = nullptr);
    static bool ensureFilmsTable();

    QHash<int, QHashDummyValue> blankedHeaderRows;
};
