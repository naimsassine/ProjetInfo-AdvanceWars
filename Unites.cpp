#include "Unites.h"
#include "Gameobject.h"
#include "iostream"
#include <cmath>
Unites::Unites(){
   this->ptattack = 7;
   this->ptdefense = 3;
   this->defterrain = 1;
    ptdeplacement=3;
   this->B = 65;
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

void Unites::setvie(int value)
{
    vie = value;
}

int Unites::getdamage()
{
    return damage;
}

void Unites::setDamage(Unites A,Unites C ,int defTerrainc)
{
    // B fournie dans la charte de dégats, comme on a qu'un seul type d'unité je met direct la valeur pour l'instant
    if(C.getType()==2000 || C.getType()==2001 || C.getType()==2002){
        defTerrainc=0;
    }
float degat = B * A.getvie() / 10 * (100 - defTerrainc * C.getvie()) / 100;
std::cout<<degat<<std::endl;
vie = vie -int(degat/10);
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

int Unites::getPrix() const
{
    return prix;
}

void Unites::setPrix(int value)
{
    prix = value;
}

int Unites::getTypeu() const
{
    return typeu;
}
