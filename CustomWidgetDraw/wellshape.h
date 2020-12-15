#ifndef WELLSHAPE_H
#define WELLSHAPE_H

class QPainter;
class QRect;

class WellShape
{
public:
    WellShape();
    void DrawWellPlate(QPainter *painter, const QRect &windowDimension);
    void DrawWells(QPainter *painter, const QRect &windowDimension);

};

#endif // WELLSHAPE_H
