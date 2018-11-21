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
    QPixmap pix1(":/osmech.gif");
    QPixmap pix2(":/osrecon.gif");
    QPixmap pix3(":/osanti-air.gif");
    QPixmap pix4(":/ostank.gif");
    QPixmap pix5(":/osmd.tank.gif");
    ui->label->setPixmap(pix.scaled(30,30));
    ui->label1->setPixmap(pix1.scaled(30,30));
    ui->label2->setPixmap(pix2.scaled(30,30));
    ui->label3->setPixmap(pix3.scaled(30,30));
    ui->label4->setPixmap(pix4.scaled(30,30));
    ui->label5->setPixmap(pix5.scaled(30,30));



    }
    else{
        QPixmap pix(":/bminfantry.gif");
        QPixmap pix1(":/bmmech.gif");
        QPixmap pix2(":/bmrecon.gif");
        QPixmap pix3(":/bmanti-air.gif");
        QPixmap pix4(":/bmtank.gif");
        QPixmap pix5(":/bmmd.tank.gif");
        ui->label->setPixmap(pix.scaled(30,30));
        ui->label1->setPixmap(pix1.scaled(30,30));
        ui->label2->setPixmap(pix2.scaled(30,30));
        ui->label3->setPixmap(pix3.scaled(30,30));
        ui->label4->setPixmap(pix4.scaled(30,30));
        ui->label5->setPixmap(pix5.scaled(30,30));
    }

}

UsineWindow::~UsineWindow()
{
    delete ui;
}

void UsineWindow::on_pushButton_clicked()
{
    Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),1998);

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

void UsineWindow::on_pushButton_2_clicked()
{
    Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),2003);
}

void UsineWindow::on_pushButton_3_clicked()
{
    Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),3000);

}

void UsineWindow::on_pushButton_5_clicked()
{
    Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),3002);
}

void UsineWindow::on_pushButton_6_clicked()
{
    Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),3003);
}

void UsineWindow::on_pushButton_4_clicked()
{ Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),3001);

}
