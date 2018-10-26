#ifndef UNITES_H
#define UNITES_H
#include "Gameobject.h"

class Unites : public Gameobject{
public:
    void attack();
    void attend();
    void fusion();
    int getvie();
    int getdamage();
    int getnumero();
private:
    int vie;
    int ptattack;
    int ptdeplacement;
    int damage;
    int numero;

};





#endif // UNITES_H
