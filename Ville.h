#ifndef VILLE_H
#define VILLE_H
#include "Buildings.h"
#include "Unites.h"

class Ville : public Buildings
{
public:
    Ville(int X, int Y);
    int getCapturepoint() const;
    void setCapturepoint(int value);
    void repair(Unites c);
    int getTeam() const;
    void setTeam(int value);

private:
    int capturepoint=20;
    int team=0;
    /*team =1 red team =2 blue*/
};

#endif // VILLE_H
