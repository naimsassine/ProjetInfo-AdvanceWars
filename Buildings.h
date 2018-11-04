#ifndef BUILDINGS_H
#define BUILDINGS_H
#include "Terrain.h"
#include "Unites.h"
class Buildings : public Terrain {

public:
    Buildings();
    Buildings(int X, int Y);

    //virtual void repair(Unites c);
    //virtual int getTeam() const;
    //virtual void setTeam(int value);
   // virtual ~Buildings();
};


#endif // BUILDINGS_H
