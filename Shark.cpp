//
//  Shark.cpp
//  PA4
//

#include "Shark.h"
#include <stdio.h>
#include "math.h"
#include "Model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Shark::Shark(Model* world): Fish('S',20)
{
    this->world = world;
    range = 1;
    attack_strength = 2;
    //cout << "Shark defalut constructed" << endl;
}

Shark::Shark(int in_id, Model* world): Fish('S',in_id,CartPoint(0,0),20)
{
    this->world = world;
    srand(world->get_time());
    double x = rand()% 20;
    double y = rand()% 20;
    CartPoint* loc = new CartPoint(x,y);
    location = *loc;
    state = 'f';
    range = 1;
    attack_strength = 2;
    cout << "Shark constructed" << endl;
}

double Shark::get_speed()
{
    return energy/size*8;
}

void Shark::start_attack(Fish* fishptr)
{
    double x = this->get_location().x - fishptr->get_location().x;
    double y = this->get_location().y - fishptr->get_location().y;
    if (sqrt(x*x + y*y) < range) {
        cout << display_code << get_id() << ": Chomp!" << endl;
        state = 'a';
        fishptr->get_bitten(attack_strength);
        target = fishptr;
    }
    else
        cout << display_code << get_id() << ": Fish are friends, not food" << endl;
}

bool Shark::update()
{
    switch (state) {
        case 'x':
            return false;
            break;
        case 's':
            return false;
            break;
        case 'e': // HOW TO CALL FISH UPDATE
            return false;
            break;
        case 'a':
            if (range > 1) {
                cout << display_code << get_id() << ": Darn! It escaped." << endl;
                target = NULL;
                state = 's';
                return true;
            }
            else {
                if (!(target->is_alive())) {
                    cout << display_code << get_id() << ": I triumph!" << endl;
                    state = 's';
                    energy += 5;
                    return true;
                }
                else {
                    cout << display_code << get_id() << ": Chomp!" << endl;
                    target->get_bitten(attack_strength);
                    return false;
                }
            }
            break;
        default:
            return false;
            break;
    }
}

void Shark::show_status()
{
    cout << "Shark status: ";
    Fish::show_status();
    if (state == 'a')
        cout << " is attacking." << endl;
    //else
    //    cout << " is swimming." << endl;
}

void Shark::save(ofstream & file) {
    Fish::save(file);
    file << this->attack_strength << endl;
    file << this->range << endl;
    cout << "Shark" << endl;
}