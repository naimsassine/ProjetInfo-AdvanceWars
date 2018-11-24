#ifndef CASE_H
#define CASE_H


class Case
{
public:
    Case();
    int getPosX() const;
    void setPosX(int value);

    int getPosY() const;
    void setPosY(int value);

private :
    int posX=0;
    int posY=0;
};

#endif // CASE_H
