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
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    map = new Map(this);
    MainWindow::setCentralWidget(map);

 //Gestions des boutons sur la map//


   bouton = new QPushButton("Quitter !", this);
   bouton->setGeometry(60, 50, 180, 70);
   bouton->move(1200, 50);
   QObject::connect(bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
   bouton->show();





}

MainWindow::~MainWindow()
{
    delete ui;
    delete map;
}

void MainWindow::InitMap()
{
    map->setgameobject();
}


void MainWindow::redraw()
{

    map->redraw();
}

void MainWindow::on_pushButton_clicked()
{
    Game& game=Game::Instance();
    game.endtour();
}







