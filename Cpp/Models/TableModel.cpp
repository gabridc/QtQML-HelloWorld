#include <TableModel.h>



void TableModel::add(RowModel* row)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());   // kindly provided by superclass
    rows_.push_back(row);

    if(roleNames_.count() == 0)
        roleNames_ = row->getRoleNames();
    endInsertRows();                                          // kindly provided by superclass
}


QList<RowModel*> TableModel::rows(void) {return rows_;}
void TableModel::setRows(const QList<RowModel*> rows) { rows_ = rows;}
QList<RowModel *> TableModel::getRows(void) const {return rows_;}
int TableModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid() )
        return 0;

    return rows_.count();
}



QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
        return rows_.at(index.row())->data(role);
}


bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) 
        return rows_.at(index.row())->setData(value, role);
}

QHash<int, QByteArray> TableModel::roleNames() const {
    return roleNames_;
}
