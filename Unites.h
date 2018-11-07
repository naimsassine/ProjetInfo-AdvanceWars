#ifndef UNITES_H
#define UNITES_H
#include "Gameobject.h"

class Unites : public Gameobject{
public:
    Unites();
    void attack();
    void attend();
    void fusion();
    int getvie();
    int getdamage();
    int getnumero();
protected:
    int vie;
    int prix;
    int ptattack;
    int ptdeplacement;
    int damage;
    int numero;
};





#endif // UNITES_H
