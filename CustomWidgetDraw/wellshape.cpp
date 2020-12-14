#include "wellshape.h"
#include <QPainter>
#include <QDebug>

WellShape::WellShape()
{

}

void WellShape::DrawWells(QPainter* painter, const QRect& windowDimension)
{
    painter->drawEllipse(windowDimension);
}


