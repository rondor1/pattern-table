#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class CustomTable;
class CustomShapeDelegate;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void UpdateTable();

private slots:
    void on_rowsSpinBox_valueChanged(int arg1);
    void on_columnsSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    CustomTable* table;
    CustomShapeDelegate* delegate;
};
#endif // MAINWINDOW_H
