#include "CellModel.h"
#include <iostream>


QString CellModel::getColumn(void) const
{
    return column_;
}

    int CellModel::row(void) const {return row_;}
    void CellModel::setRow(int row) {row = row_;}
    QString CellModel::display(void) {return QString::number(row_);}

    void CellModel::setTable(const QString& table){table_ = table;}
    void CellModel::setColumn(const QString& column) {column_ = column;}
    QString CellModel::getTable(void) const {return table_;}

void CellModel::print(void)
{
    std::cout << column_.toStdString() << std::endl;
}