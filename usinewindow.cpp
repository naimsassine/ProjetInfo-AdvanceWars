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
    QPixmap pix6(":/osmegatank.gif");
    QPixmap pix7(":/osneotank.gif");
    QPixmap pix8(":/osb-copter.gif");
    QPixmap pix9(":/osfighter.gif");
    QPixmap pix10(":/osbomber.gif");
    ui->label->setPixmap(pix.scaled(30,30));
    ui->label1->setPixmap(pix1.scaled(30,30));
    ui->label2->setPixmap(pix2.scaled(30,30));
    ui->label3->setPixmap(pix3.scaled(30,30));
    ui->label4->setPixmap(pix4.scaled(30,30));
    ui->label5->setPixmap(pix5.scaled(30,30));
    ui->label6->setPixmap(pix6.scaled(30,30));
    ui->label7->setPixmap(pix7.scaled(30,30));
    ui->label8->setPixmap(pix8.scaled(30,30));
    ui->label9->setPixmap(pix9.scaled(30,30));
    ui->label10->setPixmap(pix10.scaled(30,30));



    }
    else{
        QPixmap pix(":/bminfantry.gif");
        QPixmap pix1(":/bmmech.gif");
        QPixmap pix2(":/bmrecon.gif");
        QPixmap pix3(":/bmanti-air.gif");
        QPixmap pix4(":/bmtank.gif");
        QPixmap pix5(":/bmmd.tank.gif");
        QPixmap pix6(":/bmmegatank.gif");
        QPixmap pix7(":/bmneotank.gif");
        QPixmap pix8(":/bmb-copter.gif");
        QPixmap pix9(":/bmfighter.gif");
        QPixmap pix10(":/bmbomber.gif");
        ui->label->setPixmap(pix.scaled(30,30));
        ui->label1->setPixmap(pix1.scaled(30,30));
        ui->label2->setPixmap(pix2.scaled(30,30));
        ui->label3->setPixmap(pix3.scaled(30,30));
        ui->label4->setPixmap(pix4.scaled(30,30));
        ui->label5->setPixmap(pix5.scaled(30,30));
        ui->label6->setPixmap(pix6.scaled(30,30));
        ui->label7->setPixmap(pix7.scaled(30,30));
        ui->label8->setPixmap(pix8.scaled(30,30));
        ui->label9->setPixmap(pix9.scaled(30,30));
        ui->label10->setPixmap(pix10.scaled(30,30));
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

void UsineWindow::on_pushButton_7_clicked()
{
    Game& game=Game::Instance();
        game.createUnite(x+1,y,game.getTurn(),3004);
}

void UsineWindow::on_pushButton_8_clicked()
{
    Game& game=Game::Instance();
        game.createUnite(x+1,y,game.getTurn(),3005);
}

void UsineWindow::on_pushButton_9_clicked()
{Game& game=Game::Instance();
    game.createUnite(x+1,y,game.getTurn(),2000);

}

void UsineWindow::on_pushButton_10_clicked()
{
    Game& game=Game::Instance();
        game.createUnite(x+1,y,game.getTurn(),2002);
}

void UsineWindow::on_pushButton_11_clicked()
{
    Game& game=Game::Instance();
        game.createUnite(x+1,y,game.getTurn(),2001);
}
