#include "map.h"
#include "game.h"
#include <QPainter>
#include <iostream>
#include <QPushButton>
#include <QMouseEvent>
#include <QTextStream>
#include <QtMath>
#include <math.h>
#include <stdio.h>

Map::Map(QWidget *parent ) : QWidget(parent)
{
setFocusPolicy(Qt::StrongFocus);
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
               QPixmap pixmap(":/neutralcity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
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
        if(unites[i].getType()==1998 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osinfantry.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);

        }
        else if(unites[i].getType()==1998 && unites[i].getTeam()==2){
            QPixmap pixmap(":/blue.png");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);

        }

    }

}

void Map::mousePressEvent(QMouseEvent *e)
{

    if(e->buttons() == Qt::LeftButton){
        Game& game=Game::Instance();
        float x=floorf(e->x()/40);
        float y=floorf(e->y()/40);
        int z= (int)x-5;
        int e= (int)y;
        if (gameobject[z][e].getType() == 4){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }

        else if (gameobject[z][e].getType() == 5){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 6){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 7){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 8){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 9){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 10){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 11){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 12){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 13){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 14){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 28){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 29){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 30){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 31){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 32){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 33){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 101){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 102){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 103){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 104){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 105){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 106){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 107){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 108){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 109){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }
        else if (gameobject[z][e].getType() == 110){
            std::cout<< "Tu peux pas marcher sur l'eau"<< std::endl;
        }






        else{
         game.move(z,e);
        }

    }

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


void Map::redraw()
{
    this->repaint();
}



