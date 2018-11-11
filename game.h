#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"
#include "iostream"
#include "Unites.h"
#include "player.h"
#include "Ville.h"
#include "Infanterie.h"
class Game{
public:
    static Game& Instance();
    void move(int x,int y);
    void movearrow(int x,int y);
    void InitGame(MainWindow &wind,Player &InitPlayer1,Player &InitPlayer2);
    Gameobject getgameobject(int x,int y);
    std::vector<Unites> getUnites() const;
    void endtour();
    int getTurn() const;
    void setTurn(int value);
    void createUnite(int x, int y, int team);
    void attack(int z, int e ,int  i);
    void capture(int z,int e);
    Player *getPlayer() const;

    std::vector<Ville> getVille() const;

private:
    Game();
    std::vector<Unites> unites;
    std::vector<Ville> ville;
    static Game gameinst;
    MainWindow *window;
    Gameobject gameobject[22][18];
    Gameobject set;
    int posXselec=0;
    int posYselec=0;
    Player *player1;
    Player *player2;
    int turn=1;


    // NAim on te...//
};
#endif // GAME_H
