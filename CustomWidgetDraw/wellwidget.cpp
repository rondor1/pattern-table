#include "wellwidget.h"
#include <QPainter>

WellWidget::WellWidget(QWidget *parent) : QWidget(parent)
{

}

void WellWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawEllipse(10,10,25,25);
}

