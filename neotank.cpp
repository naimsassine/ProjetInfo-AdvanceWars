#include "neotank.h"
#include "game.h"
#include "Unites.h"

Neotank::Neotank(int InitX,int InitY,int InitTeam)
{
    posX=InitX;
    type=3005;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 6;


}
