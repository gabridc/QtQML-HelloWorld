import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.14

Window{

    id: mainWindow
    visible: true
    width: 800
    height: 480
    color: "#e9e7e7"
    title: qsTr("Window")

    Rectangle{
        width: 200
        height: 200
        color: "red"
    }

}