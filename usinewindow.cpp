#include "usinewindow.h"
#include "mainwindow.h"
#include "ui_usinewindow.h"
#include "game.h"
UsineWindow::UsineWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsineWindow)
{
    ui->setupUi(this);

    Game& game=Game::Instance();
    if(game.getTurn()==1){
    QPixmap pix(":/osinfantry.gif");
    ui->label->setPixmap(pix.scaled(50,50));}
    else{
        QPixmap pix(":/blue.png");
        ui->label->setPixmap(pix.scaled(50,50));
    }

}

UsineWindow::~UsineWindow()
{
    delete ui;
}

void UsineWindow::on_pushButton_clicked()
{
    Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn());

}

int UsineWindow::getY() const
{
    return y;
}

void UsineWindow::setY(int value)
{
    y = value;
}

int UsineWindow::getX() const
{
    return x;
}

void UsineWindow::setX(int value)
{
    x = value;
}
