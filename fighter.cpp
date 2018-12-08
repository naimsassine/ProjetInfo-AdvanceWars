#include "fighter.h"
#include"Aerienne.h"
#include"Unites.h"

Fighter::Fighter(int InitX, int InitY, int InitTeam)
{
    posX=InitX;
    type=2002;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 9;
    typeu=4;
    posBin=9;
}
