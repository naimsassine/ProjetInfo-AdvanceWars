#ifndef INFANTERIE_H
#define INFANTERIE_H
#include "Unites.h"
#include <QKeyEvent>


class Infanterie : public Unites {
private:
    int nombreDeTour;


public:
    Infanterie(int InitX,int InitY,int InitTeam);
    //~Infanterie();
    void capture();
    void attack();

};



#endif // INFANTERIE_H
