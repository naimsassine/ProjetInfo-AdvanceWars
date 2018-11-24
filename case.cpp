#include "case.h"

Case::Case()
{

}

int Case::getPosX() const
{
    return posX;
}

void Case::setPosX(int value)
{   if(value<21 &&value>=0 ){
    posX = value;}
}

int Case::getPosY() const
{
    return posY;
}

void Case::setPosY(int value)
{   if(value<17 &&value>=0 ){
    posY = value;}
}
