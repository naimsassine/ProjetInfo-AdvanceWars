#include "Gameobject.h"
Gameobject::Gameobject(int initX, int initY, int Inittype)
{
 posX=initX;
 posY=initY;
 selected = false;
 type = Inittype;

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

bool Gameobject::getSelected() const
{
    return selected;
}

void Gameobject::setSelected(bool value)
{
    selected = value;
}

void Gameobject::setPosX(int value)
{
    posX = value;
}
