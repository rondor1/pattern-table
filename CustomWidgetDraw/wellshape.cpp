#include "wellshape.h"
#include <QPainter>
#include <QDebug>

WellShape::WellShape()
{

}

void WellShape::DrawWellPlate(QPainter *painter, const QRect &windowDimension)
{
    painter->drawRect(windowDimension.x(), windowDimension.y(), windowDimension.width(), windowDimension.height());
}

void WellShape::DrawWells(QPainter* painter, const QRect& windowDimension)
{
    painter->drawEllipse(windowDimension);
}
