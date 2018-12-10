#include "aerwindow.h"
#include "ui_aerwindow.h"
#include "mainwindow.h"
#include "game.h"
AerWindow::AerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AerWindow)
{
    ui->setupUi(this);
    Game& game=Game::Instance();
    if(game.getTurn()==1){
    QPixmap pix8(":/osb-copter.gif");
    QPixmap pix9(":/osfighter.gif");
    QPixmap pix10(":/osbomber.gif");
    ui->label8->setPixmap(pix8.scaled(30,30));
    ui->label9->setPixmap(pix9.scaled(30,30));
    ui->label10->setPixmap(pix10.scaled(30,30));
    }
    else{
        QPixmap pix8(":/bmb-copter.gif");
        QPixmap pix9(":/bmfighter.gif");
        QPixmap pix10(":/bmbomber.gif");
        ui->label8->setPixmap(pix8.scaled(30,30));
        ui->label9->setPixmap(pix9.scaled(30,30));
        ui->label10->setPixmap(pix10.scaled(30,30));

    }
}

AerWindow::~AerWindow()
{
    delete ui;
}

void AerWindow::on_pushButton_9_clicked()
{
    Game& game=Game::Instance();
       if(comptachat){
           int c =game.getPlayer()->getMoney();
           if(c>=9000){
               game.getPlayer()->setMoney(game.getPlayer()->getMoney()-9000);
               game.createUnite(x,y,game.getTurn(),2000);
               game.setComptaeroport(x,y);
               comptachat=false;
           }
       }
}

void AerWindow::on_pushButton_10_clicked()
{
    Game& game=Game::Instance();
    if(comptachat){
        int c =game.getPlayer()->getMoney();
        if(c>=20000){
            game.getPlayer()->setMoney(game.getPlayer()->getMoney()-20000);
            game.createUnite(x,y,game.getTurn(),2002);
            game.setComptaeroport(x,y);
            comptachat =false;
        }
    }
}

void AerWindow::on_pushButton_11_clicked()
{
    Game& game=Game::Instance();
    if(comptachat){
        int c =game.getPlayer()->getMoney();
        if(c>=22000){
            game.getPlayer()->setMoney(game.getPlayer()->getMoney()-22000);
            game.createUnite(x,y,game.getTurn(),2001);
            game.setComptaeroport(x,y);
            comptachat=false;
        }
    }
}

int AerWindow::getY() const
{
    return y;
}

void AerWindow::setY(int value)
{
    y = value;
}

int AerWindow::getX() const
{
    return x;
}

void AerWindow::setX(int value)
{
    x = value;
}
