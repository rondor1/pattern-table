#include "customshapedelegate.h"
#include "customshape.h"

CustomShapeDelegate::CustomShapeDelegate(QObject* parent)
{

}

void CustomShapeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    CustomShape customShape = qvariant_cast<CustomShape>(index.data());

    //Draw custom shape, in this case circle
    customShape.paint(painter, option.rect, option.palette);

}

QSize CustomShapeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    CustomShape customShape = qvariant_cast<CustomShape>(index.data());
    return customShape.sizeHint();
}

QWidget *CustomShapeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void CustomShapeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
        QStyledItemDelegate::setEditorData(editor, index);
}

void CustomShapeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
        QStyledItemDelegate::setModelData(editor, model, index);
}
