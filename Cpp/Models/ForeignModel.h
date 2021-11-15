#include "CellModel.h"

class ForeignModel : public CellModel
{

public:
    ForeignModel(void) = default;
    ForeignModel& operator=(const ForeignModel& c);
private:
    int currentValue;
    int oldValue;
    QString foreignKey;
    QString foreignTable;

};