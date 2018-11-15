#include "mainwindow.h"
#include "Gameobject.h"
#include "game.h"
#include <string.h>
#include"bouton.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QPainter>
#include <iostream>
#include <QDockWidget>
#include <QCoreApplication>
#include <QSizePolicy>
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    map = new Map(this);
    MainWindow::setCentralWidget(map);
    /*QSize size(1040,600);
    this->setFixedSize(size);*/
 //Gestions des boutons sur la map//




   bouton = new QPushButton("End Turn !", this);
      bouton->setGeometry(60, 50, 180, 70);
      bouton->move(10, 520);
   QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(changeturn()));
   bouton->show();
   lab = new QLabel("Player 1 ",this);
   lab->setGeometry(60, 50, 180, 70);
   QFont f( "Arial", 20, QFont::Bold);
   lab->setFont( f);
   lab->move(50, 50);
   lab->show();
   lab2= new QLabel("Money : ",this);
   lab2->setGeometry(60, 50, 180, 70);
   QFont f2( "Arial", 16);
   lab2->setFont( f2);
   lab2->move(0, 100);
   lab2->show();
   lab3= new QLabel("1000",this);
   lab3->setGeometry(60, 50, 180, 70);

   lab3->setFont( f2);
   lab3->move(100, 100);
   lab3->show();

}

MainWindow::~MainWindow()
{   delete bouton;
    delete lab;
    delete lab2;
    delete lab3;
    delete ui;
    delete map;
}

void MainWindow::InitMap()
{
    map->setgameobject();
}


void MainWindow::redraw()
{
   map->setgameobject();
    map->redraw();
}

void MainWindow::changeturn()
{
    Game& game=Game::Instance();
    game.endtour();
    if(game.getTurn()==1){
        lab->setText("Player 1");

    }
    else{
        lab->setText("Player 2");
    }
    Player *player=game.getPlayer();
    lab3->setText(QString::number(player->getMoney()));
}









