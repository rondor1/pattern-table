#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "customtable.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new CustomTable();
    QList<int> test = {0,0,0,0,0,0,0,0,0,0,0,0,0};

    table->populateTable(test);
    ui->tableView->setModel(table);
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rowsSpinBox_valueChanged(int arg1)
{
    table->setRowValue(arg1);
}

void MainWindow::on_columnsSpinBox_valueChanged(int arg1)
{
    table->setColumnValue(arg1);
}
