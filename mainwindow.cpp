#include "mainwindow.h"
#include "Gameobject.h"
#include "game.h"
#include"bouton.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
#include <QDockWidget>
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    map = new Map(this);
    bouton = new Bouton(this);
    MainWindow::setCentralWidget(map);

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
