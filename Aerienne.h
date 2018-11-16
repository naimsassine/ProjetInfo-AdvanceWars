#ifndef AERIENNE_H
#define AERIENNE_H
#
#include "Unites.h"
class Aerienne : public Unites {

private:
    int nombreDeTour;

public:
    Aerienne();
    //~Infanterie();
    void attack();

};



#endif // AERIENNE_H
