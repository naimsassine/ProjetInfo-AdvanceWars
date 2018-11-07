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

int Gameobject::setType(int value)
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

void Gameobject::setPosX(int value)
{
    posX = value;
}
