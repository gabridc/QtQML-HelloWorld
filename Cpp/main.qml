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
       

        Text{
            id: nombre
            width: 150;
            text: "Nombre"

            ToolSeparator{ 
                anchors.right: parent.right
                anchors.rightMargin: 0
                orientation: Qt.Vertical


            }

            
            MouseArea{
            anchors.fill: nombre
            property int lastX: 0
            property int minimum: 0
            onPositionChanged: {
                if(minimum != 0) //Forzar que primero se tenga que hacer click
                {
                    if(mouse.x  > minimum )
                    {
                        console.log(mouse.x - lastX)
                        nombre.width += mouse.x - lastX
                        mainWindow.resize(mouse.x - lastX, 0 )
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
        Text{
            id:apellidos
            width: 150;
            text: "Apellidos"

            MouseArea{
            anchors.fill: apellidos
            property int lastX: 0
             property int minimum: 0
               onPositionChanged: {
                if(mouse.x  >minimum )
                {
                    apellidos.width += mouse.x - lastX
                    mainWindow.resize(mouse.x - lastX, 0 )
                }
                lastX = mouse.x
            }
            onClicked: {
                if(minimum == 0)
                {
                    minimum = mouse.x
                }
                lastX = mouse.x
            
            }
            }
        }
        Text{
            id: mail
            width: 150;
            
            text: "Mail"


            MouseArea{
                anchors.fill: mail
                property int lastX: 0
                 property int minimum: 0
                onPositionChanged: {
                    mail.width += mouse.x - lastX
                    mainWindow.resize(mouse.x - lastX, 2)
                    lastX = mouse.x
                }
                onClicked: console.log("Clicked")
            }
        }


    }

    

    Row{
        id: data
        
        anchors.top: header.top
        anchors.topMargin: 20

        anchors.left: header.left
        anchors.leftMargin: 0
        
        anchors.right: header.right
        anchors.rightMargin: 0

         spacing: 10

        Text{
            id: col0
            width: 150; 
            text: "Luis"
            property int col: 0
            
            Connections {
                target: mainWindow
                onResize: if(c == col0.col) col0.width += w
            }
        }
        Text{
            id:col1
            width: 150; text: "García"
            property int col: 1
            Connections {
                target: mainWindow
                onResize: if(c == col1.col) col1.width += w
            }
        }
        Text{
            id:col2
            property int col: 2
            width: 150; text: "l@gmail.com"
            Connections {
                target: mainWindow
                onResize: if(c == col2.col) col2.width += w
            }
        }
    }

}