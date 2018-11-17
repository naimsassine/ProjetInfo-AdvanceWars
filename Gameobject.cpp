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
    selected = value;
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

int Gameobject::getPtdemouvement() const
{
    return ptdemouvement;
}

void Gameobject::setPtdemouvement(int value)
{
    ptdemouvement = value;
}

int Gameobject::getdefTerrain() const
{
    return defTerrain;
}

void Gameobject::setdefTerrain(int value)
{
    defTerrain = value;
}

void Gameobject::setPosX(int value)
{
    posX = value;
}


