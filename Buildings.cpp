#include "Buildings.h"
#include "game.h"

Buildings::Buildings(){

}
Buildings::Buildings(int X, int Y)
{
    unite=-1;
    posX = X;
    posY = Y;
    type = 0;
}

int Buildings::getUnite() const
{
    return unite;
}

void Buildings::setUnite(int value)
{
    unite = value;
}

bool Buildings::getUnitin() const
{
    return unitin;
}

void Buildings::setUnitin(bool value)
{
    Game& game = Game::Instance();
    std::vector<Unites> unites =game.getUnites();
    unitin = value;
    if(value==true){
        unitin=true;

    }
    else if(unite> 0&& capturepoint!=0 ){

        if(unites[unite].getPosX()!=posX || unites[unite].getPosY()!=posY){

        Game& game = Game::Instance();
        capturepoint=20;
        game.setActville(-1);
        game.getWindow()->redraw();
        unitin=false;}


    }
    else{
        unitin=true;
    }

}

int Buildings::getCapturepoint() const
{
    return capturepoint;
}

void Buildings::setCapturepoint(int value)
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
