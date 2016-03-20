//
//  View.h
//  PA3
//

#ifndef __PA3__View__
#define __PA3__View__

#include <stdio.h>
#include "CartPoint.h"
#include "GameObject.h"
using namespace std;

const int view_maxsize = 20;

class View
{
private:
    int size;
    double scale;
    CartPoint origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int&,int&,CartPoint);
public:
    View();
    void clear();
    void plot(GameObject*);
    void draw();
};
#endif /* defined(__PA3__View__) */
