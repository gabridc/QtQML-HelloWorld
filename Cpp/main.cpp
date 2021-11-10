#include <iostream>
#include <QApplication>
#include <QQmlApplicationEngine>
#include "Hello.h"


int main(int argc, char *argv[])
{

    Q_INIT_RESOURCE(qml);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    qmlRegisterType<Hello>("es.hello", 1, 0, "HelloImp");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main"));
    engine.load(url);



    return app.exec();
}