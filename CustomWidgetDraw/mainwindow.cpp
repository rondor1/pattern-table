#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->antialiasingCheckBox->toggled(false);

    ui->rowsSpinbox->setValue(ui->widget->GetRowsNum());
    ui->columnsSpinbox->setValue(ui->widget->GetColsNum());

    connect(ui->widget, &WellWidget::SetRowsNum, ui->rowsSpinbox, &QSpinBox::setValue);
    connect(ui->widget, &WellWidget::SetColsNum, ui->columnsSpinbox, &QSpinBox::setValue);

    ui->wellRadiusSpinBox->setValue(ui->widget->GetWellRadius());
    ui->wellSpacingSpinBox->setValue(ui->widget->GetWellSpacing());

    ui->formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rowsSpinbox_valueChanged(int arg1)
{
    ui->widget->SetRowsNum(arg1);
    ui->radiusSize->setText(QString::number(ui->widget->GetWellRadius()));
    ui->wellSpacing->setText(QString::number(ui->widget->GetWellSpacing()));
    ui->wellRadiusSpinBox->setValue(ui->widget->GetWellRadius());
    ui->wellSpacingSpinBox->setValue(ui->widget->GetWellSpacing());
    update();
}

void MainWindow::on_columnsSpinbox_valueChanged(int arg1)
{
    ui->widget->SetColsNum(arg1);
    ui->radiusSize->setText(QString::number(ui->widget->GetWellRadius()));
    ui->wellSpacing->setText(QString::number(ui->widget->GetWellSpacing()));
    ui->wellRadiusSpinBox->setValue(ui->widget->GetWellRadius());
    ui->wellSpacingSpinBox->setValue(ui->widget->GetWellSpacing());
    update();
}

void MainWindow::on_radiusSize_textEdited(const QString &arg1)
{

}

void MainWindow::on_wellRadiusSpinBox_valueChanged(int arg1)
{
    ui->widget->SetWellRadius(arg1);
    update();
}

void MainWindow::on_wellSpacingSpinBox_valueChanged(int arg1)
{
    ui->widget->SetWellSpacing(arg1);
    update();
}

void MainWindow::on_antialiasingCheckBox_stateChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Checked)
    {
        ui->widget->SetAntialiasing(true);
    }
    else if(arg1 == Qt::CheckState::Unchecked)
    {
        ui->widget->SetAntialiasing(false);
    }
    update();
}
