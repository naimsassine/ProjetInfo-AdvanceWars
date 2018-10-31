#include "map.h"
#include "game.h"
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
#include <QTextStream>

Map::Map(QWidget *parent ) : QWidget(parent)
{

}

void Map::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0 ;i<21;i++){
        int c=i+5;
        for (int j=0; j <17 ;j++){


           if(gameobject[i][j].getType() == 0){
                  QPixmap pixmap(":/plain.gif");
                  painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 1){
               QPixmap pixmap(":/plain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 2){
               QPixmap pixmap(":/sea.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else if(gameobject[i][j].getType() == 3){
               QPixmap pixmap(":/mountain.gif");
               painter.drawPixmap(c*40,j*40,40,40,pixmap);
           }
           else{
           painter.fillRect(c*40,j*40,40,40,Qt::red);}
        }
    }

}

void Map::mousePressEvent(QMouseEvent *e)
{

    if(e->buttons() == Qt::LeftButton){

        Game& game=Game::Instance();
        game.move(e);
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

void Map::readfile()
{    int c;
     QFile df(":/map.txt");

            if (!df.open(QIODevice::ReadOnly | QIODevice::Text)) {


            }

            QTextStream txStream(&df);

            while (!txStream.atEnd()) {

                QString text = txStream.readLine();
                QStringList s=text.split(",");
                for(int j =0 ;j<7 ;j++){
                c = s[j].toInt();

                }


            }

        df.close();
}

