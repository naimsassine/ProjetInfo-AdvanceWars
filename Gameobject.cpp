#include "Gameobject.h"





int Gameobject::getPosX() const
{
    return posX;
}

int Gameobject::getPosY() const
{
    return posY;
}

void Gameobject::setPosY(int value)
{
    posY = value;
}

void Gameobject::setPos(int x, int y) {
    setPosX(x);
    setPosY(y);
}

bool Gameobject::isAtPos(int x, int y) const {
    return getPosX() == x && getPosY() == y;
}

int Gameobject::getType() const
{
    return type;
}

void Gameobject::setType(int value)
{
    type = value;
}

bool Gameobject::getSelected() const
{ 
    return selected;
}

void Gameobject::setSelected(bool value)
{
    selected = value; // apparemmebt une segfault ici
}

QString Gameobject::getFilename() const
{
    return filename;
}

void Gameobject::setAutorisation(int value)
{
    autorisation = value;
}

int Gameobject::getAutorisation()
{
    return autorisation;
}

int Gameobject::getTeam() const
{
    return team;
}

void Gameobject::setTeam(int value)
{
    team = value;
}

bool Gameobject::getMovable() const
{
    return movable;
}

void Gameobject::setMovable(bool value )
{  if (value==true){
      value2=true;
    }
    movable = value && value2;
}

int Gameobject::getPtdemouvement(int typeu) const
{
    return ldemouvement[typeu];
}
int Gameobject::getPTMvt() const{
    return ptdemouvement;
}

void Gameobject::setPtdemouvement(int value)
{
    ptdemouvement = value;
}

int Gameobject::getdefTerrain(int typet)
{
    return defTerrain[typet];
}



bool Gameobject::getUnitin() const
{
    return unitin;
}

void Gameobject::setUnitin(bool value)
{
    unitin = value;
}

int Gameobject::getPosdef() const
{
    return posdef;
}

bool Gameobject::getValue2() const
{
    return value2;
}

void Gameobject::setValue2(bool value)
{
    value2 = value;
}

int Gameobject::getPoids() const
{
    return poids;
}

void Gameobject::setPoids(int value)
{
    poids = value;
}

bool Gameobject::getDejaparc() const
{
    return dejaparc;
}

void Gameobject::setDejaparc(bool value)
{
    dejaparc = value;
}

int Gameobject::getAntecedantX() const
{
    return antecedantX;
}

void Gameobject::setAntecedantX(int value)
{
    antecedantX = value;
}

int Gameobject::getAntecedantY() const
{
    return antecedantY;
}

void Gameobject::setAntecedantY(int value)
{
    antecedantY = value;
}

int Gameobject::getDistance() const
{
    return distance;
}

void Gameobject::setDistance(int value)
{
    distance = value;
}

/*void Gameobject::pathfinding(int x, int y)
{
    this->setDejaparc(true);
    int posX = this->getPosX();
    int posY = this->getPosY();
    if (Gameobject[posX+1][posY+1].get)

}*/


void Gameobject::setPosX(int value)
{
    posX = value;
}


