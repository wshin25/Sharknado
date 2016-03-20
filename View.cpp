//
//  View.cpp
//  PA3
//

#include "View.h"
#include "CartPoint.h"

// default constructor
View::View()
{
    size = 11;
    scale = 2;
    origin = CartPoint();
}

//private member functions
bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
    ix = static_cast<int>(location.x - origin.x)/scale;
    iy = static_cast<int>(location.y - origin.y)/scale;
    if (ix <= 20 && ix >= 0 && iy <= 20 && iy >= 0)
    {
        return true;
    }
    else {
        cout << "An object is outside the display" << endl;
        return false;
    }
}

// public member functions

void View::clear()
{
    for (int j = 0; j < view_maxsize; j++) {
        for (int i = 0; i < view_maxsize; i++) {
            if (i < size && j < size) {
                grid[i][j][0] = '.';
                grid[i][j][1] = ' ';
            }
        }
    }
}

void View::plot(GameObject* ptr)
{
    int ix = ptr->get_location().x;
    int iy = ptr->get_location().y;
    bool valid = get_subscripts(ix, iy, ptr->get_location());
    if (valid) {
        if (grid[ix][iy][0] == '.' && grid[ix][iy][1] == ' ') {
            ptr->drawself(grid[ix][iy]);
        }
        else {
            grid[ix][iy][0] = '*';
            grid[ix][iy][1] = ' ';
        }
    }
}

void View::draw()
{
    //initialize labels
    int xlabel = 0;
    int ylabel = view_maxsize;
    
    // loop through x axes (up to down)
    for (int j = view_maxsize-1; j >= -1; j--) {
        if (j == -1) {
            cout << "  ";
            for (int i = 0; i < view_maxsize; i++) {
                if (i < size) {
                    if (i%2 == 0) {
                        cout << xlabel;
                    }
                    else if (xlabel <= 10) {
                        cout << "   ";
                    }
                    else {
                        cout << "  ";
                    }
                    xlabel = xlabel + scale;
                }
            }
        }
        else if (j < size) {
            // loop through y axes (left to right)
            for (int i = 0; i < view_maxsize; i++) {
                if (i < size) {
                    if (i == 0) {
                        if (j%2 == 0) {
                            cout << ylabel;
                            if (ylabel < 10)
                                cout << " ";
                        }
                        else {
                            cout << "  ";
                        }
                        ylabel = ylabel - scale;
                    }
                    cout << grid[i][j][0];
                    if (grid[i][j][1]!=' ')
                        cout << static_cast<int>(grid[i][j][1]);
                    else
                        cout << grid[i][j][1];
                }
            }
        cout << endl;
        }
    }
    cout << endl;
}
