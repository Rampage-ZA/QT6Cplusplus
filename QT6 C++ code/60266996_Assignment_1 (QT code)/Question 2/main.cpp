#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include "squabcon.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    std::cout << "Hello there" << std::endl;
    qDebug() <<"Creating and initializing two squab objects (1,1) and (1,2) and one position (0,0) object to test classes... \n";

    Position positionObject(0,0);
    Squab squab(1,1);
    Squab squab2 (1,2);

    qDebug() << "Changing position to (5,5) to test member function... \n";

    positionObject.changePos(5,5);
    qDebug() <<"Testing position change. New position X value: " << positionObject.getX() << "\n";
    qDebug() <<"Testing position change. New position Y value: " << positionObject.getY() << "\n";

    squab.incScore();

    qDebug() << "Incrementing score of first squab object by 1. New score: " << squab.getScore() << "\n";

    qDebug() << "Printing Position of Squab. X: " << squab.getPos().getX();
    qDebug() << "Y: " << squab.getPos().getX() << "\n";
    squab.move('E', 12);

    qDebug() << "Printing Position of Squab after incrementing East by 12 units. X: " << squab.getPos().getX();
    qDebug() << "Y: " << squab.getPos().getY() << "\n";

    qDebug() << "Cloning Squab. Memory location: "  << squab.clone() << "\n";
    qDebug() << "Cloning Squab. Memory location: "  << squab.clone() << "\n";

    Squab* squab3 = squab.clone();

    qDebug() << "Score of pointer to squab: " << squab3->getScore() << "\n";

    squab.lineOfSight(squab2);
    qDebug() << "Checking if squab object 1 and 2 are in LOS of each other (bool):" << squab2.getScore() << "\n";

    return a.exec();
}
