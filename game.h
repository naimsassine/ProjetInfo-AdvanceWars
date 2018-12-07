#ifndef GAME_H
#define GAME_H
#include "mainwindow.h"
#include "iostream"
#include "Unites.h"
#include "Usine.h"
#include "player.h"
#include "Aeroport.h"
#include "Ville.h"
#include "Infanterie.h"
class Game{
public:
    static Game& Instance();
    void move(int x,int y);
    void movearrow(int x,int y);
    void InitGame(MainWindow *wind,Player *InitPlayer1,Player *InitPlayer2);
    Gameobject const& getgameobject(int x,int y) const;
    std::vector<Unites> getUnites() const;
    void endtour();
    int getTurn() const;
    void setTurn(int value);
    void createUnite(int x, int y, int team ,int type);
    void attack(int z, int e ,int  i);
   // void fusion(int z, int e, Unites u1, Unites u2);
    void fusion(int z, int e, int type, int v, int w);
    void capture(int z,int e);
    void capture_Usine(int z, int e);
    void capture_Aeroport(int z, int e);
    Player *getPlayer() const;
    void moveable(int move ,int x, int y,int typeu);
    void getcaptured() const;
    void setcaptured() const;
    std::vector<Aeroport> getAeroport() const;
    std::vector<Usine> getUsine() const;
    std::vector<Ville> getVille() const;
    void affichage();
    bool samePos() const;
    bool getUnitincity() const;
    void setUnitincity(bool value);
    void setComptattack();
    void setComptcapture();

    Ville *getActville() const;

    void setActville(Ville *value);

    MainWindow *getWindow() const;

    int getPosXselec() const;

private:
    Game();
    std::vector<Usine> usine;
    std::vector<Unites> unites;
    std::vector<Aeroport> aeroport;
    std::vector<Ville> ville;
    std::vector<Terrain> terrain;
    int z=0;
    int e=0;
    Ville *actville;
    static Game gameinst;
    MainWindow *window = nullptr;
    Gameobject gameobject[22][18];
    Gameobject set;
    int posXselec=0;
    int posYselec=0;
    Player *player1;
    Player *player2;
    int turn=1;
    bool unitincity=false;
    bool same = false;


    // NAim on te...//
};
#endif // GAME_H
