#include "mainwindow.h"
#include "Gameobject.h"
#include "game.h"
#include "player.h"
#include <string.h>
#include"bouton.h"
#include "Usine.h"
#include "math.h"
#include "menu.h"
#include <QMessageBox>
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
#include <QApplication>
#include <QProcess>


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    map = new Map(this);
    MainWindow::setCentralWidget(map);
    /*QSize size(1040,600);
    this->setFixedSize(size);*/
    // Gestions des boutons sur la map//
    bouton = nullptr;
    labC1 = nullptr;
    labT1 = nullptr;
    lab = nullptr;
    lab1 = nullptr;
    lab2 = nullptr;
    lab3 = nullptr;
    lab4 = nullptr;
    lab5 = nullptr;
    lab6 = nullptr;
    lab7 = nullptr;
    lab10 = nullptr;
    don = nullptr;
    don1 = nullptr;
    don2 = nullptr;



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


   lab2 = new QLabel("Money : ",this);
   lab2->setGeometry(60, 50, 180, 70);
   QFont f2( "Arial", 16);
   lab2->setFont( f2);
   lab2->move(0, 200);
   lab2->show();


   lab3 = new QLabel("1000",this);
   lab3->setGeometry(60, 50, 180, 70);
   lab3->setFont( f2);
   lab3->move(100, 200);
   lab3->show();

   lab4 = new QLabel("Vie : ",this);
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

   lab6 = new QLabel("Point de capture : ", this);
   lab6->setGeometry(60, 50, 180, 70);
   QFont f6( "Arial", 16);
   lab6->setFont( f6);
   lab6->move(0, 300);
   lab6->show();
   labC1= new QLabel("20",this);
   labC1->setGeometry(60, 50, 180, 70);
   labC1->setFont(f6);
   labC1->move(170, 300);
   labC1->show();

   lab7 = new QLabel("Défense terrain : ", this);
   lab7->setGeometry(60, 50, 180, 70);
   QFont f7( "Arial", 16);
   lab7->setFont( f6);
   lab7->move(0, 400);
   lab6->show();
   labT1= new QLabel("0",this);
   labT1->setGeometry(60, 50, 180, 70);
   labT1->setFont(f7);
   labT1->move(170, 400);
   labT1->show();



}

void MainWindow::sendJson(QJsonObject obj) {
    QByteArray data = QJsonDocument(obj).toJson();
    QDataStream out(other);
    out << (quint32) data.length();
    other->write(data);

    std::cout << "Sending " << data.toStdString() << std::endl;
}

bool MainWindow::getIsIAfuture() const
{
    return isIAfuture;
}

void MainWindow::setIsIAfuture(bool value)
{
    isIAfuture = value;
}

bool MainWindow::getIsIAGreedy() const
{
    return isIAGreedy;
}

void MainWindow::setIsIAGreedy(bool value)
{
    isIAGreedy = value;
}

bool MainWindow::getMyTurn() const
{
    return myTurn;
}

void MainWindow::IAPath()
{
    this->setisIA(true);
}

void MainWindow::IAGreedy()
{
    this->setIsIAGreedy(true);
}

void MainWindow::IAfuture()
{
    this->setIsIAfuture(true);
}

void MainWindow::setisIA(bool value)
{
    isIAPath = value;
}

bool MainWindow::getisIA()
{
    return isIAPath;
}

bool MainWindow::getLocal() const
{
    return local;
}

void MainWindow::setMyTurn(bool value)
{
    myTurn = value;
}



void MainWindow::online()
{
    server = new QTcpServer();

    local=false;

    if(! server->listen(QHostAddress::Any, 8123)) {
        std::cout << "I am a client" << std::endl;
        other = new QTcpSocket();
        connect(other, SIGNAL(connected()), this, SLOT(onConnected()));

        other->connectToHost("127.0.0.1", 8123);
        connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    } else {
        std::cout << "I am the server" << std::endl;
        other = nullptr;


    }

    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void MainWindow::onNewConnection() {
    std::cout << "A new client is connecting !" << std::endl;
    other = server->nextPendingConnection();
    connect(other, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(other, SIGNAL(readyRead()), this, SLOT(onData()));

    QJsonObject info;
    posX = 0;
    posY = 0;
    info["x"] = posX;
    info["y"] = posY;

    isConfigured = true;
    myTurn = false;

    sendJson(info);
    update();
}

void MainWindow::onConnected() {
    std::cout << "I am connected" << std::endl;
    connect(other, SIGNAL(readyRead()), this, SLOT(onData()));
}

void MainWindow::onDisconnected() {
    std::cout << "The other guy just disconnected" << std::endl;
}

void MainWindow::onData() {
    std::cout << "Some data !" << std::endl;
    if(currentSize == 0) {
        if(other->bytesAvailable() < 4)
            return;

        QDataStream in(other);
        in >> currentSize;
    }

    if(other->bytesAvailable() < currentSize)
        return;

    QByteArray data = other->read(currentSize);
    std::cout << data.toStdString() << std::endl;
    currentSize = 0;

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    if(! isConfigured) {
        posX = json["x"].toInt();
        posY = json["y"].toInt();
        update();
        isConfigured = true;
        myTurn = true;
    }
    else {
        if(json["endtour"]==true){
            Game& game = Game::Instance();
            game.endtour();
            if (game.getTurn() == 1) {
                lab->setText("Player 1");
            }
            else {
                lab->setText("Player 2");
            }
            Player *player = game.getPlayer();
            lab3->setText(QString::number(player->getMoney()));
            myTurn=true;

        }
        int oldX = json["oldX"].toInt();
        int oldY = json["oldY"].toInt();
        int newX = json["newX"].toInt();
        int newY = json["newY"].toInt();

        if(oldX!=newX || oldY!=newY){
             Game& game = Game::Instance();
             std::vector<Unites> unite =game.getUnites();
             for(int unsigned j=0;j<unite.size();j++){
                 if(unite[j].getPosX()==oldX &&unite[j].getPosY()==oldY){
                     game.changeposu(j,newX,newY);

                 }
             }


        }
        if(json["building"]==0 ||json["building"]==1 || json["building"]==2){
            Game& game = Game::Instance();
            int type = json["building"].toInt();
            int i = json["i"].toInt();
            int s = json["capturepoint"].toInt();
            int r = json["team"].toInt();
            game.setcaptureonline(type,i,s,r);
        }

        if(json["action"].toString()=="construire"){
            Game& game = Game::Instance();
            int x = json["x"].toInt();
            int y = json["y"].toInt();
            int team = json["team"].toInt();
            int type = json["type"].toInt();
            game.createUnite(x,y,team,type);
        }
        if(json["action"].toString()=="attack"){
            Game& game = Game::Instance();
            int posx=json["posx"].toInt();
            int posy=json["posy"].toInt();
            int unit=json["unit"].toInt();
            int unit2=json["unit2"].toInt();
            game.attack(posx,posy,unit,unit2);
        }
        if(json["action"].toString()=="fusion"){
            Game& game = Game::Instance();
            int unit1=json["unit1"].toInt();
            int unit2=json["unit2"].toInt();
            game.fusion(unit1,unit2);

        }


        /* if(!(posX == oldX && posY == oldY)) {
            std::cerr << "ERROR" << std::endl;
            destroy();
            return;
        }*/

        posX = newX;
        posY = newY;
        update();
        redraw();
    }}

MainWindow::~MainWindow()
{   delete bouton;
    delete labC1;
    delete labT1;
    delete labD1;
    delete lab;
    delete lab1;
    delete lab2;
    delete lab3;
    delete lab4;
    delete lab5;
    delete lab6;
    delete lab7;
    delete lab10;
    delete ui;
    delete map;
    delete don;
    delete don1;
    delete don2;
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
    Ville *tville=game.getActville();
    if (tville != nullptr){
    labC1->setText(QString::number(tville->getCapturepoint()));
    }
    else{
        labC1->setText(" ");
    }
    Unites *tunite = game.getActvie();
    if(tunite != nullptr){
        lab5->setText(QString::number(tunite->getvie()));
    }
    else{
        lab5->setText(" ");
    }
    if(game.getEndGame()== true)
    {   QMessageBox msgBox;
        msgBox.setWindowTitle("Fin de partie !");
        msgBox.setText( "Voulez-vous recommencer une partie ?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        if(msgBox.exec() == QMessageBox::Yes){
            QProcess process;
            QApplication::quit();
            QProcess::startDetached(qApp->applicationFilePath(), QStringList());

        }else {
            QApplication::quit();
            this->close();
        }

        this->show();
    }
}

void MainWindow::changeturn()
{
    if(! myTurn && !local )
            return;
    if(!local){

    QJsonObject endtour;
    endtour["endtour"] = true;


    sendJson(endtour);
    update();
    myTurn = false;}
    Game& game = Game::Instance();
    game.endtour();
    if (game.getTurn() == 1) {
        lab->setText("Player 1");
    }
    else {
        lab->setText("Player 2");
    }
    Player *player = game.getPlayer();
    lab3->setText(QString::number(player->getMoney()));
}

Map *MainWindow::getMap() const
{
    return map;
}


void MainWindow::changeVieWindow(Unites& unite)  // copyyyyy
{
    Game& game=Game::Instance();
    int a = unite.getvie();
    lab5->setNum(a);

}

void MainWindow::changeCaptWindow(Ville& ville)  // copyyyyyyyy
{
    Game& game = Game::Instance();
    //if(ville.getSelected() == true){
        int b = ville.getCapturepoint();
        labC1->setNum(b);
    //}


}
void MainWindow::changeCaptWindow(Usine& usine)  // ocpyyyy
{
    Game& game = Game::Instance();
    int b = usine.getCapturepoint();
    labC1->setNum(b);

}
void MainWindow::changeCaptWindow(Aeroport& aeroport)  //copy (regarder la vidéo ssur l'héritage)
{
    Game& game = Game::Instance();
    int b = aeroport.getCapturepoint();
    labC1->setNum(b);

}


void MainWindow::unitmoved()
{
    Game& game = Game::Instance();
    QJsonObject move;
    move["oldX"] = game.getMoveSend(0);
    move["oldY"] = game.getMoveSend(1);
    move["newX"] = game.getMoveSend(2);
    move["newY"] = game.getMoveSend(3);
    sendJson(move);


}

void MainWindow::unitcaptured()
{
    Game& game = Game::Instance();
    QJsonObject capture;
    capture["building"] = game.getCaptureSend(0);
    capture["i"] = game.getCaptureSend(1);
    capture["capturepoint"] = game.getCaptureSend(2);
    capture["team"] = game.getCaptureSend(3);
    sendJson(capture);
}

void MainWindow::createunit()
{
    Game& game = Game::Instance();
    QJsonObject createunit;
    createunit["action"]= "construire";
    createunit["x"] = game.getCreateunit(0);
    createunit["y"] = game.getCreateunit(1);
    createunit["team"] = game.getCreateunit(2);
    createunit["type"] = game.getCreateunit(3);
    sendJson(createunit);
}

void MainWindow::attack()
{
    Game& game = Game::Instance();
    QJsonObject attack;
    attack["action"]="attack";
    attack["posx"] = game.getattackjs(0);
    attack["posy"] = game.getattackjs(1);
    attack["unit"] = game.getattackjs(2);
    attack["unit2"] = game.getattackjs(3);

    sendJson(attack);
}

void MainWindow::fusion()
{
    Game& game = Game::Instance();
    QJsonObject fusion;
    fusion["action"]="fusion";
    fusion["unit1"] = game.getfusionjs(0);
    fusion["unit2"] = game.getfusionjs(1);
    sendJson(fusion);
}

void MainWindow::changeDefWindow(Gameobject& gameobject)
{
    Game& game = Game::Instance();
    int c = gameobject.getdefTerrain(gameobject.getPosdef());
    labT1->setNum(c);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{   if(! myTurn && !local )
        return;
    int r=int(floorf(e->x()/40));
    int s=int(floorf(e->y()/40));
    if(r>= 5 && r<27 && s>=0 && s<18 ){
    map->mousePress(r,s ,e);
    redraw();
    }
    if(!local){
    int oldX = posX;
    int oldY = posY;
    posX = e->x();
    posY = e->y();

    QJsonObject move;
    move["oldX"] = oldX;
    move["oldY"] = oldY;
    move["newX"] = posX;
    move["newY"] = posY;


   }
}

void MainWindow::synchro(Unites unite)
{
   /* Game& game = Game::Instance();
    int vie= unite.getvie();
    if(unite.getType() == 1998){
        

        lab10 = new QLabel("Point de vie infanterie : /vie",this);
        lab10->setGeometry(60, 50, 180, 70);
        QFont f10( "Arial", 16);
        lab10->setFont( f10);
        lab10->move(1200, 100);
        lab10->show();}*/


}
/*void MainWindow::dessin(QLabel *p,char c, int x, int y){
    p = NULL;
    p= new QLabel(char c, this);
}*/






