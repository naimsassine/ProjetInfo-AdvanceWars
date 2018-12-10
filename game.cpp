#include "game.h"
#include"bouton.h"
#include "Aerienne.h"
#include"Aeroport.h"
#include"bomber.h"
#include"b_copter.h"
#include"fighter.h"
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
#include "bazooka.h"
#include "Infanterie.h"
#include "anti_air.h"
#include "b_copter.h"
#include "bomber.h"
#include "fighter.h"
#include "md_tank.h"
#include "mega_tank.h"
#include "neotank.h"
#include "recon.h"
#include "tank.h"
#include "Usine.h"
#include "Terrain.h"
#include "wood.h"
#include "river.h"
#include "shoal.h"
#include "reef.h"
Game Game::gameinst=Game();
Game::Game()
{
actville = nullptr;

}

int Game::getPosXselec() const
{
    return posXselec;
}

MainWindow *Game::getWindow() const
{
    return window;
}

void Game::setActville(Ville *value)
{
    actville = value;
}

Ville *Game::getActville() const
{
    return actville;
}


bool Game::getUnitincity() const
{
    return unitincity;
}

void Game::setUnitincity(bool value)
{
    unitincity = value;
}

void Game::setComptattack()
{
    unites[posXselec].setComptattack(false);
}

void Game::setComptcapture()
{
    unites[posXselec].setComptcapture(false);
}

void Game::setComptfusion()
{
    unites[posXselec].setComptfusion(false);
}

void Game::setComptproduction(int x, int y)
{
    for(Usine& u : usine){
        if(u.getPosX()==x && u.getPosY()==y){
            u.setComptproduction(false);
        }
    }
}
std::vector<Aeroport> Game::getAeroport() const
{
    return aeroport;
}
std::vector<Usine> Game::getUsine() const{
    return usine;
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

void Game::moveable(int move, int x, int y ,int typeu)
{   for (Unites & u : unites) {
         if( u.getPosX()==x+1 && u.getPosY()==y ){

             gameobject[x+1][y].setUnitin(true);}
        else if( u.getPosX()==x-1 && u.getPosY()==y ){

             gameobject[x-1][y].setUnitin(true);}
        else if( u.getPosX()==x && u.getPosY()==y+1 ){

             gameobject[x][y+1].setUnitin(true);}
        else if( u.getPosX()==x && u.getPosY()==y-1 ){

             gameobject[x][y-1].setUnitin(true);}
        }

    if(x<21 && x>-1 && y<17 && y>-1){
        if(move >= gameobject[x+1][y].getPtdemouvement(typeu) &&!gameobject[x+1][y].getUnitin() ){
            gameobject[x+1][y].setMovable(true);
            int s = move-gameobject[x+1][y].getPtdemouvement(typeu);

            if(gameobject[x+1][y].getPtdemouvement(typeu)==0){

                 gameobject[x+1][y].setMovable(false);
            }
            else{
            moveable(s,x+1,y,typeu);
            }
    }
    if(move >= gameobject[x-1][y].getPtdemouvement(typeu)&& !gameobject[x-1][y].getUnitin()){
        gameobject[x-1][y].setMovable(true);

        int s = move-gameobject[x-1][y].getPtdemouvement(typeu);
        if(gameobject[x-1][y].getPtdemouvement(typeu)==0){

             gameobject[x-1][y].setMovable(false);
        }
        else{
        moveable(s,x-1,y,typeu);
        }

    }
    if(move >= gameobject[x][y+1].getPtdemouvement(typeu)&&!gameobject[x][y+1].getUnitin()){

                gameobject[x][y+1].setMovable(true);

                int s = move-gameobject[x][y+1].getPtdemouvement(typeu);
                if(gameobject[x][y+1].getPtdemouvement(typeu)==0){

                     gameobject[x][y+1].setMovable(false);
                }
                else{
                moveable(s,x,y+1,typeu);
                }

    }
    if(move >= gameobject[x][y-1].getPtdemouvement(typeu)&& !gameobject[x][y-1].getUnitin()){
                        gameobject[x][y-1].setMovable(true);

                        int s = move-gameobject[x][y-1].getPtdemouvement(typeu);

                        if(gameobject[x][y-1].getPtdemouvement(typeu)==0){

                             gameobject[x][y-1].setMovable(false);
                        }
                        else{
                        moveable(s,x,y-1,typeu);
                        }


            }
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
{   int nbrebatiment = 0;
    for (int h = 0 ;h < 21;h++) {
        for (int j=0; j <17 ;j++) {
            if ( (gameobject[h][j].getType() == 34 || gameobject[h][j].getType() == 35 || gameobject[h][j].getType() == 39 ||gameobject[h][j].getType() == 44) &&gameobject[h][j].getTeam()==turn) {
                nbrebatiment++;
            }
        }
    }
    for(Usine& u :usine){
        u.setComptproduction(true);

    }
    getPlayer()->setMoney(getPlayer()->getMoney()+(1000*nbrebatiment));
    if (turn==1) {
        for(std::vector<Unites>::size_type i = 0; i != unites.size(); i++)
        {
            unites[i].setComptattack(true);
            unites[i].setComptcapture(true);
            unites[i].setComptmouvement(true);
            unites[i].setComptfusion(true);
            for(int h=0 ;h<21;h++){
                for (int j=0; j <17 ;j++){
                    if( unites[i].getTeam()==turn && unites[i].getPosX() == h && unites[i].getPosY() == j && unites[i].getvie() < 10 && (gameobject[h][j].getType() == 34 || gameobject[h][j].getType() == 35 || gameobject[h][j].getType() == 39 ) ){
                        int x = int(0.01*(unites[i].getPrix()));
                        unites[i].setvie(10);
                        getPlayer()->setMoney(getPlayer()->getMoney()-(x));
                    }

                }}
        }
        turn=2;


    }
    else if (turn==2) {
        for (std::vector<Unites>::size_type i = 0; i != unites.size(); i++)
        {
            unites[i].setComptattack(true);
            unites[i].setComptcapture(true);
            unites[i].setComptmouvement(true);
            unites[i].setComptfusion(true);
            for(int h=0 ;h<21;h++){
                for (int j=0; j <17 ;j++){
                    if( unites[i].getTeam()==turn && unites[i].getPosX() == h && unites[i].getPosY() == j && unites[i].getvie() < 10 && (gameobject[h][j].getType() == 34 || gameobject[h][j].getType() == 35 || gameobject[h][j].getType() == 44 ) ){
                        int x = int(0.01*(unites[i].getPrix()));
                        unites[i].setvie(10);
                        getPlayer()->setMoney(getPlayer()->getMoney()-(x));
                    }
                }}
        }
        turn=1;
    }

}
Game &Game::Instance()
{
    return gameinst;
}


void Game::move(int x,int y)
{
    if (gameobject[x][y].getType() == 34
        || gameobject[x][y].getType() == 35
        || gameobject[x][y].getType() == 36
        || gameobject[x][y].getType() == 39)
    {
        gameobject[x][y].setSelected(true);
        window->update();
        window->redraw();
    }
    if (gameobject[x][y].getType() != 700) {
        gameobject[x][y].setSelected(true);
        window->update();
        window->redraw();
    }
    gameobject[z][e].setSelected(false);
    z = x;
    e = y;

    window->redraw();

    for (std::vector<Unites>::size_type i = 0; i != unites.size(); i++) {
        int count=0;
        if (unites[i].isAtPos(x, y) && unites[i].getTeam() == turn) {
            posXselec = static_cast<int>(i);
        } else if (unites[i].isAtPos(x+1, y) ) {
            count=1;
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x-1, y) ) {
            count=1;
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x, y+1) ) {
            count=1;
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x, y-1) ) {
            count=1;
            unites[i].setUnitin(true);
        }
        else{
             unites[i].setUnitin(false);
        }
        if(count==1){
            unites[posXselec].setUnitin(true);
        }
    }

    Unites& u = unites[posXselec];
    for (Ville& v : ville) {  // plus joli quand mme

       if(v.getTeam()==turn){
        v.setUnitin(false);}
       if(u.isAtPos(v.getPosX(),v.getPosY())){
           v.setUnitin(true);
       }

    }
    for (Usine& v :usine){
        if(v.getTeam()==turn){
         v.setUnitin(false);}
        if(u.isAtPos(v.getPosX(),v.getPosY())){
            v.setUnitin(true);
        }
    }

    for(Aeroport& v : aeroport){
        if(v.getTeam()==turn){
         v.setUnitin(false);}
        if(u.isAtPos(v.getPosX(),v.getPosY())){
            v.setUnitin(true);
        }
    }
    for (std::vector<Unites>::size_type i = 0; i != unites.size(); i++) {
        if (unites[i].isAtPos(x, y) && unites[i].getTeam() == turn) {
            posXselec = static_cast<int>(i);
        } else if (unites[i].isAtPos(x+1, y) ) {
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x-1, y) ) {
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x, y+1) ) {
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x, y-1) ) {
            unites[i].setUnitin(true);
        }
        else{
             unites[i].setUnitin(false);
        }
        std::cout<<unites[i].getUnitin()<<std::endl;
    }

    for (std::vector<Terrain>::size_type i = 0; i != terrain.size(); i++){
        terrain[i].setUnitin(false);
    }

    if (u.getTeam()==turn && u.isSelected() && u.isAtPos(x, y)) {
        unites[posXselec].setSelected(false);
        for (int i=0 ;i<21;i++) {
            for (int j=0; j <17 ;j++) {
                gameobject[i][j].setMovable(false);
                gameobject[i][j].setUnitin(false);
                gameobject[i][j].setSelected(false);
            }
        }
        window->redraw();// deslectionnner une unités deja selectionner //

    }

    else if (u.getTeam() == turn
            && u.getSelected()  // should rename "getSelected" to "isSelected"
            && gameobject[x][y].getMovable()
            && u.getComptmouvement())
    {

        u.setPos(x, y);   // faire bouger l'unité
        u.setComptmouvement(false);
        // Afficher un message tu dois plus bouger
        for (int i=0 ;i<21;i++) {
            for (int j=0; j <17 ;j++) {
                gameobject[i][j].setMovable(false);
                gameobject[i][j].setUnitin(false);
                gameobject[i][j].setSelected(false);
            }
        }

        if(gameobject[x][y].getType()==34){
            for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){
                if(ville[i].getPosX()==u.getPosX() &&ville[i].getPosY()==u.getPosY()) {
                    ville[i].setUnitin(true);
                    ville[i].setSelected(true);
                    window->changeCaptWindow(ville[i]);
                    window->update();
                    window->redraw();

                }
                else {
                    ville[i].setUnitin(false);
                    ville[i].setSelected(false);
                   // window->changeCaptWindow(ville[i]);
                   // window->redraw();
                }
            }

        }

        else if(gameobject[x][y].getType() == 36){
            for(std::vector<Aeroport>::size_type i = 0; i != aeroport.size(); i++){

                if(aeroport[i].getPosX()==x && aeroport[i].getPosY()==y){
                    aeroport[i].setUnitin(true);
                    aeroport[i].setUnitin(true);
                    window->changeCaptWindow(aeroport[i]);

                }
                else{
                    aeroport[i].setUnitin(false);
                    aeroport[i].setUnitin(false);
                }

            }
        }

        else if(gameobject[x][y].getType() == 35){
            for(std::vector<Usine>::size_type i = 0; i!= usine.size(); i++){
                if(usine[i].getPosX()==x && usine[i].getPosY()==y){
                    usine[i].setUnitin(true);
                    usine[i].setSelected(true);
                    window->changeCaptWindow(usine[i]);
                }
                else{
                    usine[i].setUnitin(false);
                    usine[i].setSelected(false);
                }

            }
        }
        else if(gameobject[x][y].getType() != 700){
            //for(std::vector<Terrain>::size_type i = 0; i!= terrain.size(); i++){
                if(gameobject[x][y].getPosX()==x && gameobject[x][y].getPosY()==y){
                    gameobject[x][y].setUnitin(true);
                    gameobject[x][y].setSelected(true);
                    window->changeDefWindow(gameobject[x][y]);
                }
                else{
                    gameobject[x][y].setUnitin(false);
                    gameobject[x][y].setSelected(false);
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
    else if(unites[posXselec].getTeam()==turn && !unites[posXselec].getSelected() &&unites[posXselec].getPosX()==x && unites[posXselec].getPosY()==y && u.getComptmouvement()){


            unites[posXselec].setSelected(true);
            window->changeVieWindow(unites[posXselec]);
            window->changeDammageWindow(unites[posXselec]);
            int c= unites[posXselec].getPtdeplacement();// selectionner unité  //
            moveable(c,unites[posXselec].getPosX(),unites[posXselec].getPosY(),unites[posXselec].getTypeu());
            window->redraw();

    }
    if(unites[posXselec].getTeam()==turn&&unites[posXselec].getSelected() && gameobject[x][y].getMovable() ){
        unites[posXselec].setSelected(true);
        window->synchro(unites[posXselec]);
        window->redraw();
    }
    for (std::vector<Unites>::size_type i = 0; i != unites.size(); i++) {
        int count=0;
        if (unites[i].isAtPos(x, y) && unites[i].getTeam() == turn) {
            posXselec = static_cast<int>(i);
        } else if (unites[i].isAtPos(x+1, y) ) {
            count=1;
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x-1, y) ) {
            count=1;
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x, y+1) ) {
            count=1;
            unites[i].setUnitin(true);
        } else if (unites[i].isAtPos(x, y-1) ) {
            count=1;
            unites[i].setUnitin(true);
        }
        else{
             unites[i].setUnitin(false);
        }
        if(count==1){
            unites[posXselec].setUnitin(true);
        }
    }
}


void Game::InitGame(MainWindow *wind,Player *InitPlayer1,Player *InitPlayer2){
    window = wind;
    player1 = InitPlayer1;
    player2 = InitPlayer2;


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
                gameobject[j][d]= Wood(j,d);

            }
            if(c==4){
                gameobject[j][d]= River(j,d);
                gameobject[j][d].setType(4);
            }
            if(c==5){
                gameobject[j][d]= River(j,d);
                gameobject[j][d].setType(5);
            }
            if(c==6){
                gameobject[j][d]= River(j,d);
                gameobject[j][d].setType(c);
            }
            if(c==7){
                gameobject[j][d]= River(j,d);
                gameobject[j][d].setType(c);
            }
            if(c==8){
                gameobject[j][d]= River(j,d);
                gameobject[j][d].setType(c);
            }
            if(c==9){
                gameobject[j][d]= River(j,d);
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
                v.setType(34);
                ville.push_back(v);
            }
            if(c==30){
                gameobject[j][d]= Shoal(j,d);

            }
            if(c==33){
                gameobject[j][d]= Reef(j,d);
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
                Ville p(j,d);
                gameobject[j][d]= p;
                p.setType(34);
                gameobject[j][d].setType(34);
                ville.push_back(p);
            }
            if(c==35){
                Usine u(j,d);


                gameobject[j][d]= u;
                gameobject[j][d].setType(35);
                usine.push_back(u);
            }
            if(c==39){
                Usine uorange(j,d);


                gameobject[j][d]= uorange;
                gameobject[j][d].setType(39);
                gameobject[j][d].setTeam(1);
                uorange.setTeam(1);
                usine.push_back(uorange);
            }
            if(c==44){
                Usine ublue(j,d);


                gameobject[j][d]= ublue;
                gameobject[j][d].setType(44);
                gameobject[j][d].setTeam(2);
                ublue.setTeam(2);
                usine.push_back(ublue);
            }
            if(c==109){
                gameobject[j][d]= Pipe(j,d);
                gameobject[j][d].setType(c);
            }
            if(c==123){
                Ville r(j,d);
                gameobject[j][d]= r;
                r.setType(34);
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
                Aeroport y(j,d);
                gameobject[j][d]= Aeroport(j,d);
                gameobject[j][d].setType(c);
                aeroport.push_back(y);
            }
            if (c==95){
                Ville x(j,d);
                gameobject[j][d]= x;
                x.setType(34);
                gameobject[j][d].setType(34);
                ville.push_back(x);
            }
            if (c==92){
                Ville f(j,d);
                gameobject[j][d]= f;
                f.setType(34);
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
    unites.push_back(Play);  // Attention copie (héritage perdu) (vidéo Héritage)
    unites.push_back(Play2);

    window->redraw();
}


Gameobject const& Game::getgameobject(int x, int y) const
{
    return gameobject[x][y];
}


void Game::movearrow(int x, int y){
    if(unites[posXselec].getSelected() && unites[posXselec].getTeam() == turn) {
        int PX = unites[posXselec].getPosX() + x;
        int PY = unites[posXselec].getPosY() + y;
        if (gameobject[PX][PY].getAutorisation() == 77){
           }
        else {
            unites[posXselec].setPosX(PX);
            unites[posXselec].setPosY(PY);
        }

        window->redraw();
    }
}



void Game::createUnite(int x, int y,  int team ,int type ){
    if(type == 1998){
        Infanterie nom1(x,y,team);
        printf("big fat lol");

        window->redraw();
        unites.push_back(nom1);
    }
    else if( type == 2000){
        B_Copter copt1(x,y,team);
        window->redraw();
        unites.push_back(copt1);
    }
    else if( type == 2001){
        Bomber bomb1(x,y,team);
        window->redraw();
        unites.push_back(bomb1);
    }
    else if( type == 2002){
        Fighter fight1(x,y,team);
        window->redraw();
        unites.push_back(fight1);
    }
    else if( type == 2003){
        Bazooka fight1(x,y,team);
        window->redraw();
        unites.push_back(fight1);
    }
    else if( type == 3000){
        Recon recon1(x,y,team);
        window->redraw();
        unites.push_back(recon1);
    }
    else if( type == 3001){
        Anti_Air anti_air1(x,y,team);
        window->redraw();
        unites.push_back(anti_air1);
    }
    else if( type== 3002){
        Tank tank1(x,y,team);
        window->redraw();
        unites.push_back(tank1);
    }
    else if(type == 3003){
        MD_tank md_tank1(x,y,team);
        window->redraw();
        unites.push_back(md_tank1);
    }
    else if(type == 3004){
        mega_tank mega_tank1(x,y,team);
        window->redraw();
        unites.push_back(mega_tank1);
    }
    else if(type == 3005){
        Neotank neotank1(x,y,team);
        window->redraw();
        unites.push_back(neotank1);
    }

}

void Game::attack(int z, int e,int i){

    if(unites[i].getvie()>0){
        int x = unites[i].getPosX();
        int y = unites[i].getPosY();
        int r = unites[posXselec].getPosX();
        int s = unites[posXselec].getPosY();
        int defTerrain1 = gameobject[x][y].getdefTerrain(gameobject[x][y].getPosdef());
        int defTerrain2 = gameobject[r][s].getdefTerrain(gameobject[r][s].getPosdef());
        unites[i].setDamage(unites[posXselec],unites[i],defTerrain1);
        unites[posXselec].setDamage(unites[i],unites[posXselec],defTerrain2);



        if(unites[i].getvie() == 0){
             int T = unites[i].getTeam();
             unites.erase(unites.begin() + i);
             //supprimer unites[i]
             window->redraw();
             int nombreunites = 0;
             for(int unsigned j=0;j<unites.size();j++)
             {
                 if(unites[j].getTeam()==T){
                    nombreunites = nombreunites+1;
                 }
             }
             if(nombreunites==0){

             }
        }
        if(unites[posXselec].getvie() == 0){
             unites.erase(unites.begin() + posXselec);
            //supprimer unites[i]
             window->redraw();
        }
}

   }
void Game::fusion( int v, int w){
    Unites& a = unites[v];  // attention, vien ^^etre sur que ya pas de out_of_range
    Unites& b = unites[w];
    unites[w].setUnitin(false);
    unites[v].setUnitin(false);
    if(a.getSelected() == true){
        unites.erase(unites.begin() + v);
        if(a.getvie()+b.getvie()>=10){
            unites[w].setvie(10);
        }
        if(a.getvie()+b.getvie()<10){
           unites[w].setvie(a.getvie()+b.getvie());
        }
    }
    else{
        unites.erase(unites.begin() + w);
        if(a.getvie()+b.getvie()>=10){
            unites[v].setvie(10);
        }
        if(a.getvie()+b.getvie()<10){
           unites[v].setvie(a.getvie()+b.getvie());
        }
    }
    window->redraw();

}
/*void Game::fusion(int z, int e, Unites u1, Unites u2){
    u1.getPosX() == z;
    u1.getPosY() == e;

    if(u1.getTeam() == u2.getTeam() && u1.getType() == u2.getType()){
        if(u1.getvie() < 10 && u2.getvie() < 10){
            if(u1.getSelected() == true){
              if(u1.getvie() + u2.getvie() <= 10){

                    u1.getvie() == u1.getvie() + u2.getvie();
              }
              else
              {
                  u1.getvie() == 10;
              }
            }
            else if(u2.getSelected() == true){
                if(u1.getvie() + u2.getvie() <= 10){

                      u2.getvie() == u2.getvie() + u1.getvie();
                }
                else
                {
                    u2.getvie() == 10;
                }

            }

        }

    }
}*/



void Game::capture(int z, int e)
{


    for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){


    if(ville[i].getPosX()==z &&ville[i].getPosY()==e  && unites[posXselec].getType() == 1998){

        ville[i].setCapturepoint(unites[posXselec].getvie());
        window->changeCaptWindow(ville[i]);
        ville[i].setUnite(&unites[posXselec]);
        actville=&ville[i];
        window->redraw();
        if(ville[i].getCapturepoint()==0){
        gameobject[z][e].setTeam(turn);
        ville[i].setCapturepoint(20);
        ville[i].setTeam(turn);
        window->update();

        window->redraw();
        if( unites[posXselec].getPosX() != z || unites[posXselec].getPosY() != e && ville[i].getCapturepoint() > 0){
            ville[i].setCapturepoint(20);
            window->update();
            window->redraw();

        }

}
    }
   /* else if((gameobject[z][e].getType()!= 34 && unites[posXselec].getType() == 1998 ) && unites[posXselec].getPosX() != z && unites[posXselec].getPosY() != e){
        if(ville[i].getCapturepoint() >0){
        ville[i].setCapturepoint(20);
        window->changeCaptWindow(ville[i]);


        window->update();

        window->redraw();
        }

}*/

    }
    }





void Game::capture_Usine(int z, int e)
{
    for(std::vector<Usine>::size_type i = 0; i != usine.size(); i++){


    if(usine[i].getPosX()==z &&usine[i].getPosY()==e  && unites[posXselec].getType() == 1998){

        usine[i].setCapturepoint(unites[posXselec].getvie());
        if(usine[i].getCapturepoint()==0){
        gameobject[z][e].setTeam(turn);
        usine[i].setTeam(turn);
        window->redraw();
}
    }
    }


}
void Game::capture_Aeroport(int z, int e)
{
    for(std::vector<Aeroport>::size_type i = 0; i != aeroport.size(); i++){


    if(aeroport[i].getPosX()==z &&aeroport[i].getPosY()==e && unites[posXselec].getType() == 1998){

        aeroport[i].setCapturepoint(unites[posXselec].getvie());
        if(aeroport[i].getCapturepoint()==0){
        gameobject[z][e].setTeam(turn);
        aeroport[i].setTeam(turn);
        window->redraw();
}
    }
    }


}
void Game::affichage(){
    if(unites[posXselec].getTeam()==turn && unites[posXselec].getSelected()== true){
        window->synchro(unites[posXselec]);
        window->redraw();

    }
}

bool Game::samePos() const{
    for(int i=0 ;i<21;i++){
        for (int j=0; j <17 ;j++){
    //int x =0;
    //int y =0;

    if(unites[posXselec].getPosX() == gameobject[i][j].getPosX() && unites[posYselec].getPosY() == gameobject[i][j].getPosY() ) {
        return same;
        }
}
    }

}

