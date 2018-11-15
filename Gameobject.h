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
    QString getFilename() const;
    void setAutorisation(int value);
    int getAutorisation();

    int getTeam() const;
    void setTeam(int value);

    bool getMovable() const;
    void setMovable(bool value);

    int getPtdemouvement() const;
    void setPtdemouvement(int value);

protected:
    int posX;
    int posY;
    int type;
    bool selected=false;
    QString filename;
    int team=0;
    int autorisation;
    bool movable=false;
    int ptdemouvement=1;

};
#endif // Gameobject_H
