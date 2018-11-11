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

void Gameobject::setPosX(int value)
{
    posX = value;
}


