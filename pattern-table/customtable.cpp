#include "customtable.h"

#include <QDebug>

CustomTable::CustomTable(QObject *parent)
{

}

void CustomTable::populateTable(const QList<int> &elems)
{
    m_data.clear();
    m_data = elems;
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
    return QVariant();
}

void CustomTable::setRowValue(int rows)
{
    qDebug() << "Rows val: " << rows <<Qt::endl;
    m_rows = rows;
}

void CustomTable::setColumnValue(int columns)
{
    qDebug() << "Columns val: " << columns <<Qt::endl;
    m_columns = columns;
}
