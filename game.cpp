#include "game.h"
#include <iostream>
#include <math.h>
#include "Plain.h"
#include "Water.h"
#include "Mountain.h"
#include <QTextStream>
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
    Gameobject c =gameobject[r][s];
    gameobject[posXselec][posYselec].setPosX(r);
    gameobject[posXselec][posYselec].setPosY(s);
    gameobject[r][s]=gameobject[posXselec][posYselec];
    gameobject[posXselec][posYselec] =set;
    set=c;
    std::cout<< "gameobject[posXselec][posYselec]="<< gameobject[posXselec][posYselec].getType()  <<std::endl;


    gameobject[r][s].setSelected(false);
    window->redraw();
    }
    else{
        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int z= (int)x-5;
        int e= (int)y;
       if( gameobject[z][e].getType()==36 ){
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


    int c;
    QFile df(":/map.txt");

     if (!df.open(QIODevice::ReadOnly | QIODevice::Text)) {


                }

                QTextStream txStream(&df);
                int d=0;

                while (!txStream.atEnd()) {

                    QString text = txStream.readLine();
                    QStringList s=text.split(",");
                    for(int j =0 ;j<20 ;j++){
                    c = s[j].toInt();
                    if(c==1){
                        gameobject[j][d]= Plain(j,d);

                    }
                    if(c==2){
                        gameobject[j][d]= Water(j,d);

                    }
                    if(c==3){
                        gameobject[j][d]= Mountain(j,d);

                    }


                    }
                    d++;


                }

            df.close();

            Gameobject Play(5,10,36);
            set=gameobject[5][10];
            gameobject[5][10]=Play;
            window->redraw();




}

Gameobject Game::getgameobject(int x, int y)
{
    return gameobject[x][y];

}


