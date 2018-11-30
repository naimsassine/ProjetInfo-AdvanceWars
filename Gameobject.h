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

    int getdefTerrain(int typet ,int typeu) ;
    void setdefTerrain(int value);

    bool getUnitin() const;
    void setUnitin(bool value);

protected:
    int posX;
    int posY;
    int type;
    bool selected=false;
    bool unitin=false;
    QString filename;
    int team=0;
    int autorisation;
    bool movable=false;
    int ptdemouvement=1;
    int defTerrain;

};
#endif // Gameobject_H
