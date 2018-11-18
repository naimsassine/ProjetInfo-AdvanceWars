#ifndef TANK_H
#define TANK_H
#include "Unites.h"
#include <QKeyEvent>
#include "non_infanterie.h"

class Tank : public Non_Infanterie
{
private:
    int nombreDeTour;
public:
    Tank(int InitX,int InitY,int InitTeam);
    void attack();
};

#endif // TANK_H
