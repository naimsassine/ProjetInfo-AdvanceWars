#include "Usine.h"
#include "Unites.h"

Usine::Usine(int X, int Y){
    posX = X;
    posY = Y;
    type = 0;
    posdef=9;

}

Usine::Usine(int X, int Y, int t, int argent , int PC)
{
    posX = X;
    posY= Y;
    t = 3 ;
    argent = 1000; //Argent qu'on fournit à chaque tour//
    PC = 20; //Points de capture//
    posdef=9;
}



void Usine::repair(Unites c)
{

}

void Usine::createTeam(Unites c)
{


}
int Usine::getTeam() const
{
    return team;
}

void Usine::setTeam(int value)
{
    team = value;
}

bool Usine::getUnitin() const
{
    return unitin;
}

void Usine::setUnitin(bool value)
{
    unitin = value;
}

int Usine::getCapturepoint() const
{
    return capturepoint;
}
void Usine::initCapturePoint()
{
    capturepoint=20;
}


void Usine::setCapturepoint(int value)
{
    capturepoint = capturepoint-value;
    /*if capturepoint =0 setteam*/
    if(capturepoint<0){
        capturepoint=0;
    }

}
