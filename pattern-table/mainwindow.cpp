#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "customtable.h"
#include "customshapedelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new CustomTable();

    table->setRowValue(6);
    table->setColumnValue(6);
    table->populateTable(6,6);
    ui->tableView->setModel(table);
    //Add delegate here
    ui->tableView->setItemDelegate(new CustomShapeDelegate(this));
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->rowsSpinBox->setValue(table->rowCount());
    ui->columnsSpinBox->setValue(table->columnCount());
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTable()
{
    ui->tableView->setModel(nullptr);
    ui->tableView->setModel(table);
    ui->tableView->show();
}


void MainWindow::on_rowsSpinBox_valueChanged(int arg1)
{
    table->setRowValue(arg1);
    UpdateTable();
}

void MainWindow::on_columnsSpinBox_valueChanged(int arg1)
{
    table->setColumnValue(arg1);
    UpdateTable();
}
