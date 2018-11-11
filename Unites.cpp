#include "Unites.h"
#include "Gameobject.h"


Unites::Unites(){
   this->ptattack = 90;
   this->ptdefense = 90;
   this->defterrain = 10;
   this->B = 65;
}

void Unites::attack()
{

}

void Unites::attend()
{

}

void Unites::fusion()
{

}

int Unites::getvie()
{
    return vie;
}

int Unites::getdamage()
{
    return damage;
}

void Unites::setDamage(Unites A)
{
    // B fournie dans la charte de dégats, comme on a qu'un seul type d'unité je met direct la valeur pour l'instant
int degat = B * A.ptattack / 10 * (100 - defterrain * ptdefense) / 100;
vie = vie - degat;
if(vie<0){
    vie=0;
}


}
void Unites::initvie(){
    vie = 10;
}

int Unites::getnumero()
{
    return numero;
}

int Unites::getTeam() const
{
    return Team;
}

void Unites::setTeam(int value)
{
    Team = value;
}

bool Unites::getUnitin() const
{
    return unity;
}

void Unites::setUnitin(bool value)
{
    unity = value;
}
