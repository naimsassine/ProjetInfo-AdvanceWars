#include "Ville.h"


Ville::Ville(int X, int Y)
{
    posX = X;
    posY = Y;
    type = 0;
}

int Ville::getCapturepoint() const
{
    return capturepoint;
}

void Ville::setCapturepoint(int value)
{
    capturepoint = value;/*if capturepoint =0 setteam*/

}

void Ville::repair(Unites c)
{

}

int Ville::getTeam() const
{
    return team;
}

void Ville::setTeam(int value)
{
    team = value;
}
