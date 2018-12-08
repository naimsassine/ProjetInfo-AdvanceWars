#include "Infanterie.h"
#include "game.h"
#include"Unites.h"


Infanterie::Infanterie(int InitX, int InitY, int InitTeam)
{
    posX=InitX;
    type=1998;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 3;
    prix = 1000;
    typeu= 0;
    posBin=0;


}


