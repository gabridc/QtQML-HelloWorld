#include "RowModel.h"
#include <iostream>

void RowModel::add(const QString& columnName, CellModel* cell)
{

    cells_.insert(columnName, cell);
    std::cout << cells_.count() << std::endl;

}

QVariant RowModel::data(int role) const
{
    return QVariant();
}

bool RowModel::setData(const QVariant &value, int role) const
{
    return true;
}

QHash<int, QByteArray> RowModel::getRoleNames(void) const
{
    QHash<int, QByteArray> roleNames;
    int index = 1;

    for(auto k : cells_.keys())
    {
        std::cout << k.toStdString() << std::endl;
        roleNames.insert(index, k.toUtf8());
    }

    return roleNames;
}
