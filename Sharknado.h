//
//  Sharknado.h
//  PA4
//

#ifndef __PA4__Sharknado__
#define __PA4__Sharknado__

#include <stdio.h>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"

using namespace std;

class Model;

class Sharknado: public GameObject
{
private:
    int timer;
    Model* world;
public:
    Sharknado(Model*);
    bool update();
    ~Sharknado();
//    void history();
};

#endif /* defined(__PA4__Sharknado__) */
