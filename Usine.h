#ifndef USINE_H
#define USINE_H
#include "Buildings.h"
#include "Unites.h"
class Usine : public Buildings
{
public:
    Usine(int posX, int posY, int def, int argent, int PC);
    void repair(Unites c);
    int getTeam() const;
    void setTeam(int value);
    void createTeam(Unites c);

private:
    int capturepoint=20;
    int team=0;
    /*team =1 red team =2 blue*/
};

#endif // USINE_H
