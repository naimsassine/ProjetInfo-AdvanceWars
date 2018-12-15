#include "Ville.h"
#include "buildings.h"
#include "game.h"

Ville::Ville(int X, int Y ,int Z,int T)
{
    posX = X;
    posY = Y;
    type = 0;
    capturepoint=Z;
    team=T;
    posdef=8;


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




