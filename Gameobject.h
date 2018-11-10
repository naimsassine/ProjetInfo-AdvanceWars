#ifndef Gameobject_H
#define Gameobject_H
#include <QString>

class Gameobject
{
public:

    int getPosX() const;
    void setPosX(int value);
    int getPosY() const;
    void setPosY(int value);
    int getType() const;
    void setType(int value);
    bool getSelected() const;
     void setSelected(bool value);
    // LOLOLOLOLOOLOLOLOLOLOL //
    QString getFilename() const;

    int getTeam() const;
    void setTeam(int value);

protected:
    int posX;
    int posY;
    int type;
    bool selected=false;
    QString filename;
    int team=0;

};
#endif // Gameobject_H
