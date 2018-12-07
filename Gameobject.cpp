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

void Gameobject::setMovable(bool value)
{
    movable = value;
}

int Gameobject::getPtdemouvement(int typeu) const
{
    return ldemouvement[typeu];
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


void Gameobject::setPosX(int value)
{
    posX = value;
}


