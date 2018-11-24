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
#include <string.h>
#include <iostream>

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

   lab4= new QLabel("Vie : ",this);
   lab4->setGeometry(60, 50, 180, 70);
   QFont f3( "Arial", 16);
   lab4->setFont( f3);
   lab4->move(0, 150);
   lab4->show();
   lab5= new QLabel("0",this);
   lab5->setGeometry(60, 50, 180, 70);
   lab5->setFont(f3);
   lab5->move(100, 150);
   lab5->show();



}

MainWindow::~MainWindow()
{   delete bouton;
    delete lab;
    delete lab2;
    delete lab3;
    delete lab4;
    delete lab5;
    delete don;
    delete don1;
    delete don2;
    delete ui;
    delete map;
}

void MainWindow::InitMap()
{
    map->setgameobject();
}


void MainWindow::redraw()
{   Game& game=Game::Instance();
    lab3->setText(QString::number(game.getPlayer()->getMoney()));
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


void MainWindow::changeVieWindow(Unites unite)
{
    Game& game=Game::Instance();
    int a = unite.getvie();
    lab5->setNum(a);

}

void MainWindow::synchro(Unites unite)
{
    Game& game = Game::Instance();
    int vie= unite.getvie();
    if(unite.getType() == 1998){
        

        lab10= new QLabel("Point de vie infanterie : /vie",this);
        lab10->setGeometry(60, 50, 180, 70);
        QFont f10( "Arial", 16);
        lab10->setFont( f10);
        lab10->move(1200, 100);
        lab10->show();}


}
/*void MainWindow::dessin(QLabel *p,char c, int x, int y){
    p = NULL;
    p= new QLabel(char c, this);
}*/






