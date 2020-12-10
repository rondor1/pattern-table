#ifndef CUSTOMSHAPE_H
#define CUSTOMSHAPE_H

#include<QPainter>
#include<QRect>
#include<QPalette>

class CustomShape
{
public:
    explicit CustomShape();

    void paint(QPainter *painter, const QRect& rect,
               const QPalette &palette) const;
    QSize sizeHint() const;
};

Q_DECLARE_METATYPE(CustomShape)

#endif // CUSTOMSHAPE_H
