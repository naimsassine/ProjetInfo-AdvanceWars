#include "game.h"
#include <iostream>
#include <math.h>
#include "Plain.h"
#include "Water.h"
#include "Mountain.h"
#include "Ville.h"
#include "Aeroport.h"
#include "Pipe.h"
#include "Road.h"
#include "Infanterie.h"
#include <QTextStream>
Game Game::gameinst=Game();
Game::Game()
{


}
Game &Game::Instance()
{
    return gameinst;
}


void Game::move(int x,int y)
{
    if(gameobject[posXselec][posYselec].getSelected()){

    std::cout<<"la position en X est "<< x <<std::endl;
    std::cout<<"la position en Y est "<< y <<std::endl;
    Gameobject c =gameobject[x][y];
    gameobject[posXselec][posYselec].setPosX(x);
    gameobject[posXselec][posYselec].setPosY(y);
    gameobject[x][y]=gameobject[posXselec][posYselec];
    gameobject[posXselec][posYselec] =set;
    set=c;
    std::cout<< "gameobject[posXselec][posYselec]="<< gameobject[posXselec][posYselec].getType()  <<std::endl;
<<<<<<< HEAD
//<<<<< HEAD
   //ameobject[r][s].setSelected(false);
//=======


   //ameobject[x][y].setSelected(false);
//>>>>> 1c7c5eefb17152d0e80385af124259d2e83269b4
=======
/*<<<<<<< HEAD
    gameobject[r][s].setSelected(false);
=======


    gameobject[x][y].setSelected(false);
>>>>>>> 1c7c5eefb17152d0e80385af124259d2e83269b4 */
>>>>>>> 88bb820b5047f523774c03792afeeda14ec3718b
    window->redraw();
    }
    else{

       if( gameobject[x][y].getType()==1998 ){
           std::cout<<"la position en X est "<<std::endl;
             gameobject[x][y].setSelected(true);
             std::cout<<"la position en X est "<<std::endl;
             posXselec=x;
             posYselec=y;
       }
    }
}

void Game::movearrow(int x, int y)
{

    if(gameobject[posXselec][posYselec].getSelected()){

        x=gameobject[posXselec][posYselec].getPosX()+x;
        y=gameobject[posXselec][posYselec].getPosY()+y;
        Gameobject c =gameobject[x][y];
        gameobject[posXselec][posYselec].setPosX(x);
        gameobject[posXselec][posYselec].setPosY(y);
        gameobject[x][y]=gameobject[posXselec][posYselec];
        gameobject[posXselec][posYselec] =set;
        set=c;
        posXselec=x;
        posYselec=y;
        window->redraw();}

}

void Game::InitGame(MainWindow &wind)
{
    window = &wind ;


    int c;
    QFile df(":/reelmap.txt");

     if (!df.open(QIODevice::ReadOnly | QIODevice::Text)) {

                }

                QTextStream txStream(&df);
                int d=0;

                while (!txStream.atEnd()) {

                    QString text = txStream.readLine();
                    QStringList s=text.split(",");
                    for(int j =0 ;j<21 ;j++){
                    c = s[j].toInt();

                    if(c==1){
                        gameobject[j][d]= Plain(j,d);
                    }
                    if(c==2){
                        gameobject[j][d]= Mountain(j,d);
                    }
                    if(c==3){
                        gameobject[j][d]= Mountain(j,d);
                        gameobject[j][d].setType(3);
                    }
                    if(c==4){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(4);
                    }
                    if(c==5){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(5);
                    }
                    if(c==6){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==7){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==8){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==9){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==104){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==102){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==108){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==18){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==15){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==34){
                        gameobject[j][d]= Ville(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==30){
                        gameobject[j][d]= Plain(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==33){
                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==19){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==106){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==24){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==22){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==101){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==125){
                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==35){
                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==109){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==123){
                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==23){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==21){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==16){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==26){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==29){
                        gameobject[j][d]= Plain(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==20){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==110){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==36){
                        gameobject[j][d]= Aeroport(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if (c==95){
                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if (c==92){
                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if (c==107){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if (c==25){
                        gameobject[j][d]= Road(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if (c==10){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(c);
                    }


                    }
                    d++;


                }

            df.close();
            Infanterie Play(5,10);
            set=gameobject[5][10];
            gameobject[5][10]=Play;
            window->redraw();




}

Gameobject Game::getgameobject(int x, int y)
{
    return gameobject[x][y];

}


