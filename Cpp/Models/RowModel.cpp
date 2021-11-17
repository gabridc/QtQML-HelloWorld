#include "RowModel.h"
#include <iostream>

int RowModel::rowCount(const QModelIndex &parent) const
{
    if ( parent.isValid() )
        return 0;
    return cells_.size();
}

QHash<int, QByteArray> RowModel::roleNames() const {
    return roleNames_;
}

void RowModel::add(int index, const QString& columnName, CellModel* cell)
{
    std::cout << "ADD Cell " << index << columnName.toStdString() << std::endl;
    cells_.push_back(cell);
    roleNames_.insert(index, columnName.toUtf8());
    std::cout << cells_.count() << std::endl;

}

QList<CellModel*> RowModel::cells(void)
{
    return cells_;
}


void RowModel::setCells (QList<CellModel*> cells)
{
    cells_ = cells;
}

QVariant RowModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        auto roles = RowModel::getRoleNames();
        for(auto roleID :  roles.keys())
        {
            if(roleID == role)
            {
                return cells_[index.row()]->getColumn();
            }
        }
    }
    return QVariant();
}

bool RowModel::setData(const QVariant &value, int role) const
{
    return true;
}

QHash<int, QByteArray> RowModel::getRoleNames(void) const
{
    return roleNames_;
}
