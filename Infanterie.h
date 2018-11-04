#ifndef INFANTERIE_H
#define INFANTERIE_H
#include "Unites.h"
#include <QKeyEvent>


class Infanterie : public Unites {
private:
    int nombreDeTour;


public:
    Infanterie(int InitX,int InitY,int InitTeam);

    void capture();

};



#endif // INFANTERIE_H
