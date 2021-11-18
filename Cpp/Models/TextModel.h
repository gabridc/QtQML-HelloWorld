#ifndef TEXTMODEL_OPERATION_H
#define TEXTMODEL_OPERATION_H


#include "CellModel.h"

class TextModel : public CellModel
{

public:
    TextModel(QObject *parent = 0){};
   /*TextModel(const QString& table, const QString& column, const QString& currentValue, const QString& oldValue, QObject *parent = 0) : 
            currentValue_(currentValue),
            oldValue_(oldValue)
            {    
                table_ = table;
                column_ = column;
            };*/
    TextModel& operator=(const TextModel& c);


    void setOldValue(void);
    QString display(void) {return currentValue_;};

    void setCurrentValue(const QString& currentValue)
    {
        currentValue_ = currentValue;
    }

    QString currentValue(void)
    {
        return currentValue_;
    }
    

private:
    QString currentValue_;
    QString oldValue_;

};

#endif