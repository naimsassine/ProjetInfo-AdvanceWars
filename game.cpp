#include "game.h"
#include <iostream>
#include <math.h>
#include "Plain.h"
Game Game::gameinst=Game();
Game::Game()
{


}
Game &Game::Instance()
{
    return gameinst;
}

void Game::move(QMouseEvent *e)
{
    if(gameobject[posXselec][posYselec].getSelected()){
        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int r= (int)x-5;
        int s= (int)y;

    std::cout<<"la position en X est "<< e->x() <<std::endl;
    std::cout<<"la position en Y est "<< e->y() <<std::endl;
    std::cout<<"la position en X est "<< x <<std::endl;
    std::cout<<"la position en Y est "<< y <<std::endl;
    gameobject[posXselec][posYselec].setPosX(r);
    gameobject[posXselec][posYselec].setPosY(s);
    gameobject[r][s]=gameobject[posXselec][posYselec];
    gameobject[posXselec][posYselec] = *new Gameobject(posXselec,posYselec);
    std::cout<< "gameobject[posXselec][posYselec]="<< gameobject[posXselec][posYselec].getType()  <<std::endl;


    gameobject[r][s].setSelected(false);
    window->redraw();
    }
    else{
        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int z= (int)x-5;
        int e= (int)y;
       if( gameobject[z][e].getType()==2 ){
           std::cout<<"la position en X est "<<std::endl;
             gameobject[z][e].setSelected(true);
             std::cout<<"la position en X est "<<std::endl;
             posXselec=z;
             posYselec=e;
       }
    }
}

void Game::InitGame(MainWindow &wind)
{
    window = &wind ;
    for(int i=0 ;i<21;i++){
        for (int j=0; j <21 ;j++){

            gameobject[i][j]= *new Gameobject(i,j) ;
        }}
    Gameobject Play(5,10,2);
    gameobject[5][10]=Play;
    window->redraw();




}

Gameobject Game::getgameobject(int x, int y)
{
    return gameobject[x][y];

}


