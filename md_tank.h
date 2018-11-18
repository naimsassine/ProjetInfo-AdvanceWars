#ifndef MD_TANK_H
#define MD_TANK_H
#include "Unites.h"
#include "non_infanterie.h"
#include <QKeyEvent>

class MD_tank : public Non_Infanterie
{
private:
        int nombreDeTour;
public:
    MD_tank(int InitX,int InitY,int InitTeam);
    void attack();
};

#endif // MD_TANK_H
