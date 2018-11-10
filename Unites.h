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

    int getTeam() const;
    void setTeam(int value);


protected:
    int vie;
    int prix;
    int ptattack;
    int ptdeplacement;
    int damage;
    int numero;
    int Team;
};





#endif // UNITES_H
