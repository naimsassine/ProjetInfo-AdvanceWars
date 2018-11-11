#include "game.h"
#include"bouton.h"
#include <iostream>
#include <math.h>
#include "Plain.h"
#include "mainwindow.h"
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
#include "Infanterie.h"
#include "Terrain.h"
Game Game::gameinst=Game();
Game::Game()
{


}

std::vector<Ville> Game::getVille() const
{
    return ville;
}

Player *Game::getPlayer() const
{ if(turn==1){
        return player1;}
    else if(turn==2){
        return player2;
    }
    else{
        return nullptr;
    }
}

int Game::getTurn() const
{
    return turn;
}

void Game::setTurn(int value)
{
    turn = value;
}

std::vector<Unites> Game::getUnites() const
{
    return unites;
}

void Game::endtour()
{
    if(turn==1){
        turn=2;
    }
    else if(turn==2){
        turn=1;
    }
}
Game &Game::Instance()
{
    return gameinst;
}


void Game::move(int x,int y)
{

    for(std::vector<Unites>::size_type i = 0; i != unites.size(); i++){
      if( unites[i].getPosX()==x && unites[i].getPosY()==y && unites[i].getTeam()==turn){

           posXselec=i;}
      else if( unites[i].getPosX()==x+1 && unites[i].getPosY()==y && unites[i].getTeam()!=turn){

           unites[i].setUnitin(true);}
      else if( unites[i].getPosX()==x-1 && unites[i].getPosY()==y && unites[i].getTeam()!=turn){

           unites[i].setUnitin(true);}
      else if( unites[i].getPosX()==x && unites[i].getPosY()==y+1 && unites[i].getTeam()!=turn){

           unites[i].setUnitin(true);}
      else if( unites[i].getPosX()==x && unites[i].getPosY()==y-1 && unites[i].getTeam()!=turn){

           unites[i].setUnitin(true);}
      }

    if(unites[posXselec].getTeam()==turn &&unites[posXselec].getSelected()&& unites[posXselec].getPosX()==x && unites[posXselec].getPosY()==y){

    unites[posXselec].setSelected(false);  // deslectionnner une unités deja selectionner //

    }
    else if(unites[posXselec].getTeam()==turn&&unites[posXselec].getSelected()){


        unites[posXselec].setPosX(x);   // faire bouger l'unité //
        unites[posXselec].setPosY(y);



        if(gameobject[x][y].getType()==34){
            for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){


                if(ville[i].getPosX()==x &&ville[i].getPosY()==y){
                    ville[i].setUnitin(true);

                }
                else{
                    ville[i].setUnitin(false);

                }
            }

        }


        /*else if(gameobject[x][y].getType() == 1998 && gameobject[x][y].getTeam() ==2)
        {
            if(gameobject[x][y].getPosX() == unites[posXselec].getPosX() && gameobject[x][y].getPosY() == unites[posYselec].getPosY()){
                unites[posXselec].setUnitin(true);

            }
            else{
                unites[posXselec].setUnitin(false);
            }
        }*/
        unites[posXselec].setSelected(false);
        window->redraw();
    }
    else if(unites[posXselec].getTeam()==turn && !unites[posXselec].getSelected() &&unites[posXselec].getPosX()==x && unites[posXselec].getPosY()==y){


            unites[posXselec].setSelected(true);  // selectionner unité  //

     }


    }





void Game::InitGame(MainWindow &wind,Player &InitPlayer1,Player &InitPlayer2){
    window = &wind ;
    player1=&InitPlayer1;
    player2=&InitPlayer2;


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
                        Ville v(j,d);

                        gameobject[j][d]= v;
                        gameobject[j][d].setType(34);
                        ville.push_back(v);
                    }
                    if(c==30){
                        gameobject[j][d]= Water(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==33){
                        Ville e(j,d);
                        gameobject[j][d]= e;
                        gameobject[j][d].setType(34);
                        ville.push_back(e);
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
                        Ville p(j,d);
                        gameobject[j][d]= p;
                        gameobject[j][d].setType(34);
                        ville.push_back(p);
                    }
                    if(c==35){

                        gameobject[j][d]= Buildings(j,d);
                        gameobject[j][d].setType(35);

                    }
                    if(c==109){
                        gameobject[j][d]= Pipe(j,d);
                        gameobject[j][d].setType(c);
                    }
                    if(c==123){
                        Ville r(j,d);
                        gameobject[j][d]= r;
                        gameobject[j][d].setType(34);
                        ville.push_back(r);
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
                        Ville x(j,d);
                        gameobject[j][d]= x;
                        gameobject[j][d].setType(34);
                        ville.push_back(x);
                    }
                    if (c==92){
                        Ville f(j,d);
                        gameobject[j][d]= f;
                        gameobject[j][d].setType(34);
                        ville.push_back(f);

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
    if(unites[posXselec].getSelected()&& unites[posXselec].getTeam()==turn){
        int PX = 0;
        int PY = 0;


        PX=unites[posXselec].getPosX()+x;
        PY=unites[posXselec].getPosY()+y;
        if (gameobject[PX][PY].getAutorisation() == 77){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else {
            unites[posXselec].setPosX(PX);
            unites[posXselec].setPosY(PY);

        }

        window->redraw();}
}



void Game::createUnite(int x, int y,  int team ){
    Infanterie nom1(x,y,team);

    window->redraw();
    unites.push_back(nom1);

}

void Game::attack(int z, int e,int i){


   /* bool found = false;
    while(i<sizeof (unites) && !found){
        if(unites[i].getPosX() == z && unites[i].getPosY() == e){
            found = true;
        }
        i++;
    }
    i--; //décrement du i de la boucle while en trop
    if(found){
        unites[i].setDamage(unites[posXselec]);
    }*/
    std::cout<<unites[i].getvie()<<std::endl;
    if(unites[i].getvie()>0){
        unites[i].setDamage(unites[posXselec]);
        std::cout<<unites[i].getvie()<<std::endl;


    if(unites[i].getvie() == 0){
        unites.erase(unites.begin() + i);
        //supprimer unites[i]
        window->redraw();
    }
}

   }


void Game::capture(int z, int e)
{   for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){


    if(ville[i].getPosX()==z &&ville[i].getPosY()==e){

        ville[i].setCapturepoint(unites[posXselec].getvie());
        if(ville[i].getCapturepoint()==0){
        gameobject[z][e].setTeam(turn);
        ville[i].setTeam(turn);
        window->redraw();
}
    }
    }


}




