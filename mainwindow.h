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
#include "Ville.h";
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

    void mousePressEvent(QMouseEvent *e);

    void synchro(Unites unite);
   // void dessin(QLabel *p, char c, int x, int y);

    Map *getMap() const;

private slots:
    void changeturn();
//void changeMoneyWindow();//

private:
    Ui::MainWindow *ui = nullptr;
    Map *map = nullptr;
    QPushButton *bouton = nullptr;
    QLabel *labC1 = nullptr;
    QLabel *labT1 = nullptr;
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


};

#endif // MAINWINDOW_H

