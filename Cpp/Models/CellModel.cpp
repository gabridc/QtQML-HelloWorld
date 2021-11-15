#include "CellModel.h"



QString CellModel::getColumn(void) const
{
    return column_;
}

    void CellModel::setTable(const QString& table){table_ = table;}
    void CellModel::setColumn(const QString& column) {column_ = column;}
    QString CellModel::getTable(void) const {return table_;}