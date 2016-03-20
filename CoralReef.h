//
//  CoralReef.h
//  PA3
//

#ifndef __PA3__CoralReef__
#define __PA3__CoralReef__

#include <stdio.h>
#include "CartPoint.h"
#include "GameObject.h"
#include <fstream>
using namespace std;

class CoralReef: public GameObject
{
private:
    double amount;
public:
    bool is_empty();
    double provide_food(double);
    bool update();
    void show_status();
    void save(ofstream&);
    
    CoralReef();
    CoralReef(int,CartPoint);
    ~CoralReef();
};

#endif /* defined(__PA3__CoralReef__) */
