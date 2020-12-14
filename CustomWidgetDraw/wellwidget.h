#ifndef WELLWIDGET_H
#define WELLWIDGET_H

#include <QWidget>

class WellWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WellWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent* painter);
signals:

};

#endif // WELLWIDGET_H
