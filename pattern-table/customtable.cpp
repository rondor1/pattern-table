#include "customtable.h"

#include <QDebug>

CustomTable::CustomTable(QObject *parent)
{

}

void CustomTable::populateTable(const int& rows, const int& columns)
{
    shapes.clear();
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            m_data[i].push_back(0);
        }
    }
    return;
}

int CustomTable::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_rows;
}

int CustomTable::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_columns;
}

QVariant CustomTable::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole || !index.isValid())
    {
        return QVariant();
    }
    else
    {
        if((index.column() >= 0 && index.column() < m_columns) &&
           (index.row() >= 0 && index.row() < m_rows))
        {
            return m_data[index.row()][index.column()];
        }
        else
        {
            return QVariant();
        }
    }
}

void CustomTable::setRowValue(int rows)
{
    qDebug() << "Rows val: " << rows <<Qt::endl;
    m_rows = rows;
    populateTable(m_rows, m_columns);
}

void CustomTable::setColumnValue(int columns)
{
    qDebug() << "Columns val: " << columns <<Qt::endl;
    m_columns = columns;
    populateTable(m_rows, m_columns);
}
