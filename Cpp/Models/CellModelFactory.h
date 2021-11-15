#ifndef CELLMODELFACTORY_H
#define CELLMODELFACTORY_H

#include  "CellModel.h"
#include "TextModel.h"
#include "ForeignModel.h"

class CellModelFactory : public QObject
{

public:

    CellModelFactory(const QString type, QObject *object=0)
    {
        if("FOREIGN KEY")
            cell = new ForeignModel();
        else if("TEXT")
            cell = new TextModel();
    }

    CellModel* getInstance(void) {return cell;}

private:
    CellModel *cell; 

};

#endif