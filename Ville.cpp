#include "Ville.h"
#include "game.h"

Ville::Ville(int X, int Y ,int Z,int T)
{
    posX = X;
    posY = Y;
    type = 0;
    capturepoint=Z;
    team=T;
    defTerrain = 3;
    unite=nullptr;
}

int Ville::getCapturepoint() const
{
    return capturepoint;
}


void Ville::setCapturepoint(int value)
{
    capturepoint = capturepoint-value;
    /*if capturepoint =0 setteam*/
    if(capturepoint<0){
        capturepoint=0;
    }

}

void Ville::repair(Unites c)
{

}

int Ville::getTeam() const
{
    return team;
}

void Ville::setTeam(int value)
{
    team = value;
}

void Ville::initTeam()
{
    team=0;
}

void Ville::initCapturePoint()
{
    capturepoint=20;
}

bool Ville::getUnitin() const
{
    return unitin;
}

void Ville::setUnitin(bool value)
{
    if(unite!=nullptr&& capturepoint!=0 && (unite->getPosX()!=posX || unite->getPosY()!=posY)){
        Game& game = Game::Instance();
        capturepoint=20;
        game.setActville(nullptr);
        game.getWindow()->redraw();

    }
    unitin = value;
}

Unites *Ville::getUnite() const
{
    return unite;
}

void Ville::setUnite(Unites *value)
{
    unite = value;
}
