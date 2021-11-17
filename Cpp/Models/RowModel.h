
#ifndef ROWMODEL_OPERATION_H
#define ROWMODEL_OPERATION_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include "CellModel.h"
#include <QAbstractListModel>
#include <iostream>

class RowModel : public QAbstractListModel 
{

    Q_OBJECT
    Q_PROPERTY(QList<CellModel*> cells READ cells WRITE setCells NOTIFY cellsChanged)

public:
    RowModel(QObject* parent = 0){};
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;


    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QVariant &value, int role) const;
    void add(int index, const QString& columnName, CellModel* cell);
    QList<CellModel*> cells(void);
    void setCells (QList<CellModel*> cells);
    QHash<int, QByteArray> getRoleNames(void) const;

public slots:
    void print(void);
    CellModel* getCell(int index);


signals:
    void cellsChanged(bool foo);

private:
    QList<CellModel*> cells_;
    QHash<int, QByteArray> roleNames_;


};

#endif