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
    void initCapturePoint();

    int getTeam() const;
    void setTeam(int value);
    void createTeam(Unites c);


    bool getComptproduction() const;
    void setComptproduction(bool value);

private:

    int team=0;

     bool comptproduction=true;
    /*team =1 red team =2 blue*/
};

#endif // USINE_H
