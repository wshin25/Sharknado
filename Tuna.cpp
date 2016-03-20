//
//  Tuna.cpp
//  PA4
//

#include "Tuna.h"
#include "Model.h"

using namespace std;
// default constructor
Tuna::Tuna(Model* world) : Fish('T',10)
{
    this->world = world;
    timer = 0;
    initiator = false;
    //cout << "Default Tuna constructed" << endl;
}

Tuna::Tuna(int id, Cave* home, Model* world) : Fish('T', id, home, 10)
{
    this->world = world;
    timer = 0;
    initiator = false;
    //cout << "Tuna constructed" << endl;
}

double Tuna::get_speed()
{
    return energy/size*4;
}

bool Tuna::start_mating(Tuna* fish_mate)
{
                cout << display_code << get_id() << ": I found my mate!" << endl;
                do_mating();
                initiator = true;
                fish_mate->do_mating();
                return true;
}

bool Tuna::update()
{
    Fish::update();
    switch (state) {
        case 'h':
        {
            if (is_hidden()) {
                energy = energy - 0.25;
                if (energy < 5) {
                    state = 'x';
                    return true;
                }
                else {
                    Tuna* fish_mate = world->find_a_mate_for(this);
                    //cout << this->get_home()->get_id() << endl;
                    if (fish_mate != NULL) {
                        bool baby = start_mating(fish_mate);
                        return baby;
                    }
                    else return false;
                }
            }
            else return false; // NECESSARY??
            break;
        }
        case 'm':
        {
            if (timer == 2) {
                timer = 0;
                state = 'h';
                if (initiator == true) {
                    world->add_baby_tuna(home);
                }
                return true;
            }
            else {
                timer++;
                return false;
            }
        }
        default: {
            return false;
            break;
        }
    }
}

void Tuna::show_status()
{
    cout << "Tuna status: ";
    Fish::show_status();
    if (state == 'm')
        cout << " and is mating." << endl;
    if (state == 'x')
        cout << " is dead." << endl;
}

void Tuna::do_mating()
{
    this->state = 'm';
}

void Tuna::save(ofstream & file) {
    Fish::save(file);
    cout << "Tuna" << endl;
}