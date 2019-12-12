//===========================================
#include "ZVariableTableModel.h"

#include <QDebug>
//===========================================
ZVariableTableModel::ZVariableTableModel(QObject* parent) : QAbstractTableModel(parent) {}
//===========================================
Qt::ItemFlags ZVariableTableModel::flags(const QModelIndex& index) const
{
    Qt::ItemFlags flags;
    flags = Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
    return flags;
}
//===========================================
int ZVariableTableModel::rowCount(const QModelIndex& parent) const
{
    return zv_variableList.count();
}
//===========================================
int ZVariableTableModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}
//===========================================
QVariant ZVariableTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        if (role == Qt::DisplayRole)
        {
            switch (section)
            {
            case 0:
                return QVariant(tr("Name"));

            case 1:
                return QVariant(tr("Value"));

            default:
                return QVariant();
            }
        }
    }
    else // Vertical
    {
        if (section >= 0 || section < rowCount())
        {
            if (role == Qt::DisplayRole)
            {
                return QString::number(section + 1);
            }
        }
    }

    return QVariant();
}
//===========================================
QVariant ZVariableTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= rowCount() || index.column() < 0
        || index.column() >= columnCount())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
        {
            return QVariant(zv_variableList.at(index.row()).first);
        }

        if (index.column() == 1)
        {
            return QVariant(zv_variableList.at(index.row()).second);
        }
    }

    return QVariant();
}
//===========================================
bool ZVariableTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid() || index.row() < 0 || index.row() >= rowCount() || index.column() < 0
        || index.column() >= columnCount())
    {
        return false;
    }

    if (role == Qt::EditRole)
    {
        if (index.column() == 0)
        {
            zv_variableList[index.row()].first = value.toString();
            return true;
        }

        if (index.column() == 1)
        {
            bool ok = false;
            qreal dValue = value.toDouble(&ok);
            if (!ok)
            {
                return false;
            }
            zv_variableList[index.row()].second = dValue;
            return true;
        }
    }

    return false;
}
//===========================================
bool ZVariableTableModel::insertRows(int row, int count, const QModelIndex& parent)
{
    if (count < 1)
    {
        return false;
    }

    beginInsertRows(parent, row, row + count - 1);
    for (int i = 0; i < count; ++i)
    {
        zv_variableList.insert(row + i, QPair<QString, qreal>());
    }
    endInsertRows();
    return true;
}
//===========================================
bool ZVariableTableModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (count < 1 || row < 0 || row >= rowCount())
    {
        return false;
    }

    int last = row + count - 1 >= rowCount() ? rowCount() - 1 : row + count - 1;
    beginRemoveRows(parent, row, last);
    for (int i = count - 1; i >= 0; --i)
    {
        zv_variableList.removeAt(last - i);
    }
    endRemoveRows();

    return true;
}
//===========================================
void ZVariableTableModel::zp_variableValue(const QString& variableName, qreal& value, bool& ok) const
{
    for (int i = 0; i < zv_variableList.count(); ++i)
    {
        if (zv_variableList.at(i).first == variableName)
        {
            value = zv_variableList.at(i).second;
            ok = true;
            return;
        }
    }

    ok = false;
}
//===========================================
