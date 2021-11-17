#include <TableModel.h>
#include <iostream>


void TableModel::add(RowModel* row)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());   // kindly provided by superclass
    rows_.push_back(row);

   //if(roleNames_.count() == 0)
      //  roleNames_ = row->getRoleNames();
    endInsertRows();                                          // kindly provided by superclass

    if(columns_.size() == 0)
    {
        beginInsertColumns(QModelIndex(), columnCount(), columnCount());   // kindly provided by superclass
        for(auto c : row->cells())
            columns_.push_back(c->getColumn());
        endInsertColumns(); 
    }
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

int TableModel::columnCount(const QModelIndex &parent) const
{
    if ( parent.isValid() )
        return 0;

    return columns_.count();
}



QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        return rows_[index.row()]->cells().at(index.column())->getColumn();
    }
}

std::tuple<int, int> TableModel::getIndex(int index)
{
    auto row = index % 10000;
    auto column = (index - row ) / 10000;
    return std::tuple<int, int>(row, column);
}

CellModel* TableModel::getCell(int index)
{
    auto row = std::get<0>(getIndex(index));
    auto column = std::get<1>(getIndex(index));
    return rows_[row]->cells()[column];
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid()) 
        return rows_.at(index.row())->setData(value, role);
}
