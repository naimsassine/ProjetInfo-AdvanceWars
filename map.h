#ifndef MAP_H
#define MAP_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QWidget>
#include"Gameobject.h"
#include <QString>
#include <QKeyEvent>
#include "case.h"
class Map : public QWidget{
    Q_OBJECT
public:

    explicit Map(QWidget *parent = 0) ;
    ~Map();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *keyEvent);
    void setgameobject();
    void ablatif();

    void redraw();
private slots:
    void captureville();
    void captureusine();
    void captureaeroport();
    void attackunite();
    void fusionunite();

private:
    Gameobject gameobject[22][18];
    QString filename;
    QAction *capture;
    QAction *wait;
    QAction *attack;
    QAction *fusion;
    Case  *casee;
    int z;
    int e;
    int v;
    int w;
    int type;
    int unitpos;


};
#endif // MAP_H

