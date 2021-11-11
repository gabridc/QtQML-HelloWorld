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
        headerModel.append({"colName": "Nombre", "index": 0})
        headerModel.append({"colName": "Apellidos", "index":1})
        headerModel.append({"colName": "Mail", "index":2})

        dataModel.append({"dataTxt": "Gabriel", "index" : 0})
        dataModel.append({"dataTxt": "Domínguez", "index" : 1})
        dataModel.append({"dataTxt": "g@gmail.com", "index": 2})
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
            model: ListModel{id:headerModel}
            delegate: Text{
                id: col
                width: 150;
                height: 30
                text: colName
                property int index_: index 
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

    

    Row{
        id: data
        
        anchors.top: header.top
        anchors.topMargin: 50

        anchors.left: header.left
        anchors.leftMargin: 0
        
        anchors.right: header.right
        anchors.rightMargin: 0

         spacing: 10

         Repeater {
            model: ListModel{id: dataModel}
            delegate: Text{
                id: col0
                width: 150; 
                text: dataTxt
                property int index_: index
                
                Connections {
                    target: mainWindow
                    onResize:{ if(c == index_) col0.width += w }
                }
            }
         }

    }

}