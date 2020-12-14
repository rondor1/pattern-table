#ifndef WELLWIDGET_H
#define WELLWIDGET_H

#include <QWidget>
class WellShape;

class WellWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WellWidget(QWidget *parent = nullptr);
    ~WellWidget();
    void SetRowsNum(const int& rows);
    void SetColsNum(const int& cols);
    int GetRowsNum() const;
    int GetColsNum() const;
    int GetWellRadius() const;

private:
    void CalculateRows();
    void CalculateColumns();
    void CalculateRadius();
protected:
    void paintEvent(QPaintEvent* painter);

public:
    signals:
        void radiusChange(const QString &arg1);
private:
    WellShape* m_wellShape; //<! Pointer to a class handling drawing
    int m_rows = 5; //<! Number of drawn rows
    int m_columns = 5; //<! Number of drawn columns
    int m_wellSpacing = 15; //<! Presents the distance between two elements
    int m_wellRadius = 30; //<! Standard well radius
};

#endif // WELLWIDGET_H
