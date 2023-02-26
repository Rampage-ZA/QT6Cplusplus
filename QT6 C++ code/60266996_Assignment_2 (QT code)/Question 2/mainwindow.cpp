#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QString>
#include <dialog.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_released()
{
    double w = ui->lineEdit->text().toDouble();
    double h = ui->lineEdit_2->text().toDouble();
    if (w>0 && h>0)
    {
        double BMI = (w/(h*h));
        ui->lcdNumber->display(BMI);
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Invalid numbers entered!");
        messageBox.setFixedSize(500,200);
    }

}


void MainWindow::on_pushButton_2_clicked()
{

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lcdNumber->display(0);
}

