#ifndef UNITES_H
#define UNITES_H
#include "Gameobject.h"
//#include "Infanterie.h"

class Unites : public Gameobject{
public:
    Unites();
    void attack();
    void attend();
    void fusion();
    int getvie();
    void setvie(int value);
    int getdamage();
    int getnumero();
    void initvie();
    int getTeam() const;
    void setTeam(int value);
    void setDamage(Unites,Unites,int defterrainb);
    bool getUnitin() const;
    void setUnitin(bool value);



    int getPtdeplacement() const;
    void setPtdeplacement(int value);

    int getPrix() const;
    void setPrix(int value);

    int getTypeu() const;

    bool getComptattack() const;
    void setComptattack(bool value);

    bool getComptcapture() const;
    void setComptcapture(bool value);

    bool getComptmouvement() const;
    void setComptmouvement(bool value);

    bool getComptfusion() const;

    void setComptfusion(bool value);

    int getPosBin() const;

protected:
    int vie;
    int prix;
    int ptattack;
    int ptdefense;
    int defterrain;
    int ptdeplacement = 3;
    int typeu;
    int B;
    int damage =0;
    int numero;
    int Team;
    int posBin;
    bool unity =false;
    bool comptattack = true;
    bool comptcapture = true;
    bool comptmouvement = true;
    bool comptfusion = true;
    int Bin[11][11]={{55,45,12,5,5,1,1,1,7,0,0},{65,55,85,65,55,15,5,15,9,0,0},{70,65,35,4,6,1,1,1,12,0,0},{105,105,60,45,25,10,1,5,120,65,75},{75,70,85,65,55,15,10,15,10,0,0},{105,95,105,105,85,55,25,45,12,0,0},{135,125,195,195,180,125,65,115,22,0,0},{125,115,125,115,105,75,35,55,22,0,0},{75,75,55,25,55,25,10,20,65,0,0},{0,0,0,0,0,0,0,0,100,55,100},{110,110,105,95,105,95,35,90,0,0,0}};
};


#endif // UNITES_H
