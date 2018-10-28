#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"
class Game{
public:
    static Game& Instance();
    void move(QMouseEvent *e);
    void InitGame(MainWindow &wind);
    Gameobject getgameobject(int x,int y);
private:
    Game();
    static Game gameinst;
    MainWindow *window;
    Gameobject gameobject[21][21];
    int posXselec=0;
    int posYselec=0;

    // NAim on te...//
};
#endif // GAME_H
