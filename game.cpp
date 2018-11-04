#include "game.h"
#include"bouton.h"
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
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
Game Game::gameinst=Game();
Game::Game()
{


}

std::vector<Unites> Game::getUnites() const
{
    return unites;
}
Game &Game::Instance()
{
    return gameinst;
}


void Game::move(int x,int y)
{

    if(unites[posXselec].getSelected()){




    Gameobject c =gameobject[x][y];
    unites[posXselec].setPosX(x);
    unites[posXselec].setPosY(y);

    std::cout<< "gameobject[posXselec][posYselec]="<< gameobject[posXselec][posYselec].getType()  <<std::endl;



    unites[posXselec].setSelected(false);

    window->redraw();
    }
    else{
     for(std::vector<Unites>::size_type i = 0; i != unites.size(); i++){
       if( unites[i].getPosX()==x && unites[i].getPosY()==y ){
           std::cout<<"la position en X est "<<std::endl;
            unites[i].setSelected(true);
             std::cout<<"la position en X est "<<std::endl;

             posXselec=i;
       }



     }

    }
}



void Game::InitGame(MainWindow &wind){
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
                window->InitMap();

            df.close();
            Infanterie Play(5,10,1);
            Infanterie Play2(10,10,2);
            unites.push_back(Play);
            unites.push_back(Play2);
            window->redraw();




}

Gameobject Game::getgameobject(int x, int y)
{
    return gameobject[x][y];

}




void Game::movearrow(int x, int y){
    if(unites[posXselec].getSelected()){

        x=unites[posXselec].getPosX()+x;
        y=unites[posXselec].getPosY()+y;

        unites[posXselec].setPosX(x);
        unites[posXselec].setPosY(y);


        window->redraw();}
}


