#ifndef MAP_H
#define MAP_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QWidget>
#include"Gameobject.h"
#include <QString>
#include <QKeyEvent>
class Map : public QWidget{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = 0) ;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *keyEvent);
    void setgameobject();
    void redraw();

private:
    Gameobject gameobject[22][18];
    QString filename;

};
#endif // MAP_H

