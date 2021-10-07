import sys
sys.path.append('D:\Qt-Workspace\Asteria\openpyxl')
sys.path.append('D:\Qt-Workspace\Asteria\PySide2')
from PySide2.QtQml import *
from PySide2.QtGui import QGuiApplication
from PySide2.QtQuick import QQuickView
from PySide2.QtCore import QUrl, QObject, Signal, Slot, Property

class Backend(QObject):
 
    def __init__(self):
        QObject.__init__(self)


def main():
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()

    qmlRegisterType(Backend, 'Backend', 1, 0, 'Backend')

    mainWindow = Backend()

    engine.load(QUrl("main.qml"))
  
    if not engine.rootObjects():
        sys.exit(-1)    

    app.exec_()


if __name__ == "__main__":
    main()
