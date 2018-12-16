#ifndef BAZOOKA_H
#define BAZOOKA_H
#include "Unites.h"


class Bazooka : public Unites
{
public:
    Bazooka(int InitX,int InitY,int InitTeam);
    static const int money2=3000;
};

#endif // BAZOOKA_H
