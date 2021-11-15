#include <QAbstractListModel>
#include <QList>
#include "RowModel.h"

class TableModel : public QAbstractListModel
{

    Q_OBJECT
    Q_PROPERTY(QList<RowModel*> rows READ rows WRITE setRows)

    public:

        TableModel(QObject *parent = 0){};
        //Expone el nombre de los atributos y los relaciona entre QML y C++
        QHash<int, QByteArray> roleNames() const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const;

        //Permite leer los atributos de la clase Operation en QML
        QVariant data(const QModelIndex &index, int role) const;
        void add(RowModel* row);
        QList<RowModel*> rows(void);
        void setRows(QList<RowModel*> rows);
        QList<RowModel *> getRows(void) const;

        // Esta función permite modificar los parametros de la clase Operation desde QML
        bool setData(const QModelIndex &index, const QVariant &value, int role);

    private:
        QList<RowModel*> rows_;
        QHash<int, QByteArray> roleNames_;


};