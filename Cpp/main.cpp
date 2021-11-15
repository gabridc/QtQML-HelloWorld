#include <iostream>
#include <QApplication>
#include <QQmlApplicationEngine>
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
    

    

    for(int i = 0; i < 10; i++)
    {
        RowModel *rowModel = new RowModel();
        for(int j = 0; j < 5; j++)
        {
            CellModelFactory *cell = new CellModelFactory("TEXT");
            cell->getInstance()->setTable("SW");
            cell->getInstance()->setColumn("ID");
            rowModel->add("ID " + QString::number(j), cell->getInstance());  
        }

        std::cout << rowModel->getRoleNames().count() << std::endl;

        tableModel.add(rowModel);
    }

    

    auto rows = tableModel.getRows();
    int i = 0;
    for(auto r : rows)
    {
        std::cout << i << std::endl;
        auto roles = r->getRoleNames();
            for(auto c : roles)
                std::cout << c.toStdString() << std::endl;
        i++;
    }
    





    QApplication app(argc, argv);
    qmlRegisterType<Hello>("es.hello", 1, 0, "HelloImp");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main"));
    engine.load(url);



    return app.exec();
}