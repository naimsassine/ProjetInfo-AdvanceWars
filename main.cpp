#include "mainwindow.h"
#include"Gameobject.h"
#include "game.h"
#include <QApplication>
#include <QHBoxLayout>
#include "player.h"
#include "menu.h"
int main(int argc, char *argv[])
{    QApplication a(argc, argv);

    Menu menu;

    MainWindow w;
    Player player1(1000, 1);
    Player player2(1000, 2);
    Game& game = Game::Instance();
    game.InitGame(&w, &player1, &player2);  // je trouve ça plus clair
    menu.setWindow(&w);
    menu.show();


    return a.exec();

}
