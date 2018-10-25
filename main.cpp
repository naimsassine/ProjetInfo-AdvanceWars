#include "mainwindow.h"
#include"Gameobject.h"
#include "game.h"
#include <QApplication>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    Game& game=Game::Instance();
    game.InitGame(w);
    w.show();


    return a.exec();

}
