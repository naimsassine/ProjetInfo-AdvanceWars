#include "Aeroport.h"
#include"Buildings.h"
#include"game.h"
#include "Aerienne.h"
#include "Unites.h"

Aeroport::Aeroport(int X, int Y)
{
    posX = X;
    posY = Y;
    type = 0;
    posdef=10;

}
Aeroport::Aeroport(int X, int Y, int t, int argent , int PC)
{
    posX = X;
    posY= Y;
    t = 3 ;
    argent = 1000; //Argent qu'on fournit à chaque tour//
    PC = 20; //Points de capture//
}



void Aeroport::repair(Unites c)
{

}

void Aeroport::createTeam(Unites c)
{


}
int Aeroport::getTeam() const
{
    return team;
}

void Aeroport::setTeam(int value)
{
    team = value;
}


void Aeroport::initTeam()
{
    team=0;
}

void Aeroport::initCapturePoint()
{
    capturepoint=20;
}

bool Aeroport::getUnitin() const
{
    return unitin;
}

void Aeroport::setUnitin(bool value)
{
    unitin = value;
}

bool Aeroport::getComptproduction() const
{
    return comptproduction;
}

void Aeroport::setComptproduction(bool value)
{
    comptproduction = value;
}

int Aeroport::getCapturepoint() const
{
    return capturepoint;
}

void Aeroport::setCapturepoint(int value)
{
    capturepoint = capturepoint-value;
    /*if capturepoint =0 setteam*/
    if(capturepoint<0){
        capturepoint=0;
    }
    if(value==20){
       capturepoint=20;
    }

}











