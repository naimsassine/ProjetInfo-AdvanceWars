#include "md_tank.h"
#include "game.h"
#include "Unites.h"

MD_tank::MD_tank(int InitX,int InitY,int InitTeam)
{
    posX=InitX;
    type=3003;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 5;
    typeu=2;
    posBin=5;
    prix=16000;
}
