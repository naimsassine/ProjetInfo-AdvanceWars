#ifndef MEGA_TANK_H
#define MEGA_TANK_H
#include "Unites.h"
#include "non_infanterie.h"
#include <QKeyEvent>

class mega_tank : public Non_Infanterie
{
private:
    int nombreDeTour;
public:
    mega_tank(int InitX,int InitY,int InitTeam);
    void attack();
};

#endif // MEGA_TANK_H
