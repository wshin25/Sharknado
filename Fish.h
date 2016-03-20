//
//  Fish.h
//  PA3
//

#ifndef __PA3__Fish__
#define __PA3__Fish__

#include <stdio.h>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include <fstream>

using namespace std;

class Cave;
class Model;

class Fish: public GameObject
{
private:
    double prefeast_size;
    CartPoint destination;
    CartVector delta;
    CoralReef* reef;
    bool update_location();
    void setup_destination(CartPoint);
protected:
    double energy;
    double size;
    Cave* home;
    //char display_code;
    //char state;
    Model* world;
public:
    virtual bool update();
    double get_size();
    void start_swimming(CartPoint);
    void start_eating(CoralReef*);
    bool is_hidden();
    void start_hiding(Cave*);
    void float_in_place();
    void show_status();
    virtual double get_speed() = 0;
    //PA4 stuff
    virtual void start_attack(Fish*);
    virtual bool start_mating(Fish*);
    void get_bitten(int);
    bool is_alive();
    Cave* get_home(); // necessary?
    char get_state();
    void save(ofstream&);

    
    Fish(char,int);
    Fish(char,int,Cave*,int);
    Fish(char,int,CartPoint,int);
    ~Fish();
};

#endif /* defined(__PA3__Fish__) */
