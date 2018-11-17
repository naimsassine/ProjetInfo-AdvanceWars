#include "Unites.h"
#include "Gameobject.h"
#include "iostream"

Unites::Unites(){
   this->ptattack = 7;
   this->ptdefense = 3;
   this->defterrain = 1;
    ptdeplacement=3;
   this->B = 65;
   this->defTerrain = 0;
   vie=10;
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

void Unites::setDamage(Unites A, int defTerrain)
{
    // B fournie dans la charte de dégats, comme on a qu'un seul type d'unité je met direct la valeur pour l'instant
int degat = B * A.ptattack / 10 * (100 - defTerrain * ptdefense) / 100;
std::cout<<degat<<std::endl;
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

int Unites::getPtdeplacement() const
{
    return ptdeplacement;
}

void Unites::setPtdeplacement(int value)
{
    ptdeplacement = value;
}
