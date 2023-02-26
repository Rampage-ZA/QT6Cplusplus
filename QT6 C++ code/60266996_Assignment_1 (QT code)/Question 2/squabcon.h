#ifndef SQUABCON_H
#define SQUABCON_H

class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y);
    Position();
    void changePos(int x, int y);
    int getX() const;
    int getY() const;
};

class Squab {
private:
    int score;
    Position pos;

public:
    Squab(int x, int y);
    Squab();
    int getScore() const;
    void incScore();
    Position getPos() const;
    void move(char dn, int de);
    bool lineOfSight(Squab s) const;
    Squab * clone() const;
//    Squab(const Squab& s);
//    Squab& operator=(const Squab& s);

    ~Squab();
};


#endif // SQUABCON_H
