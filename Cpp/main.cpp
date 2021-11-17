#include <iostream>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Hello.h"
#include "TableModel.h"
#include "RowModel.h"
#include "CellModel.h"
#include "CellModelfactory.h"
#include "TextModel.h"

int main(int argc, char *argv[])
{

    Q_INIT_RESOURCE(qml);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qmlRegisterUncreatableType<TableModel>("es.broker", 1, 0, "OperationsModel", "OperationsModel sholud not be created in QMl");
    qmlRegisterUncreatableType<RowModel>("es.broker", 1, 0, "RowModel", "Operation sholud not be created in QMl");
    qmlRegisterUncreatableType<CellModel>("es.broker", 1, 0, "CellModel", "Operation sholud not be created in QMl");
    qmlRegisterUncreatableType<CellModelFactory>("es.broker", 1, 0, "CellModelfactory", "Operation sholud not be created in QMl");
    qmlRegisterUncreatableType<TextModel>("es.broker", 1, 0, "TextModel", "Operation sholud not be created in QMl");

    TableModel tableModel;
    

    
   ///HEADER
    for(int i = 0; i < 10000; i++)
    {
        RowModel *rowModel = new RowModel();
        CellModelFactory *cell = new CellModelFactory("TEXT");
        cell->getInstance()->setTable("SW");
        cell->getInstance()->setColumn("id");
        rowModel->add(0, "id", cell->getInstance());
        CellModelFactory *cell1 = new CellModelFactory("TEXT");
        cell1->getInstance()->setTable("SW");
        cell1->getInstance()->setColumn("name");
        rowModel->add(1, "name", cell1->getInstance());  
        CellModelFactory *cell2= new CellModelFactory("TEXT");
        cell2->getInstance()->setTable("SW");
        cell2->getInstance()->setColumn("phone");
        rowModel->add(2, "phone", cell2->getInstance());  
        CellModelFactory *cell3 = new CellModelFactory("TEXT");
        cell3->getInstance()->setTable("SW");
        cell3->getInstance()->setColumn("mail");
        rowModel->add(3, "mail", cell3->getInstance());  
        tableModel.add(rowModel);
    }


    QApplication app(argc, argv);
    qmlRegisterType<Hello>("es.hello", 1, 0, "HelloImp");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("tableModel", &tableModel);
    const QUrl url(QStringLiteral("qrc:/main"));
    engine.load(url);



    return app.exec();
}