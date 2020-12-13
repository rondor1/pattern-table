#include "customshapedelegate.h"
#include "customshape.h"

CustomShapeDelegate::CustomShapeDelegate(QObject* parent)
{

}

void CustomShapeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    option.rect.getCoords(&x1,&y1, &x2, &y2);
    QRect size{(option.rect.width() - option.rect.height())/2 +x1 ,y1,option.rect.height(),option.rect.height()};
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);

    painter->drawEllipse(size);
    painter->drawText(QPoint((option.rect.width())/2 +x1, (y1+y2)/2), index.data().toString());

    painter->restore();

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
