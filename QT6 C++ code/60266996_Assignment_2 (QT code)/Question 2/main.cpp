#include "mainwindow.h"
#include <QInputDialog>
#include <QApplication>
#include <QPushButton>
#include <QtWidgets>
#include <QtCore>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();


    return a.exec();
}
