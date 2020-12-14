#ifndef WELLSHAPE_H
#define WELLSHAPE_H

class QPainter;
class QRect;

class WellShape
{
public:
    WellShape();
    void DrawWells(QPainter *painter, const QRect &windowDimension);

};

#endif // WELLSHAPE_H
