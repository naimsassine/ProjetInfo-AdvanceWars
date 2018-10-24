#ifndef Gameobject_H
#define Gameobject_H
class Gameobject
{
public:
    Gameobject(int initX,int initY,int type) ;
    Gameobject() ;
    int getPosX() const;
    void setPosX(int value);
    int getPosY() const;
    void setPosY(int value);
    int getType() const;

private:
    float posX;
    float posY;
    int type;
};
#endif // Gameobject_H
