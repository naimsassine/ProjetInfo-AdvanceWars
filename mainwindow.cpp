#include "mainwindow.h"
#include "Gameobject.h"
#include "game.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    map = new Map(this);
    MainWindow::setCentralWidget(map);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete map;
}


void MainWindow::redraw()
{   map->setgameobject();
    map->redraw();
}
