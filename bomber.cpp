#include "game.h"
#include"Unites.h"
#include "bomber.h"
#include "Aerienne.h"
Bomber::Bomber(int InitX, int InitY, int InitTeam)
{
    posX=InitX;
    type=2001;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 7;
    typeu=4;

}
