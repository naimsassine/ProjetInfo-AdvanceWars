#ifndef FIGHTER_H
#define FIGHTER_H

#include "Aerienne.h"
#include <QKeyEvent>
class Fighter: public Aerienne
{
public:
    Fighter(int InitX, int InitY, int InitTeam);
};

#endif // FIGHTER_H
