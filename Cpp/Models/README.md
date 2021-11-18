## 1. How it works

El modelo de datos TableModel pretende resolver la problematica de diseñar tablas personalizadas en QT/QML que representen los datos de una base de datos o culquier otro tipo de datos que requieran una tabla para ser representados. 

El objetivo es exponer al QML una interfaz común de celdas pero que cada celda pueda ser de un tipo distinto y por tanto tenga un tratamiento distinto. 

Para lograr este objetivo se ha diseñado una estructura basada en herencia abstracta de clases. La clase base CellModel expone todos los métodos (slots) que son accesibles desde QMl y permiten interactuar con las clases C++. Las clases derivadas como ForeignModel y TextModel son especializaciones de una celda que debe implementar todos los métodos virtuales puros expuestos por CellModel.

La clase CellModelFactory se encarga de crear los objetos derivados en según se requiera un tipo de celda.

TableModel contiene la lista de filas de tipo RowModel, RowModel tiene una lista de Celdas. Ambas clases heredan QAbstractTableModel o QAbstractItemModel para que el tipo TableView de QML pueda construir la tabla.

El código QML que permite instanciar y crear la tabla se muestra en el punto 2. Usage.


## 2. Usage
----
- Add folder Models into your code directory
- In main.cpp add header file
 	
        `#include "TableModel.h`

- In main.cpp add this line to do visible TableModel and CellModel from QML

```
qmlRegisterUncreatableType<TableModel>(<namespace>, 1, 0, "OperationsModel", "OperationsModel sholud not be created in QMl");

qmlRegisterUncreatableType<CellModel>(<namespace>, 1, 0, "CellModel", "Operation sholud not be created in QMl");

TableModel tableModel;

//Construir el modelo de datos. 
//Ejemplo: Crea un tabal de 10000 filas y 4 columnas (id, name, phone, mail)
for(int i = 0; i < 10000; i++)
{
    RowModel *rowModel = new RowModel();
    CellModelFactory *cell = new CellModelFactory("TEXT");
    cell->getInstance()->setTable("SW");
    cell->getInstance()->setColumn("id");
    cell->getInstance()->setCurrentValue("1");
    rowModel->add(0, "id", cell->getInstance());
    CellModelFactory *cell1 = new CellModelFactory("TEXT");
    cell1->getInstance()->setTable("SW");
    cell1->getInstance()->setColumn("name");
    cell1->getInstance()->setCurrentValue("Juan");
    rowModel->add(1, "name", cell1->getInstance());  
    CellModelFactory *cell2= new CellModelFactory("TEXT");
    cell2->getInstance()->setTable("SW");
    cell2->getInstance()->setColumn("phone");
    cell2->getInstance()->setCurrentValue("687598757");
    rowModel->add(2, "phone", cell2->getInstance());  
    CellModelFactory *cell3 = new CellModelFactory("TEXT");
    cell3->getInstance()->setTable("SW");
    cell3->getInstance()->setColumn("mail");
    cell3->getInstance()->setCurrentValue("g@gmail.com");
    rowModel->add(3, "mail", cell3->getInstance());  
    tableModel.add(rowModel);
}

<other code>

QQmlApplicationEngine engine;
engine.rootContext()->setContextProperty("tableModel", &tableModel);
const QUrl url(QStringLiteral("qrc:/main"));
engine.load(url);

```

- En el código QML

```

TableView {
    anchors.fill: parent
    anchors.top: mainWindow.top
    anchors.topMargin: 50

    anchors.left: mainWindow.left
    anchors.leftMargin: 50
    
    columnSpacing: 1
    rowSpacing: 1
    model: tableModel // Referencia setContextProperty de main.cpp
    interactive: true
    flickableDirection : Flickable.VerticalFlick
    delegate: Rectangle{
        implicitWidth: 200
        implicitHeight: 50
        Text{
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 10
            text: tableModel.getCell(index).currentValue()
            property int index_: index
            clip: true
        }

        MouseArea
        {
            id: cellMA
            anchors.fill: parent
            onClicked: {
                console.log(tableModel.getCell(index).display())
            }
        }
    }
}

```



