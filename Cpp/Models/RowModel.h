
#ifndef ROWMODEL_OPERATION_H
#define ROWMODEL_OPERATION_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include "CellModel.h"

class RowModel : public QObject
{

    Q_OBJECT

public:
    RowModel(QObject* parent = 0){};
    QVariant data(int role) const;
    bool setData(const QVariant &value, int role) const;
    void add(const QString& columnName, CellModel* cell);
    QHash<int, QByteArray> getRoleNames(void) const;

private:
    QMap<QString, CellModel*> cells_;

};

#endif