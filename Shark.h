//
//  Shark.h
//  PA4
//

#ifndef __PA4__Shark__
#define __PA4__Shark__

#include "Fish.h"
#include <fstream>
//#include "Model.h"

class Model;

class Shark: public Fish
{
private:
    int attack_strength;
    double range;
    Fish* target;
public:
    Shark(Model*);
    Shark(int,Model*);
    double get_speed();
    void start_attack(Fish*);
    bool update();
    void show_status();
    void save(ofstream&);

};

#endif /* defined(__PA4__Shark__) */
