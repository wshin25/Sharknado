//
//  Tuna.h
//  PA4
//

#ifndef __PA4__Tuna__
#define __PA4__Tuna__

#include <stdio.h>
#include "Fish.h"
#include "Cave.h"
#include <fstream>

class Model;

class Tuna: public Fish
{
private:
    int timer;
    bool initiator;
public:
    double get_speed();
    bool start_mating(Tuna*);
    bool update();
    void show_status();
    void do_mating();
    Tuna(Model*);
    Tuna(int,Cave*,Model*);
    void save(ofstream&);

};
#endif /* defined(__PA4__Tuna__) */
