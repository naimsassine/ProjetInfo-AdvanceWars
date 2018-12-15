#include "Ville.h"
#include "game.h"

Ville::Ville(int X, int Y ,int Z,int T)
{
    posX = X;
    posY = Y;
    type = 0;
    capturepoint=Z;
    team=T;
    posdef=8;
    unite=-1;

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
    if(value==20){
       capturepoint=20;
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
    Game& game = Game::Instance();
    std::vector<Unites> unites =game.getUnites();
    unitin = value;
    if(value==true){
        unitin=true;

    }
    else if(unite !=-1&& capturepoint!=0 && (unites[unite].getPosX()!=posX || unites[unite].getPosY()!=posY)){

       std::cout<<posX<<"  "<<posY<<std::endl;

        Game& game = Game::Instance();
        capturepoint=20;
        game.setActville(-1);
        game.getWindow()->redraw();
        unitin=false;


    }
    else{
        unitin=true;
    }

}

int Ville::getUnite() const
{
    return unite;
}

void Ville::setUnite(int value)
{
    unite = value;


}
