#include "mainwindow.h"
#include "Gameobject.h"
#include <QtWidgets>
#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{   Gameobject Play(5,10,2);


    QApplication a(argc, argv);
    MainWindow w;
    w.setgameobject(Play);
    w.show();
    int x = 5;
    return a.exec();

}
