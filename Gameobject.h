#ifndef Gameobject_H
#define Gameobject_H
#include <QString>
class Gameobject
{
public:
    Gameobject(int initX,int initY, int Inittype = 0) ;
    Gameobject() ;
    int getPosX() const;
    void setPosX(int value);
    int getPosY() const;
    void setPosY(int value);
    int getType() const;
    bool getSelected() const;
    void setSelected(bool value);
    // LOLOLOLOLOOLOLOLOLOLOL //
    QString getFilename() const;

protected:
    float posX;
    float posY;
    int type;
    bool selected;
    QString filename;
};
#endif // Gameobject_H
