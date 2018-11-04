#ifndef AEROPORT_H
#define AEROPORT_H
#include "Buildings.h"
#include"Aerienne.h"
class Aeroport : public Buildings
{
public:
    Aeroport(int X, int Y);
    void repair(Aerienne a);
    int getTeam() const;
    void setTeam(int value);
};

#endif // AEROPORT_H
