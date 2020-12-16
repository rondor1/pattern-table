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
    void SetWellRadius(const int& wellRadius);
    int GetWellSpacing();
    void SetWellSpacing(const int& wellSpacing);
    void SetAntialiasing(const bool& state);

private:
    void CalculateRows();
    void CalculateColumns();
    void CalculateRadius();
    void CalculateOptimalWellPlate();
    void CalculateInitialWellPlateSize();
    void CalculateInitialRadiusSize();
protected:
    void paintEvent(QPaintEvent* painter);
    QSize minimumSizeHint() const;
private:
    WellShape* m_wellShape; //<! Pointer to a class handling drawing
    int m_rows = 1; //<! Number of drawn rows
    int m_columns = 1; //<! Number of drawn columns
    int m_wellSpacing; //<! Presents the distance between two elements
    int m_wellRadius; //<! Standard well radius
    bool m_aliasing = false; //<! Antialiasing flag
    int m_wellPlateWidth;//<! Width of the plate on which wells will be drawn
    int m_wellPlateHeight; //<! Height of the plate on which wells will be drawn
};

#endif // WELLWIDGET_H
