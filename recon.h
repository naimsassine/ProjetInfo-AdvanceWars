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

};

#endif // RECON_H
