#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wellshape.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radiusSize->setText(QString::number(ui->widget->GetWellRadius()));
    ui->rowsSpinbox->setValue(ui->widget->GetRowsNum());
    ui->columnsSpinbox->setValue(ui->widget->GetColsNum());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rowsSpinbox_valueChanged(int arg1)
{
    ui->widget->SetRowsNum(arg1);
    update();
}

void MainWindow::on_columnsSpinbox_valueChanged(int arg1)
{
    ui->widget->SetColsNum(arg1);
}

void MainWindow::on_radiusSize_textEdited(const QString &arg1)
{

}
