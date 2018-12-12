#include "recon.h"
#include "game.h"
#include "Unites.h"

Recon::Recon(int InitX, int InitY, int InitTeam)
{
    posX=InitX;
    type=3000;
    posY=InitY;
    Team = InitTeam;
    vie=10;
    ptdeplacement = 8;
    typeu=3;
    posBin=2;
    prix=15000;
}
