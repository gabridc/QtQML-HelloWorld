#ifndef CELLMODEL_OPERATION_H
#define CELLMODEL_OPERATION_H

#include <QObject>
#include <QString>


class CellModel : public QObject
{

Q_OBJECT
Q_PROPERTY(int row READ row WRITE setRow)
Q_PROPERTY(QString display READ display)


public:
    
    

    CellModel(QObject *parent = 0){row_ = 19;};
    ~CellModel(void) = default;

    CellModel& operator=(const CellModel& c);

    void setTable(const QString& table);
    void setColumn(const QString& column);
    QString getColumn(void) const;
    QString getTable(void) const;

    int row(void) const;
    void setRow(int row);
    QString display(void);

public slots:
    void print(void);


private:
    QString table_;
    QString column_;
    int row_;


};

#endif