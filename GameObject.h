//
//  GameObject.h
//  PA3_UnderTheSea
//

#ifndef __PA3__GameObject__
#define __PA3__GameObject__
#include <stdio.h>
#include "CartPoint.h"
#include <fstream>
#include <iostream>

using namespace std;
class Model;

class GameObject
{
private:
    int id_num;
protected:
    CartPoint location;
    char display_code;
    char state;
public:
    GameObject(char, int);
    GameObject(char, int, CartPoint);
    virtual ~GameObject();
    CartPoint get_location();
    int get_id();
    virtual void show_status();
    virtual bool update() = 0;
    void drawself(char*);
    virtual bool is_alive();
    void set_location(int,int);
    char get_display_code();
    // save & restore
    virtual void save(ofstream&);
    //virtual void restore(ifstream&, Model&);
};

#endif /* defined(__PA3__GameObject__) */
