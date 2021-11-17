#include <QAbstractTableModel>
#include <QList>
#include <QObject>
#include "RowModel.h"

class TableModel : public QAbstractTableModel
{

    Q_OBJECT
    Q_PROPERTY(QList<RowModel*> rows READ rows WRITE setRows NOTIFY rowsChanged)

public:
    TableModel(QObject *parent = 0){};

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //Permite leer los atributos de la clase Operation en QML
    QVariant data(const QModelIndex &index, int role) const;
    void add(RowModel* row);
    QList<RowModel*> rows(void);
    void setRows(QList<RowModel*> rows);
    QList<RowModel *> getRows(void) const;

    // Esta función permite modificar los parametros de la clase Operation desde QML
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    
    //Expone el nombre de los atributos y los relaciona entre QML y C++
    QHash<int, QByteArray> roleNames() const
    {
        return { {Qt::DisplayRole, "display"} };
    }

signals:
    void rowsChanged(bool foo);

private:
        QList<RowModel*> rows_;
        QList<QString> columns_;
        QHash<int, QByteArray> roleNames_;


};