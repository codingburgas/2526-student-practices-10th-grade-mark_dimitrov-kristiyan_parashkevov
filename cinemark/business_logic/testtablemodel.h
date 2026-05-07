#pragma once
#include <QAbstractTableModel>
#include <QVector>
#include <QString>

class SimpleTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit SimpleTableModel(QObject* parent = nullptr)
        : QAbstractTableModel(parent)
    {
        m_data = {
            {"Alice", "24", "a"},
            {"Bob",   "30", "b"},
            {"Chis", "28", "c"}
        };
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return m_data.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return m_data.isEmpty() ? 0 : m_data[0].size();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
    {
        if (!index.isValid())
            return {};

        if (role == Qt::DisplayRole || role == Qt::EditRole)
            return m_data[index.row()][index.column()];

        return {};
    }

    bool setData(const QModelIndex& index, const QVariant& value, int role) override
    {
        if (!index.isValid() || role != Qt::EditRole)
            return false;

        m_data[index.row()][index.column()] = value.toString();

        emit dataChanged(index, index);
        return true;
    }

    Qt::ItemFlags flags(const QModelIndex& index) const override
    {
        if (!index.isValid())
            return Qt::NoItemFlags;

        return Qt::ItemIsSelectable |
               Qt::ItemIsEnabled |
               Qt::ItemIsEditable;
    }

private:
    QVector<QVector<QString>> m_data;
};
