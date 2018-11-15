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
    int getdamage();
    int getnumero();
    void initvie();
    int getTeam() const;
    void setTeam(int value);
    void setDamage(Unites);
    bool getUnitin() const;
    void setUnitin(bool value);


    int getPtdeplacement() const;
    void setPtdeplacement(int value);

protected:
    int vie ;
    int prix;
    int ptattack;
    int ptdefense;
    int defterrain;
    int ptdeplacement=3;
    int B;
    int damage;
    int numero;
    int Team;
    bool unity =false;
};


#endif // UNITES_H
