//
//  Cave.h
//  PA3
//

#ifndef __PA3__Cave__
#define __PA3__Cave__

#include <stdio.h>
#include "CartPoint.h"
#include "GameObject.h"
#include "Fish.h"
#include <fstream>

using namespace std;

class Fish;

class Cave: public GameObject
{
private:
    double space;
public:
    bool hide_fish(Fish*);
    bool release_fish(Fish*);
    bool update();
    void show_status();
    double get_space();
    void save(ofstream&);
    
    Cave();
    Cave(int,CartPoint);
    ~Cave();
};

#endif /* defined(__PA3__Cave__) */
