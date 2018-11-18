#ifndef NEOTANK_H
#define NEOTANK_H
#include "Unites.h"
#include "non_infanterie.h"
#include <QKeyEvent>


class Neotank: public Non_Infanterie
{
private:
    int nombreDeTour;
public:
    Neotank(int InitX,int InitY,int InitTeam);
    void attack();
};

#endif // NEOTANK_H
