#include "wellwidget.h"
#include "wellshape.h"

#include <QPainter>
#include <QDebug>

WellWidget::WellWidget(QWidget *parent) : QWidget(parent)
{
    m_wellShape = new WellShape();
}

WellWidget::~WellWidget()
{
    delete m_wellShape;
}

void WellWidget::CalculateColumns()
{
    m_columns = (this->size().width()-m_wellSpacing)/(m_wellSpacing+m_wellRadius);
}

void WellWidget::CalculateRows()
{
    m_rows = (this->size().height() - m_wellSpacing)/(m_wellSpacing+m_wellRadius);
}

void WellWidget::SetRowsNum(const int& rows)
{
    m_rows = rows;
}


void WellWidget::SetColsNum(const int &cols)
{
    m_columns = cols;
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


void WellWidget::paintEvent(QPaintEvent *event)
{
    static int numberOfPaints = 0;
    CalculateColumns();
    CalculateRows();
    qDebug() << " Columns: " << m_columns << Qt::endl;
    qDebug() << " Rows: " << m_rows << Qt::endl;

    qDebug() << " Number of paints : " << numberOfPaints++ << Qt::endl;

    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawRect(this->rect());

    painter.setBrush(Qt::white);
    for(int i = 0; i < m_rows; ++i)
    {
        for(int j = 0; j < m_columns; ++j)
        {
            m_wellShape->DrawWells(&painter,
                                   {m_wellSpacing+j*m_wellSpacing + j* m_wellRadius,
                                    m_wellSpacing + m_wellSpacing*i+m_wellRadius*i,
                                    m_wellRadius,
                                    m_wellRadius});
        }
    }
}
