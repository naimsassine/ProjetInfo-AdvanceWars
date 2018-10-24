#include "Gameobject.h"
Gameobject::Gameobject(int initX, int initY, int initType)
{
 posX=initX;
 posY=initY;
 type=initType;

}
Gameobject::Gameobject()
{
}


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

void Gameobject::setPosX(int value)
{
    posX = value;
}
