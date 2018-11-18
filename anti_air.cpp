#include "anti_air.h"
#include "Unites.h"
#include "game.h"

Anti_Air::Anti_Air(int InitX, int InitY, int InitTeam)
{
    posX=InitX;
    type=3001;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 6;
}
