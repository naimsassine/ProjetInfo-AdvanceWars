#include "Ville.h"


Ville::Ville(int X, int Y ,int Z,int T)
{
    posX = X;
    posY = Y;
    type = 0;
    capturepoint=Z;
    team=T;
    defTerrain = 3;
}

int Ville::getCapturepoint() const
{
    return capturepoint;
}


void Ville::setCapturepoint(int value)
{
    capturepoint = capturepoint-value;
    /*if capturepoint =0 setteam*/
    if(capturepoint<0){
        capturepoint=0;
    }

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

void Ville::initTeam()
{
    team=0;
}

void Ville::initCapturePoint()
{
    capturepoint=20;
}

bool Ville::getUnitin() const
{
    return unitin;
}

void Ville::setUnitin(bool value)
{
    unitin = value;
}
