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

int Gameobject::getdefTerrain(int typet ,int typeu)
{   if(typet==34 ||typet==35 || typet==39 || typet==44 ||  typet==36 ||typeu==2000|| typeu ==2001 || typeu==2002 ||typeu==20003 ){
        defTerrain=1;

    }
    return defTerrain;
}

void Gameobject::setdefTerrain(int value)
{
    defTerrain = value;
}

bool Gameobject::getUnitin() const
{
    return unitin;
}

void Gameobject::setUnitin(bool value)
{
    unitin = value;
}


void Gameobject::setPosX(int value)
{
    posX = value;
}


