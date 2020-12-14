#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class WellWidget;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rowsSpinbox_valueChanged(int arg1);

    void on_columnsSpinbox_valueChanged(int arg1);

    void on_radiusSize_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
