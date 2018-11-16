#ifndef AEROPORT_H
#define AEROPORT_H
#include "Buildings.h"
#include"Aerienne.h"
class Aeroport : public Buildings
{
public:
    Aeroport(int X, int Y);

    //partie similaire à usine//

    void repair(Aerienne a);
    int getTeam() const;
    void setTeam(int value);
    Aeroport(int posX, int posY, int def, int argent, int PC);
    void repair(Unites c);
    void createTeam(Unites c);

    //partie similaire à ville//
    int getCapturepoint() const;
    void setCapturepoint(int value);
    void initTeam();
    void initCapturePoint();
    bool getUnitin() const;
    void setUnitin(bool value);

protected:
    int capturepoint=20;
    int team=0;
    bool unitin=false;
    int def_terrain = 0;
};

#endif // AEROPORT_H
