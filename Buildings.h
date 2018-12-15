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
    int getUnite() const;
    void setUnite(int value);
    bool getUnitin() const;
    void setUnitin(bool value);

    int getCapturepoint() const;
    void setCapturepoint(int value);

protected :
    int unite=-1;
    bool unitin=false;
    int capturepoint;
};


#endif // BUILDINGS_H
