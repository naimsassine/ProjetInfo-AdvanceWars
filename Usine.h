#ifndef USINE_H
#define USINE_H
#include "Buildings.h"
#include "Unites.h"
class Usine : public Buildings
{
public:
    Usine(int posX, int posY, int def, int argent, int PC);
    Usine(int X, int Y);
    void repair(Unites c);
    int getCapturepoint() const;
    void setCapturepoint(int value);
    void initCapturePoint();

    int getTeam() const;
    void setTeam(int value);
    void createTeam(Unites c);
    bool getUnitin() const;
    void setUnitin(bool value);

    bool getComptproduction() const;
    void setComptproduction(bool value);

private:
    int capturepoint=20;
    int team=0;

    bool unitin=false;
     bool comptproduction=true;
    /*team =1 red team =2 blue*/
};

#endif // USINE_H
