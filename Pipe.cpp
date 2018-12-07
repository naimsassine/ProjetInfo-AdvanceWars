#include "Pipe.h"

Pipe::Pipe()
{

}
Pipe::Pipe(int X, int Y)
{
    posX = X;
    posY = Y;
    type = 0;
    ptdemouvement=100;
    posdef=11;
    ldemouvement[0]=0;
    ldemouvement[1]=0;
    ldemouvement[2]=0;
    ldemouvement[3]=0;
    ldemouvement[4]=0;
}
