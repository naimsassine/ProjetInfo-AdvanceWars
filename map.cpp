#include "map.h"
#include "game.h"
#include <QPainter>
#include <iostream>
#include <QMouseEvent>
Map::Map(QWidget *parent ) : QWidget(parent)
{

}

void Map::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=0 ;i<21;i++){
        int c=i+5;
        for (int j=0; j <21 ;j++){

           painter.drawRect(c*40,j*40,38,38);
           if(gameobject[i][j].getType() == 1){
           painter.fillRect(c*40,j*40,38,38,Qt::cyan);}
           else{
           painter.fillRect(c*40,j*40,38,38,Qt::red);}
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
        for (int j=0; j <21 ;j++){
            gameobject[i][j]=game.getgameobject(i,j);
        }}

}

void Map::redraw()
{
    this->repaint();
}
