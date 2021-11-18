#ifndef CELLMODEL_OPERATION_H
#define CELLMODEL_OPERATION_H

#include <QObject>
#include <QString>


class CellModel : public QObject
{

Q_OBJECT

public:
    void setTable(const QString& table);
    void setColumn(const QString& column);
    QString getColumn(void) const;
    QString getTable(void) const;
    virtual void setCurrentValue(const QString& currentValue) = 0;



public slots:
    void print(void);
    virtual QString display(void) = 0;
    virtual QString currentValue(void) = 0;

private:
    QString table_;
    QString column_;
    int row_;


};

#endif