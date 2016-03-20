//
//  Sharknado.cpp
//  PA4
//

#include "Sharknado.h"
#include "Model.h"

using namespace std;

Sharknado::Sharknado(Model* world): GameObject(1,1)
{
    this->world = world;
    timer = 0;
    cout << "Sharknado constructued" << endl;
}

Sharknado::~Sharknado()
{
    cout << "Sharknado destructed" << endl;
}

bool Sharknado::update()
{
    timer++;
    if (timer == 10) {
        cout << "The Sharknado is coming!" << endl;
    }
    if (timer == 15) {
        timer = 0;
        cout << "The Sharknado is upon us!" << endl;
        world->delete_objects();
        return true;
    }
    return false;
}