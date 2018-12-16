#ifndef RECON_H
#define RECON_H
#include "Unites.h"
#include "non_infanterie.h"
#include <QKeyEvent>
class Recon : public Non_Infanterie
{
private:
    int nombreDeTour;

public:
    Recon(int InitX,int InitY,int InitTeam);
    void attack();
    static const int money2=15000;

};

#endif // RECON_H
