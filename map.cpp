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
#include "Usine.h"
#include "usinewindow.h"
#include "case.h"
#include "aerwindow.h"
Map::Map(QWidget *parent ) : QWidget(parent)
{

Case cas;
casee=cas;
casee.setPosX(0);
casee.setPosY(0);
z=0;
e=0;
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
        Game& game=Game::Instance();
        std::vector<Unites> unite =game.getUnites();
        for(std::vector<Unites>::size_type h = 0; h != unite.size(); h++){
        for (int j=0; j <17 ;j++){


           if(gameobject[i][j].getType() == 1 ){
                  QPixmap pixmap(":/plain.gif");
                  painter.drawPixmap(c*40,j*40,40,40,pixmap);
                  if(gameobject[i][j].getMovable()){
                                 QPixmap pixmap(":/Misc.png");
                                 painter.drawPixmap(c*40,j*40,40,40,pixmap);
                             }

           }


           else if(gameobject[i][j].getType() == 2){
               QPixmap pixmap1(":/plain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap1);
               QPixmap pixmap(":/mountain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(( (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())) && unite[h].getTeam() == turn){
                    painter.drawPixmap(50,350,40,40,pixmap);}
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 3){
               QPixmap pixmap(":/wood.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 4){
               QPixmap pixmap(":/hriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 5){
               QPixmap pixmap(":/vriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 6){
               QPixmap pixmap(":/criver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 7){
               QPixmap pixmap(":/esriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 8){
               QPixmap pixmap(":/swriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);

                          }
           }
           else if(gameobject[i][j].getType() == 9){
               QPixmap pixmap(":/wnriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 104){
               QPixmap pixmap(":/espipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 102){
               QPixmap pixmap(":/hpipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 108){
               QPixmap pixmap(":/epipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 18){
               QPixmap pixmap(":/esroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 15){
               QPixmap pixmap(":/hroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }

           else if(gameobject[i][j].getType() == 30){
               QPixmap pixmap(":/hshoal.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 33){
               QPixmap pixmap(":/reef.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
                       if(gameobject[i][j].getMovable()){
                                      QPixmap pixmap(":/Misc.png");
                                      painter.drawPixmap(c*40,j*40,40,40,pixmap);
                                  }
           }
           else if(gameobject[i][j].getType() == 19){
               QPixmap pixmap(":/swroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 106){
               QPixmap pixmap(":/wnpipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 24){
               QPixmap pixmap(":/wneroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 22){
               QPixmap pixmap(":/eswroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 101){
               QPixmap pixmap(":/vpipe.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 125){
               QPixmap pixmap(":/jadesunhq.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 34){
               QPixmap pixmap1(":/plain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap1);
               if(gameobject[i][j].getTeam()==0){
               QPixmap pixmap(":/neutralcity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }}
               if(gameobject[i][j].getTeam()==1){
               QPixmap pixmap(":/orangestarcity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }}
               if(gameobject[i][j].getTeam()==2){
               QPixmap pixmap(":/bluemooncity.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }}
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 35){
               QPixmap pixmap1(":/plain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap1);
               if(gameobject[i][j].getTeam()==0){
               QPixmap pixmap(":/neutralbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }}
               if(gameobject[i][j].getTeam()==1){
               QPixmap pixmap(":/orangestarbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }
               }
               if(gameobject[i][j].getTeam()==2){
               QPixmap pixmap(":/bluemoonbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }

               }


               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 36){
               if(gameobject[i][j].getTeam()==0){
               QPixmap pixmap(":/neutralairport.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }}
               if(gameobject[i][j].getTeam()==1){
               QPixmap pixmap(":/orangestarairport.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }
               }
               if(gameobject[i][j].getTeam()==2){
               QPixmap pixmap(":/bluemoonairport.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }
               }

               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 109){
               QPixmap pixmap(":/spipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 39){
               QPixmap pixmap(":/orangestarbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                              }
           }
           else if(gameobject[i][j].getType() == 44){
               QPixmap pixmap(":/bluemoonbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }
               if(gameobject[i][j].getMovable()){
                               QPixmap pixmap(":/Misc.png");
                               painter.drawPixmap(c*40,j*40,40,40,pixmap);
                              }
           }
           else if(gameobject[i][j].getType() == 123){
               QPixmap pixmap(":/jadesunbase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if((gameobject[i][j].getSelected()==true)  || (unite[h].getPosX() == gameobject[i][j].getPosX() && unite[h].getPosY() == gameobject[i][j].getPosY())){
                    painter.drawPixmap(50,250,40,40,pixmap);

               }
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 23){
               QPixmap pixmap(":/swnroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 21){
               QPixmap pixmap(":/neroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 16){
               QPixmap pixmap(":/vroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 26){
               QPixmap pixmap(":/hbridge.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 29){
               QPixmap pixmap(":/hshoal.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 20){
               QPixmap pixmap(":/wnroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 110){
               QPixmap pixmap(":/wpipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }

           else if(gameobject[i][j].getType() == 95){
               QPixmap pixmap(":/blackholehq.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 92){
               QPixmap pixmap(":/blackholebase.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 25){
               QPixmap pixmap(":/nesroad.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 10){
               QPixmap pixmap(":/neriver.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
           }
           else if(gameobject[i][j].getType() == 107){
               QPixmap pixmap(":/npipeend.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
               if(gameobject[i][j].getMovable()){
                              QPixmap pixmap(":/Misc.png");
                              painter.drawPixmap(c*40,j*40,40,40,pixmap);
                          }
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
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);

            }

        }
        else if(unites[i].getType()==1998 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bminfantry.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3001 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osanti-air.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3001 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmanti-air.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2003 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osmech.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2003 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmmech.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3000 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osrecon.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3000 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmrecon.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3002 && unites[i].getTeam()==1){
            QPixmap pixmap(":/ostank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3002 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmtank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3003 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osmd.tank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3003 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmmd.tank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3004 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osmegatank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3004 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmmegatank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75 ,115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3005 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osneotank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==3005 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmneotank.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2000 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osb-copter.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2000 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmb-copter.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2002 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osfighter.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2002 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmfighter.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2001 && unites[i].getTeam()==1){
            QPixmap pixmap(":/osbomber.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }

        }
        else if(unites[i].getType()==2001 && unites[i].getTeam()==2){
            QPixmap pixmap(":/bmbomber.gif");
            painter.drawPixmap((unites[i].getPosX()+5)*40,unites[i].getPosY()*40,40,40,pixmap);
            if(unites[i].getSelected()==true){
                painter.drawPixmap(75, 115, 40,40, pixmap);
            }


        }

    }
    painter.drawRoundRect((casee.getPosX()+5)*40,casee.getPosY()*40,40,40,5,5);

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
    game.setComptcapture();

}

void Map::fusionunite()
{
    Game& game = Game::Instance();
    game.fusion(unitpos,game.getPosXselec());
    game.setComptfusion();
}

void Map::captureusine()
{
    Game& game= Game::Instance();
    game.capture_Usine(z,e);
    game.setComptcapture();
}
void Map::captureaeroport()
{
    Game& game= Game::Instance();
    game.capture_Aeroport(z,e);
    game.setComptcapture();
}
void Map::attackunite()
{
    Game& game=Game::Instance();
    game.attack(z,e,unitpos,game.getPosXselec());
    game.setComptattack();
}


void Map::mousePress(int x ,int y , QMouseEvent *ev)
{

            gameobject[z][e].setSelected(false); // apelé ici, donc je suspecte que z ou e soit hors borne
             // fonction deja implementé //
            z= (int)x-5;
            e= (int)y;

            casee.setPosX(z);
            casee.setPosY(e);
            if(ev->buttons() == Qt::LeftButton){
                Game& game=Game::Instance();
                game.setActville(nullptr);
                 game.move(z,e);

                if(gameobject[z][e].getType()==34 ){
                    gameobject[z][e].setSelected(true);
                    std::vector<Ville> ville =game.getVille();
                    for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){
                        if(ville[i].getPosX()==z &&ville[i].getPosY()==e) {
                            game.setActville(&ville[i]);
                        }}
                    game.getWindow()->redraw();
                }
                game.setActvie(nullptr);
                std::vector<Unites> unites =game.getUnites();
                for(std::vector<Unites>::size_type i = 0; i != unites.size(); i++){

                    if(unites[i].getPosX()==z && unites[i].getPosY()==e){
                        game.setActvie(&unites[i]);

                        game.getWindow()->redraw();
                    }}
            }

            else if(ev->buttons() == Qt::RightButton){
               Game& game=Game::Instance();

                if ( gameobject[z][e].getType() == 35  && gameobject[z][e].getTeam() == game.getTurn() ){
                    std::vector<Usine> usine = game.getUsine();
                    for(Usine& u : usine){
                        if(u.getPosX()==z && u.getPosY()==e && u.getTeam() ==game.getTurn() && u.getComptproduction()){
                            UsineWindow w;

                            w.setX(z);
                            w.setY(e);
                            w.exec();
                        }
                    }
                }
                if ( gameobject[z][e].getType() == 36 && gameobject[z][e].getTeam() == game.getTurn() ){
                    std::vector<Aeroport> aeroport = game.getAeroport();
                    for(Aeroport& u : aeroport){
                        if(u.getPosX()==z && u.getPosY()==e && u.getTeam() ==game.getTurn() && u.getComptproduction()){
                            AerWindow w;

                            w.setX(z);
                            w.setY(e);
                            w.exec();

                        }
                    }

                }
                 if (gameobject[z][e].getType() == 34){
                    Game& game=Game::Instance();
                    std::vector<Ville> ville =game.getVille();
                    std::vector<Unites> unite =game.getUnites();
                    if(unite[game.getPosXselec()].getComptcapture()){
                    for(std::vector<Ville>::size_type i = 0; i != ville.size(); i++){


                        if(ville[i].getPosX()==unite[game.getPosXselec()].getPosX()&& unite[game.getPosXselec()].getTeam()!=ville[i].getTeam() &&ville[i].getPosY()==unite[game.getPosXselec()].getPosY() && ville[i].getUnitin() && unite[game.getPosXselec()].getTeam()==game.getTurn()  ){

                            QMenu menu(this);

                            capture =new QAction("Capture", this);
                            menu.addAction(capture);
                            wait =new QAction("Wait", this);
                            menu.addAction(wait);
                            QObject::connect(capture, SIGNAL(triggered()), this, SLOT(captureville()));

                            // Place the menu in the right position and show it.
                            menu.exec(ev->globalPos());
                           }
                    }}

                }
                if(gameobject[z][e].getType()== 35){
                    Game& game = Game::Instance();
                    std::vector<Usine> usine = game.getUsine();
                    std::vector<Unites> unite =game.getUnites();
                    if(unite[game.getPosXselec()].getComptcapture()){
                    for(std::vector<Usine>::size_type i = 0; i!= usine.size(); i++){
                        if(usine[i].getPosX()==unite[game.getPosXselec()].getPosX() &&usine[i].getPosY()==unite[game.getPosXselec()].getPosY() && usine[i].getUnitin() && unite[game.getPosXselec()].getTeam()!=usine[i].getTeam() && unite[game.getPosXselec()].getTeam()==game.getTurn() ){
                            QMenu menu(this);
                            capture =new QAction("Capture", this);
                            menu.addAction(capture);
                            wait =new QAction("Wait", this);
                            menu.addAction(wait);
                            QObject::connect(capture, SIGNAL(triggered()), this, SLOT(captureusine()));

                            // Place the menu in the right position and show it.
                            menu.exec(ev->globalPos());
                           }

                    }
                    }
                }

                if(gameobject[z][e].getType()== 36){
                    Game& game = Game::Instance();
                    std::vector<Aeroport> aeroport = game.getAeroport();
                    std::vector<Unites> unite =game.getUnites();
                    if(unite[game.getPosXselec()].getComptcapture()){
                    for(std::vector<Aeroport>::size_type i = 0; i!= aeroport.size(); i++){
                        if(aeroport[i].getPosX()==unite[game.getPosXselec()].getPosX() &&aeroport[i].getPosY()==unite[game.getPosXselec()].getPosY() && unite[game.getPosXselec()].getTeam()!=aeroport[i].getTeam()&& aeroport[i].getUnitin() && unite[game.getPosXselec()].getTeam()==game.getTurn() ){
                            QMenu menu(this);
                            capture =new QAction("Capture", this);
                            menu.addAction(capture);
                            wait =new QAction("Wait", this);
                            menu.addAction(wait);
                            QObject::connect(capture, SIGNAL(triggered()), this, SLOT(captureaeroport()));

                            // Place the menu in the right position and show it.
                            menu.exec(ev->globalPos());

                        }
                    }}

                }




                    std::vector<Unites> unite =game.getUnites();
                    for(std::vector<Unites>::size_type i = 0; i != unite.size(); i++){
                        game.setActvie(nullptr);


                        if(unite[game.getPosXselec()].getComptattack()&& unite[game.getPosXselec()].getTeam()==game.getTurn()){

                        if(unite[i].getPosX()==z &&unite[i].getPosY()==e && unite[i].getUnitin() && unite[i].getTeam()!=game.getTurn()){
                            game.setActvie(&unite[i]);
                            QMenu menu(this);
                            attack =new QAction("Attaquer", this);
                            menu.addAction(attack);
                            wait =new QAction("Wait", this);
                            menu.addAction(wait);
                            unitpos=i;
                            QObject::connect(attack, SIGNAL(triggered()), this, SLOT(attackunite()));

                            // Place the menu in the right position and show it.
                            menu.exec(ev->globalPos());
                        }
                    }
                        if(unite[game.getPosXselec()].getComptfusion()){
                            //std::cout<<unite[game.getPosXselec()].getUnitin()<<std::endl;
                        if(unite[i].getPosX()==z  &&unite[i].getPosY()==e && unite[i].getUnitin() && unite[i].getTeam()==game.getTurn() && unite[game.getPosXselec()].getTeam() == game.getTurn() &&  i != game.getPosXselec() )
                                //unite[i].getPosX() == z && unite[i].getType()==unite[game.getPosXselec()].getType()
                                //&& unite[i].getPosY()==e && unite[game.getPosXselec()].getUnitin()
                              //  && unite[i].getTeam() == game.getTurn() && unite[game.getPosXselec()].getTeam() == game.getTurn() && unite[i].getUnitin() )
                        {
                            QMenu menu(this);
                            fusion = new QAction("Fusion", this);
                            menu.addAction(fusion);
                            type = unite[i].getType();
                            wait = new QAction("Wait", this);
                            menu.addAction(wait);
                            unitpos = i ;
                            QObject::connect(fusion, SIGNAL(triggered()), this, SLOT(fusionunite()));
                            menu.exec(ev->globalPos());
                        }
                    }}
}

            }



void Map::keyPressEvent(QKeyEvent *keyEvent)
{
    Game& game=Game::Instance();
        switch (keyEvent->key()) {
        case Qt::Key_Down:

            casee.setPosY(casee.getPosY()+1);
            break;
        case Qt::Key_Left:
            casee.setPosX(casee.getPosX()-1);
            break;
        case Qt::Key_Right:
            casee.setPosX(casee.getPosX()+1);
            break;
        case Qt::Key_Up:
            casee.setPosY(casee.getPosY()-1);
            break;
        case Qt::Key_Enter:

            if(gameobject[casee.getPosX()][casee.getPosY()].getSelected()){
            game.move(casee.getPosX(),casee.getPosY());}
            else{
                gameobject[casee.getPosX()][casee.getPosY()].setSelected(true);
            }
        default:
            break;
        }
        redraw();
}

void Map::ablatif(){


}
void Map::setgameobject()
{   Game& game=Game::Instance();
    for(int i=0 ;i<21;i++){
        for (int j=0; j <17 ;j++){
            gameobject[i][j]=game.getgameobject(i,j);
        }}}
