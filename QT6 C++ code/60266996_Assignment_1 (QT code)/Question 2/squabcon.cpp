#include <iostream>
#include <QTextStream>  //test1
#include "squabcon.h"


QTextStream cout(stdout); //2
QTextStream cin(stdin); //3


Position::Position(){};

Position::Position(int x, int y)
{
    Position::x=x;
    Position::y=y;
}

int Position::getX() const{
    return x;
}

int Position::getY() const{
    return y;
}

void Position::changePos(int x, int y){
    Position::x=x;
    Position::y=y;
}


Squab::Squab(int x, int y)
{
    score = 0;
    Position pos(x,y);
    pos.changePos(x,y);
 //   Squab::pos = positionObject;
 //   Position pos(x,y);

}

Squab::Squab(){
    score = 0;
}

Position Squab::getPos() const{
return pos;
}

int Squab::getScore() const{
    return score;
}

void Squab::incScore(){
    score = score +1;
}

Squab::~Squab(){};

void Squab::move(char dn, int de)
{
    if (dn == 'E') {pos.changePos(pos.getX()+de,pos.getY());}
    else if (dn == 'W') {pos.changePos(pos.getX()-de,pos.getY());}
    else if (dn == 'N') {pos.changePos(pos.getX(),pos.getY()+de);}
    else if (dn == 'S') {pos.changePos(pos.getX(),pos.getY()-de);}
    else {cout << "Invalid direction entered.";}
}


Squab * Squab::clone() const
{
/*    Squab newSquab = s;
    Squab* squabptr;
    squabptr = &newSquab;

    QMessageBox msgBox;
    msgBox.setText("Object created. Score: "+QVariant(newSquab.getScore()).toString());
    msgBox.exec();
    return squabptr; */
    Squab *squabptr = new Squab();
//    squabptr->getScore();

    squabptr->score = this->score;
    squabptr->pos = this->pos;

    return squabptr;

//    Squab* squabptr = &s;
//    return squabptr;
}


bool Squab::lineOfSight(Squab s) const
{
if (s.pos.getX() == this->pos.getX())
{
    cout<<"True!"; return true;
}
else if (s.pos.getY() == this->pos.getY())
{
    cout<<"True!"; return true;
}
else {cout<<"False!"; return false; }
}



/*


Squab::Squab(const Squab& s)
    {
        std::cout << "Copy constructor called " << std::endl;
    }

Squab::Squab& operator= (const Squab& s)
    {
        cout << "Assignment operator called " << endl;
        return *this;
    }

*/


// CLONE: https://stackoverflow.com/questions/19394426/c-returning-reference-to-new-object

/*
class Position
{
private:
    int x;
    int y;

public:
    Position(int x, int y);
    void changePos(int x, int y);
    int getX() const;
    int getY() const;
};


class Squab
{
private:
    int score;
    Position pos;

public:
    Squab(int x, int y);
    int getScore() const;
    void incScore();
    Position getPos() const;
    void move(char dn, int de);
    bool lineOfSight(Squab s) const;
    Squab * clone() const;
};
*/
