//
//  Model.h
//  PA3
//

#ifndef __PA3__Model__
#define __PA3__Model__

#include <stdio.h>
#include "Cave.h"
#include "Fish.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "View.h"
#include <list>
#include "Tuna.h"
#include "Shark.h"
#include "Sharknado.h"
#include <fstream>


using namespace std;

class Model
{
private:
    int count;
    int time;
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<Fish*> fish_ptrs;
    list<Fish*> dead_ptrs;
    list<Cave*> cave_ptrs;
    list<CoralReef*> reef_ptrs;
    list<Sharknado*> sharknado_ptr;
public:
    Model();
    ~Model();
    Fish* get_Fish_ptr(int);
    bool update();
    void display(View&);
    void show_status();
    Tuna* find_a_mate_for(Tuna*);
    void add_baby_tuna(Cave*);
    void add_new_object(GameObject*);
    int get_time();
    Shark* add_Shark_ptr(int);
    Tuna* add_Tuna_ptr(int,int);
    CoralReef* add_CoralReef_ptr(int,double,double);
    Cave* add_Cave_ptr(int,double,double);
    CoralReef* get_CoralReef_ptr(int);
    Cave* get_Cave_ptr(int);
    void delete_objects();
    void show_history();
    void save(ofstream&);
    //void restore(ifstream&);
};

#endif /* defined(__PA3__Model__) */
