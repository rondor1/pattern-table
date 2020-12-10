#include "customshape.h"

CustomShape::CustomShape()
{

}

void CustomShape::paint(QPainter *painter, const QRect &rect, const QPalette &palette) const
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    rect.getCoords(&x1,&y1, &x2, &y2);
    QRect size{x1,y1,29,29};
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);

    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);

    painter->drawEllipse(size);

    painter->restore();
}

QSize CustomShape::sizeHint() const
{
    return {5,5};
}
