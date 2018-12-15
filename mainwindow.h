#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMouseEvent>
#include <QApplication>
#include <QWidget>
#include <QFont>
#include <QIcon>
#include <QPushButton>
#include <QMainWindow>
#include"Gameobject.h"
#include "map.h"
#include "Gameobject.h"
#include <QLabel>
#include "Unites.h"
#include "Usine.h"
#include "Aeroport.h"
#include "Ville.h"
#include "QtNetwork"
#include "Terrain.h"
class Gameobject;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    void InitMap();
    void redraw();
    void changeVieWindow(Unites& unite);
    void changeCaptWindow(Ville& ville);
    void changeCaptWindow(Usine& usine);
    void changeCaptWindow(Aeroport& aeroport);
    void changeDefWindow(Terrain& terrain);
    void changeDefWindow(Gameobject& gameobject);
    void changeDammageWindow(Unites& unite);
    void unitmoved();
    void unitcaptured();
    void createunit();
    void attack();
    void fusion();

    void mousePressEvent(QMouseEvent *e);

    void synchro(Unites unite);
   // void dessin(QLabel *p, char c, int x, int y);

    Map *getMap() const;
    void online();
    void setMyTurn(bool value);
    bool getLocal() const;
    bool getMyTurn() const;
    void IA();
    void setisIA(bool value);
    bool getisIA();

private slots:
    void changeturn();
    void onNewConnection();
    void onConnected();
    void onData();
    void onDisconnected();
//void changeMoneyWindow();//
private:
    void sendJson(QJsonObject obj);
private:
    Ui::MainWindow *ui = nullptr;
    Map *map = nullptr;
    QPushButton *bouton = nullptr;
    QLabel *labC1 = nullptr;
    QLabel *labT1 = nullptr;
    QLabel *labD1 = nullptr;
    QLabel *labD = nullptr;
    QLabel *lab = nullptr;
    QLabel *lab1 = nullptr;
    QLabel *lab2 = nullptr;
    QLabel *lab3 = nullptr;
    QLabel *lab4 = nullptr;
    QLabel *lab5 = nullptr;
    QLabel *lab6 = nullptr;
    QLabel *lab7 = nullptr;
    QLabel *lab10 = nullptr;
    QLabel *don = nullptr;
    QLabel *don1 = nullptr;
    QLabel *don2 = nullptr;
    int typet= 0;
    quint32 currentSize = 0;
    bool isConfigured = false;
    int posX = 100, posY = 150;
    bool myTurn = false;
    bool local=true;
    QTcpServer* server = nullptr;
    QTcpSocket* other = nullptr;
    bool isIA = false;



};

#endif // MAINWINDOW_H

