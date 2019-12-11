//===========================================
#ifndef ZVARIABLETABLEMODEL_H
#define ZVARIABLETABLEMODEL_H
//===========================================
#include <QAbstractTableModel>
//===========================================

//===========================================
class ZVariableTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ZVariableTableModel(QObject* parent = nullptr);

    // Overrided funcs
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    // End of overrided funcs

protected:
    bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;
signals:

public slots:

private:
    //VARS
    QList<QPair<QString, qreal>> zv_variableList;
    //FUNCS
};
//===========================================
#endif // ZVARIABLETABLEMODEL_H
