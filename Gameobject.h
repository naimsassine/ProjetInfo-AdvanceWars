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
    void setPos(int x, int y);
    bool isAtPos(int x, int y) const;

    int getType() const;
    void setType(int value);

    bool getSelected() const;
    bool isSelected() const { return getSelected(); }
    void setSelected(bool value);

    QString getFilename() const;
    void setAutorisation(int value);
    int getAutorisation();

    int getTeam() const;
    void setTeam(int value);

    bool getMovable() const;
    bool isMovable() const { return getMovable(); }
    void setMovable(bool value );

    int getPtdemouvement(int typeu) const;
    int getPTMvt() const;
    void setPtdemouvement(int value);

    int getdefTerrain(int typeu) ;

    bool getUnitin() const;
    void setUnitin(bool value);

    int getPosdef() const;

    bool getValue2() const;
    void setValue2(bool value);

    int getPoids() const;
    void setPoids(int value);

    bool getDejaparc() const;
    void setDejaparc(bool value);

    int getAntecedantX() const;
    void setAntecedantX(int value);

    int getAntecedantY() const;
    void setAntecedantY(int value);

protected:
    int posX;
    int posY;
    int type;
    bool value2=false;
    bool selected=false;
    bool unitin=false;
    QString filename;
    int team=0;
    int autorisation;
    int posdef=11;
    bool movable=false;
    int ptdemouvement=1;
    int ldemouvement[5]={1,1,1,1,1};
    int defTerrain[12]={1,4,2,0,0,0,0,1,3,3,3,0};
    int poids = -1;
    bool dejaparc = false;
    int antecedantX;
    int antecedantY;


};
#endif // Gameobject_H
