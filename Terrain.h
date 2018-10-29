#ifndef TERRAIN_H
#define TERRAIN_H
#include "Gameobject.h"
#include <string>
using namespace std;

class Terrain : public Gameobject {
public:
    string getFilename() const;

protected:
    string filename;
private:
    int nbVie;


};




#endif // TERRAIN_H
