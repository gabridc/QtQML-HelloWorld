#include "CellModel.h"

class ForeignModel : public CellModel
{

public:
    ForeignModel(QObject *parent = 0){};
    ForeignModel& operator=(const ForeignModel& c);

    void setCurrentValue(const QString& currentValue)
    {
        currentValue_ = currentValue.toInt();
    }

    QString display(void) {return QString::number(currentValue_);};

    QString currentValue(void)
    {
        return QString::number(currentValue_);
    }

private:
    int currentValue_;
    int oldValue;
    QString foreignKey;
    QString foreignTable;

};