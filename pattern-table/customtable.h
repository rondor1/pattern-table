#ifndef CUSTOMTABLE_H
#define CUSTOMTABLE_H

#include <QAbstractTableModel>

class CustomTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomTable(QObject* parent = nullptr);
    void populateTable(const int &rows, const int &columns);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void setRowValue(int rows);
    void setColumnValue(int columns);
private:
    int m_rows;
    int m_columns;
    QMap<int, QVector<int>> m_data;
};

#endif // CUSTOMTABLE_H

