#include "Usine.h"
#include "Unites.h"

Usine::Usine(int X, int Y){
    posX = X;
    posY = Y;
    type = 0;

}

//Usine::Usine(int X, int Y, int t, int argent , int PC)
//{
    //posX = X;
    //posY= Y;
    //t = 3 ;
    //argent = 1000; //Argent qu'on fournit à chaque tour//
  //  PC = 20; //Points de capture//
//}


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
