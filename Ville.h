#ifndef VILLE_H
#define VILLE_H
#include "Buildings.h"
#include "Unites.h"

class Ville : public Buildings
{
public:
    Ville(int X, int Y ,int Z=20,int T=0);
    int getCapturepoint() const;
    void setCapturepoint(int value);
    void repair(Unites c);
    int getTeam() const;
    void setTeam(int value);
    void initTeam();
    void initCapturePoint();
    bool getUnitin() const;
    void setUnitin(bool value);

    int getUnite() const;
    void setUnite(int value);

private:
    int capturepoint;
    int team;
    bool unitin=false;
    int unite;
   /*team =1 red team =2 blue*/
};

#endif // VILLE_H
