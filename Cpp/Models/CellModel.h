#ifndef CELLMODEL_OPERATION_H
#define CELLMODEL_OPERATION_H

#include <QObject>
#include <QString>


class CellModel : public QObject
{

Q_OBJECT

public:
    
    

    CellModel(QObject *parent = 0){};
    ~CellModel(void) = default;

    CellModel& operator=(const CellModel& c);

    void setTable(const QString& table);
    void setColumn(const QString& column);
    QString getColumn(void) const;
    QString getTable(void) const;


private:
    QString table_;
    QString column_;


};

#endif