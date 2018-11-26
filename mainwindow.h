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
#include <QLabel>
#include "Unites.h"
#include "Ville.h";
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
    void changeVieWindow(Unites unite);
    void changeCaptWindow(Ville ville);
    void synchro(Unites unite);
   // void dessin(QLabel *p, char c, int x, int y);

private slots:
void changeturn();
//void changeMoneyWindow();//

private:
    Ui::MainWindow *ui;
    Map *map;
    QPushButton *bouton;
    QLabel *labC1;
    QLabel *lab;
    QLabel *lab1;
    QLabel *lab2;
    QLabel *lab3;
    QLabel *lab4;
    QLabel *lab5;
    QLabel *lab6;
    QLabel *lab10;

    QLabel *don;
    QLabel *don1;
    QLabel *don2;

};

#endif // MAINWINDOW_H

