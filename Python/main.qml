import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.14
import QtGraphicalEffects 1.0

Window{

    id: mainWindow
    visible: true
    width: 800
    height: 480
    color: "#e9e7e7"
    title: qsTr("Window")

    Rectangle{
        id: rect
        width: 200
        height: 200
        color: "red"
        radius: 20
        clip: true
    }

    Image{
        id: img
        
        property bool rounded: true
        property bool adapt: true

        layer.enabled: rounded
        anchors.fill: rect
        source: "peces-de-agua-dulce.jpg"
        layer.effect: OpacityMask {
        maskSource: Item {
            width: img.width
            height: img.height
            Rectangle {
                anchors.centerIn: parent
                width: img.adapt ? img.width : Math.min(img.width, img.height)
                height: img.adapt ? img.height : width
                radius: 20
            }
        }
        }
    }

}