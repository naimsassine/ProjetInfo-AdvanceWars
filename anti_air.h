#ifndef ANTI_AIR_H
#define ANTI_AIR_H
#include "Unites.h"
#include <QKeyEvent>
#include "non_infanterie.h"

class Anti_Air : public Non_Infanterie
{
private:
    int nombreDeTour;

public:
    Anti_Air(int InitX,int InitY,int InitTeam);
    void attack();


};

#endif // ANTI_AIR_H
