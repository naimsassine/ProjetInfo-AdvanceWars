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
    bool getSelected() const;
    void setSelected(bool value);

private:
    float posX;
    float posY;
    int type;
    bool selected;
};
#endif // Gameobject_H
