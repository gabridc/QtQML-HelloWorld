import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.1


Window {
    id: mainWindow
    visible: true
    height: Screen.height
    width: Screen.width
    //visibility: "FullScreen"
    color: "#e9e7e7"
    title: qsTr("Hello")
    
    signal resize(var w, var c)

    Component.onCompleted:{
    }
    
    Row
    {
        id: header

        anchors.top: mainWindow.top
        anchors.topMargin: 20
        
        anchors.left: mainWindow.left
        anchors.leftMargin: 20
        
        anchors.right: mainWindow.right
        anchors.rightMargin: 20

        spacing: 10
       

         Repeater {
            model: tableModel
            delegate: Text{
                id: col
                width: 150;
                height: 30
                text: name
                property int index_: index 

                Component.onCompleted: console.log(tableModel.rowCount())
                ToolSeparator{ 
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    orientation: Qt.Vertical
                }
                MouseArea{
                    anchors.fill: col
                    property int lastX: 0
                    property int minimum: 0
                    onPositionChanged: {
                        if(minimum != 0) //Forzar que primero se tenga que hacer click
                        {
                            console.log(col.index_);
                            if(mouse.x  > minimum )
                            {
                                col.width += mouse.x - lastX
                                mainWindow.resize(mouse.x - lastX, col.index_ )
                            }
                            lastX = mouse.x
                        }
                    }
                    onClicked: {
                        if(minimum == 0)
                        {
                            minimum = mouse.x
                        }
                        lastX = mouse.x
                        console.log("Clicked "  + (mouse.x - lastX))
                    
                    }
                }
            }
        }
    }

    
    Column {
        anchors.top: header.top
        anchors.topMargin: 50

        anchors.left: header.left
        anchors.leftMargin: 0
        
        anchors.right: header.right
        anchors.rightMargin: 0
        spacing: 5

         Repeater {
            model: tableModel.rows
            delegate: Row{
                id: data
                property var data_: ""
                spacing: 10

                Repeater {
                    model: tableModel
                    delegate: Text{
                        id: col0
                        width: 150; 
                        text: ""
                        property int index_: index
                        clip: true
                        
                        Connections {
                            target: mainWindow
                            onResize:{ if(c == index_) col0.width += w }
                        }

                       Rectangle{anchors.fill: parent; color: "lightblue"}
                    }
                }
            }
        }
    }
}