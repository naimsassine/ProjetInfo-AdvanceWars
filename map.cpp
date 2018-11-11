#include "map.h"
#include "game.h"
#include"Infanterie.h"
#include "Unites.h"
#include <QPainter>
#include <iostream>
#include <QPushButton>
#include <QWidget>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTextStream>
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QtMath>
#include <math.h>
#include <stdio.h>
#include <QMenu>
#include <QAction>
#include "usinewindow.h"
Map::Map(QWidget *parent ) : QWidget(parent)
{
setFocusPolicy(Qt::StrongFocus);

}

Map::~Map()
{
    /*delete capture;
    delete wait;*/
}

void Map::paintEvent(QPaintEvent *event)
{   Game game=Game::Instance();
    QPainter painter(this);
    for(int i=0 ;i<21;i++){
        int c=i+5;
        for (int j=0; j <17 ;j++){


           if(gameobject[i][j].getType() == 1){
                  QPixmap pixmap(":/plain.gif");
                  painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }


           else if(gameobject[i][j].getType() == 2){
               QPixmap pixmap(":/mountain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 3){
               QPixmap pixmap(":/wood.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 4){
               QPixmap pixmap(":/hriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 5){
               QPixmap pixmap(":/vriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 6){
               QPixmap pixmap(":/criver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 7){
               QPixmap pixmap(":/esriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 8){
               QPixmap pixmap(":/swriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 9){
               QPixmap pixmap(":/wnriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 104){
               QPixmap pixmap(":/espipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 102){
               QPixmap pixmap(":/hpipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 108){
               QPixmap pixmap(":/epipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 18){
               QPixmap pixmap(":/esroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 15){
               QPixmap pixmap(":/hroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 34){

               if(gameobject[i][j].getTeam()==0){
               QPixmap pixmap(":/neutralcity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);}
               if(gameobject[i][j].getTeam()==1){
               QPixmap pixmap(":/orangestarcity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);}
               if(gameobject[i][j].getTeam()==2){
               QPixmap pixmap(":/bluemooncity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);}
           }
           else if(gameobject[i][j].getType() == 30){
               QPixmap pixmap(":/hshoal.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 33){
               QPixmap pixmap(":/reef.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 19){
               QPixmap pixmap(":/swroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 106){
               QPixmap pixmap(":/wnpipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 24){
               QPixmap pixmap(":/wneroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 22){
               QPixmap pixmap(":/eswroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 101){
               QPixmap pixmap(":/vpipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 125){
               QPixmap pixmap(":/jadesunhq.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 35){
               QPixmap pixmap(":/neutralbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 109){
               QPixmap pixmap(":/spipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 123){
               QPixmap pixmap(":/jadesunbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 23){
               QPixmap pixmap(":/swnroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 21){
               QPixmap pixmap(":/neroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 16){
               QPixmap pixmap(":/vroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 26){
               QPixmap pixmap(":/hbridge.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 29){
               QPixmap pixmap(":/hshoal.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 20){
               QPixmap pixmap(":/wnroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 110){
               QPixmap pixmap(":/wpipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 36){
               QPixmap pixmap(":/neutralairport.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 95){
               QPixmap pixmap(":/blackholehq.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 92){
               QPixmap pixmap(":/blackholebase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 25){
               QPixmap pixmap(":/nesroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 10){
               QPixmap pixmap(":/neriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 107){
               QPixmap pixmap(":/npipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }


           else{
               QPixmap pixmap(":/osinfantry.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);}
        }
    }
    std::vector<Unites> unites= game.getUnites();
    for(std::vector<Unites>::size_type i = 0; i != unites.size(); i++){

        if(unites[i].getType()==1998 && unites[i].getTeam()==1 ){

            QPixmap pixmap(":/osinfantry.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);

        }
        else if(unites[i].getType()==1998 && unites[i].getTeam()==2){
            QPixmap pixmap(":/blue.png");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);

        }


    }

}

void Map::redraw()
{
    this->repaint();
}

void Map::captureville()
{
    Game& game=Game::Instance();
    game.capture(z,e);
}


void Map::mousePressEvent(QMouseEvent *ev)
{
    float x=floorf(ev->x()/40);
    float y=floorf(ev->y()/40); // fonction deja implementé //
    z= (int)x-5;
    e= (int)y;
    if(ev->buttons() == Qt::LeftButton){
        Game& game=Game::Instance();





        if (gameobject[z][e].getAutorisation() == 77){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 35){
            UsineWindow w;

            w.setX(z);
            w.setY(e);
            w.exec();
            /*Game& game=Game::Instance();
            int reponse = QMessageBox::question(this, "Création d'Infanterie", "Voulez-vous créer une unité d'infanterie ?", QMessageBox ::Yes | QMessageBox::No);

                if (reponse == QMessageBox::Yes)
                {
                    if(game.getTurn()==1)
                    {
                        game.createUnite(z+1, e, 1);
                        this->redraw();
                    }
                    else
                    {
                        game.createUnite(z+1, e, 2);
                        this->redraw();
                    }

                }
                else if( reponse == QMessageBox::No)
                {
                 game.move(z+1,e);
                }*/

        }


        else{
         game.move(z,e);
        }

    }
    else if(ev->buttons() == Qt::RightButton){
        if (gameobject[z][e].getType() == 34){
            Game& game=Game::Instance();
            std::vector<Ville> ville =game.getVille();
            for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){


                if(ville[i].getPosX()==z &&ville[i].getPosY()==e && ville[i].getUnitin() && ville[i].getTeam()==0){
                    QMenu menu(this);
                    capture =new QAction("Capture", this);
                    menu.addAction(capture);
                    wait =new QAction("Wait", this);
                    menu.addAction(wait);
                    QObject::connect(capture, SIGNAL(triggered()), this, SLOT(captureville()));

                    // Place the menu in the right position and show it.
                    menu.exec(ev->globalPos());
                   }
            }
            /**std::vector<Unites> uni = game.getUnites();
            unsigned int i = 0;
            bool found = false;
            while( i < sizeof(uni)){
                if(uni[i].getPosX() == z && uni[i].getPosY() == e){
                    found = true;
                }
                i++;

            }i--;
            if(found){
                QMenu menu(this);
                attack =new QAction("Attack", this);
                menu.addAction(attack);

                QObject::connect(attack, SIGNAL(triggered()), this, SLOT(attack()));
                menu.exec(ev->globalPos());
            }**/



        }
        else if(gameobject[z][e].getType() == 1998){
            Game& game=Game::Instance();
            std::vector<Unites> unite =game.getUnites();
            for(std::vector<Unites>::size_type i = 0; i != unite.size(); i++){


                if(unite[i].getPosX()==z &&unite[i].getPosY()==e &&  unite[i].getTeam()==0){
                    QMenu menu(this);
                    attack =new QAction("Attaquer", this);
                    menu.addAction(attack);
                    wait =new QAction("Wait", this);
                    menu.addAction(wait);
                    QObject::connect(attack, SIGNAL(triggered()), this, SLOT(attack()));

                    // Place the menu in the right position and show it.
                    menu.exec(ev->globalPos());
                   }
            }


    }}




}

void Map::keyPressEvent(QKeyEvent *keyEvent)
{
    Game& game=Game::Instance();
        switch (keyEvent->key()) {
        case Qt::Key_Down:

            game.movearrow(0,1);
            break;
        case Qt::Key_Left:
            game.movearrow(-1,0);
            break;
        case Qt::Key_Right:
            game.movearrow(1,0);
            break;
        case Qt::Key_Up:
            game.movearrow(0,-1);
            break;
        default:
            break;
        }
}


void Map::setgameobject()
{   Game& game=Game::Instance();
    for(int i=0 ;i<21;i++){
        for (int j=0; j <17 ;j++){
            gameobject[i][j]=game.getgameobject(i,j);
        }}

}

