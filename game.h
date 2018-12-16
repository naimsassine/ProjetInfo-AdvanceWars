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
    Gameobject & getgameobject(int x,int y) ;
    std::vector<Unites> getUnites() const;
    void endtour();
    int getTurn() const;
    void setTurn(int value);
    void createUnite(int x, int y, int team ,int type);
    void attack(int z, int e ,int  i,int je);
   // void fusion(int z, int e, Unites u1, Unites u2);
    void fusion( int v, int w);
    void capture(int z,int e);
    void capture_Usine(int z, int e);
    void capture_Aeroport(int z, int e);
    Player *getPlayer() const;
    void moveable(int move ,int x, int y,int typeu);
    void getcaptured() const;
    void setcaptured() const;
    void pathfinddijkstra(Unites &unit);
    std::vector<Aeroport> getAeroport() const;
    std::vector<Usine> getUsine() const;
    std::vector<Ville> getVille() const;
    void affichage();
    bool samePos() const;
    bool getUnitincity() const;
    void setUnitincity(bool value);
    void setComptattack();
    void setComptcapture();
    void setComptfusion();
    void setComptproduction(int x,int y);
    void setComptaeroport(int x,int y);
    bool getEndGame() const;
    void setEndGame(bool value) ;
    static Game& newGame();
    void dijkstra(Unites &blue);

    Ville *getActville() const;
    void setActville(int i);

    Unites *getActvie() const;
    void setActvie(int i );

    MainWindow *getWindow() const;

    int getPosXselec() const;
    int getMoveSend(int a);
    int getCaptureSend(int a);
    int getCreateunit(int a);
    int getattackjs(int a);
    int getfusionjs(int a);
    void changeposu(int i ,int newx ,int newy);
    void setcaptureonline(int type,int i ,int capturepoint ,int team);
    void theendgame();

private:
    Game();
    std::vector<Usine> usine;
    std::vector<Unites> unites;
    std::vector<Aeroport> aeroport;
    std::vector<Ville> ville;
    std::vector<Terrain> terrain;
    int movesend[4];
    int z=0;
    int e=0;
    Unites *actvie;
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
    bool isEndGame = false;
    bool unitincity=false;
    bool same = false;
    int capturesend[4];
    int creationunit[4];
    int attackjs[4];
    int fusionjs[2];
    static int compteurfin1;
    static int compteurfin2;
    static bool compteurpathfind;
    void pathfinding(Gameobject end, Unites &unite, bool compt);
    double calculdistance(Gameobject s1, Gameobject s2);
    void greedy(Unites &unit);
};
#endif // GAME_H
