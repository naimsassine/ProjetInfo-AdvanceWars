#include "tank.h"
#include "Unites.h"
#include "game.h"

Tank::Tank(int InitX,int InitY,int InitTeam)
{
    posX=InitX;
    type=3002;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 6;
}
