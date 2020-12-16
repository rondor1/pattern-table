#include "wellwidget.h"
#include "wellshape.h"

#include <QPainter>
#include <QDebug>

WellWidget::WellWidget(QWidget *parent) : QWidget(parent)
{
    m_wellShape = new WellShape();

    m_wellSpacing = 25;
    m_wellRadius = 50;
    m_wellPlateHeight = 0;
    m_wellPlateWidth = 0;
    CalculateInitialWellPlateSize();
}

WellWidget::~WellWidget()
{
    delete m_wellShape;
}

void WellWidget::CalculateColumns()
{
    m_columns = (m_wellPlateWidth-m_wellSpacing)/(m_wellSpacing+m_wellRadius);
}

void WellWidget::CalculateRadius()
{
    auto radius1 = 2*m_wellPlateWidth / (3*m_columns + 1);
    auto radius2 = 2*m_wellPlateHeight / (3*m_rows + 1);
    m_wellRadius = radius1 < radius2 ? radius1 : radius2;
    m_wellSpacing= m_wellRadius/2;
}

void WellWidget::CalculateInitialWellPlateSize()
{
    m_wellPlateWidth = this->rect().width() - 2 * m_wellSpacing;
    m_wellPlateHeight =  this->rect().height() - 2 * m_wellSpacing;
}

void WellWidget::CalculateOptimalWellPlate()
{
    qDebug() << "Well radius: " << m_wellRadius;
    m_wellPlateWidth = (m_columns+1)*m_wellSpacing + m_columns*m_wellRadius;
    m_wellPlateHeight = (m_rows+1)*m_wellSpacing + m_rows*m_wellRadius;
}

void WellWidget::CalculateRows()
{
    m_rows = (m_wellPlateHeight - m_wellSpacing)/(m_wellSpacing+m_wellRadius);
}

void WellWidget::SetRowsNum(const int& rows)
{
    m_rows = rows;
    CalculateRadius();
}


void WellWidget::SetColsNum(const int &cols)
{
    m_columns = cols;
    CalculateRadius();
}

int WellWidget::GetRowsNum() const
{
    return m_rows;
}

int WellWidget::GetColsNum() const
{
    return m_columns;
}

int WellWidget::GetWellRadius() const
{
    return m_wellRadius;
}

void WellWidget::SetWellRadius(const int &wellRadius)
{
    m_wellRadius = wellRadius;
    m_wellSpacing = wellRadius/2;
}

int WellWidget::GetWellSpacing()
{
    return m_wellSpacing;
}

void WellWidget::SetWellSpacing(const int &wellSpacing)
{
    m_wellSpacing = wellSpacing;
    m_wellRadius = 2*wellSpacing;
}

void WellWidget::SetAntialiasing(const bool &state)
{
    m_aliasing = state;
}

void WellWidget::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setBrush(QColor(0,0,255, 127));

    painter.drawRect(this->rect());

    CalculateOptimalWellPlate();
    CalculateRadius();

    QPoint startingPointWidget{this->rect().topLeft().x(), this->rect().topLeft().y()};

    QPoint plateDimensions{m_wellPlateWidth, m_wellPlateHeight};

    QPoint plateStartingPoint{startingPointWidget.x() + m_wellSpacing,
                m_wellSpacing + startingPointWidget.y()};

    qDebug() << plateStartingPoint.x();
    qDebug() << plateStartingPoint.y();


    if(m_aliasing)
    {
        painter.setRenderHint(QPainter::Antialiasing);
    }

    m_wellShape->DrawWellPlate(&painter, {plateStartingPoint.x(),
                                          plateStartingPoint.y(),
                                          m_wellPlateWidth,
                                          m_wellPlateHeight});

    painter.setBrush(Qt::white);

    for(auto i = 0; i < m_rows; ++i)
    {
        for(auto j = 0; j < m_columns; ++j)
        {
            m_wellShape->DrawWells(&painter,
                                   {(m_wellSpacing + plateStartingPoint.x())+j*m_wellSpacing + j* m_wellRadius,
                                    (m_wellSpacing + plateStartingPoint.y()) + m_wellSpacing*i+m_wellRadius*i,
                                    m_wellRadius,
                                    m_wellRadius});
        }
    }
}

QSize WellWidget::minimumSizeHint() const
{
    return QSize(500,500);
}
