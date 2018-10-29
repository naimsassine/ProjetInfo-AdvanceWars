#ifndef TERRAIN_H
#define TERRAIN_H
#include "Gameobject.h"
#include <QString>
using namespace std;
class Terrain : public Gameobject {
public:
    QString  getFilename() const;

protected:
    QString filename;
private:
    int nbVie;


};




#endif // TERRAIN_H
