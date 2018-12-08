#include "mega_tank.h"
#include "game.h"
#include "Unites.h"

mega_tank::mega_tank(int InitX,int InitY,int InitTeam)
{
    posX = InitX;
    type = 3004;
    posY = InitY;
    Team = InitTeam;
    vie = 10;
    ptdeplacement = 4;
    typeu=2;
    posBin=6;
}
