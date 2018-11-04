#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"
#include "iostream"
#include "Unites.h"
class Game{
public:
    static Game& Instance();
    void move(int x,int y);
    void movearrow(int x,int y);
    void InitGame(MainWindow &wind);
    Gameobject getgameobject(int x,int y);
<<<<<<< HEAD
    std::vector<Unites> getUnites() const;

=======
    void endtour();
>>>>>>> 46fb271351962e35fc44cd39e8a9ea9c8dad8590
private:
    Game();
    std::vector<Unites> unites;
    static Game gameinst;
    MainWindow *window;
    Gameobject gameobject[22][18];
    Gameobject set;
    int posXselec=0;
    int posYselec=0;

    // NAim on te...//
};
#endif // GAME_H
