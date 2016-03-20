//
//  Fish.cpp
//  PA3
//

#include "Fish.h"
#include "math.h"
#include "Model.h"
using namespace std;

//default constructor
Fish::Fish(char display_code, int size) : GameObject(display_code,get_id())
{
    //display_code = 'F';
    state = 'h';
    energy = 15;
    this->size = size;
    prefeast_size = size;
    destination.x = 0.0;
    destination.y = 0.0;
    reef = NULL;
    home = NULL;
    cout << "Fish default constructed" << endl;
}

// constructor 1
Fish::Fish(char display_code, int in_id, Cave* home, int size)
        : GameObject(display_code,in_id,home->get_location())
{
    energy = 15;
    this->size = size;
    prefeast_size = size;
    destination.x = 0.0;
    destination.y = 0.0;
    home->hide_fish(this);
    reef = NULL;
    this->home = home;
    state = 'h';
    cout << "Fish constructed" << endl;
}

// constructor 2 WHAT DOES SPAWN MEAN
Fish::Fish(char display_code,int in_id, CartPoint location ,int size)
        : GameObject(display_code,in_id,location)
{
    state = 's';
    energy = 15;
    this->size = size;
    prefeast_size = size;
    home = NULL;
    reef = NULL;
    destination.x = 0; // CHECK
    destination.y = 0; // CHECK
    cout << "Fish constructed" << endl;
}


// destructor
Fish::~Fish()
{
    cout << "Fish destructed" << endl;
}

// private member functions
bool Fish::update_location()
{
    if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) {
        location = destination;
        cout << display_code << get_id() << ": I'm there!" << endl;
        return true;
    }
    else {
        location = location + delta;
        cout << display_code << get_id() << ": just keep swimming..." << endl;
        return false;
    }
}

void Fish::setup_destination(CartPoint dest)
{
    // Setting destination pointer and calculating delta
    destination = dest;
    delta = (destination - location) * (get_speed() / cart_distance(destination, location));
}


// public member functions
bool Fish::update()
{
    switch (state) {
        case 'f':
        {
            home->release_fish(this);
            return false;
            break;
        }
        case 's':
        {
            bool here = update_location();
            if (here) {
                state = 'f';
                return true;
            }
            else
                return false;
            break;
        }
        case 'o':
        {
            bool here = update_location();
            if (here) {
                state = 'e';
                cout << display_code << get_id() << ": Starting to dine at a coral reef" << endl;
                prefeast_size = size;
                return true;
            }
            else
                return false;
            break;
        }
        case 'e':
        {
            double amount_to_provide = 20;
            if (size >= 2*prefeast_size) {
                setup_destination(home->get_location());
                cout << display_code << get_id() << ": I'm full. I'm heading home" << endl;
                state = 'z';
                return  true;
            }
            else {
                double food = reef->provide_food(amount_to_provide);
                if (food == 0) {
                    state = 'f';
                    cout << display_code << get_id() << ": This reef has no more food for me..." << endl;
                    return true;
                }
                else {
                    size += food/2;
                    cout << display_code << get_id() << ": Grew to size " << size << endl;
                    return false;
                }
            }
            break;
        }
        case 'z':
        {
            bool here = update_location();
            if (here) {
                bool hidden = home->hide_fish(this);
                if (hidden) {
                    state = 'h';
                    cout << display_code << get_id() << ": I am hidden and safe" << endl;
                }
                else {
                state = 'p';
                cout << display_code << get_id() << ": Help! My home cave is full" << endl;
                }
                return true;
            }
            else
                return false;
            break;
        }
        case 'p':
        {
            return false;
            break;
        }
        case 'x':
        {
            return false;
            break;
        }
        default:
        {
            return false;
            break;
        }
    }
}

// function returns size of fish
double Fish::get_size()
{
    return size;
}

// function tells the fish to start swimming towards a given direction
void Fish::start_swimming(CartPoint dest)
{
    if (is_alive()) {
        home->release_fish(this);
        setup_destination(dest);
        state = 's';
        cout << "Swimming " << get_id() << " to " << destination << endl;
        cout << display_code << get_id() << ": On my way" << endl;
    }
    else
        cout << display_code << get_id() << ": Dead." << endl;
}

// function tells the fish to start eating at the given CoralReef
void Fish::start_eating(CoralReef* destReef)
{
    if (is_alive()) {
        home->release_fish(this);
        setup_destination(destReef->get_location());
        reef = destReef;
        state = 'o';
        cout << "Fish " << get_id() << " eating at CoralReef " << destReef->get_id() << " and returning back to Cave " << home->get_id() << endl;
        cout << display_code << get_id() << ": Food here I come!" << endl;
    }
    else
        cout << display_code << get_id() << ": Dead." << endl;
}

// function checks if the fish is hidden
bool Fish::is_hidden()
{
    if (state == 'h') {
        return true;
    }
    else return false;
}

// function tells the fish to hide at the given cave
void Fish::start_hiding(Cave* destCave)
{
    if (state == 'h') {
        home->release_fish(this);
    }
    setup_destination(destCave->get_location());
    home = destCave;
    state = 'z';
    cout <<  "Fish " << get_id() << " swimming to Cave " << home->get_id() << endl;
    cout << display_code << get_id() << ": Off to safety" << endl;
}

// function tells the fish to stop moving, eating or hiding
void Fish::float_in_place()
{
    this->state = 'f';
    cout << "Stopping " << get_id() << endl;
    cout << display_code << get_id() << ": Resting my fins" << endl;
}

// function prints the status of the fish depending on its state
void Fish::show_status()
{
    GameObject::show_status();
    switch (state) {
        case 'f':
            cout << " is floating. Has a size of: " << size << " and energy of: " << energy << endl;
            break;
        case 's':
            cout << " has a speed of: " << get_speed() << " and is heading to: " << destination << endl;
            break;
        case 'o':
            cout << " is outbound to Reef: " << reef->get_id() << " with a speed of " << get_speed() << endl;
            break;
        case 'e':
            cout << " is eating at Reef " << reef->get_id() << endl;
            break;
        case 'z':
            cout << " is swimming to Cave " << home->get_id() << " with a speed of " << get_speed() << endl;
            break;
        case 'h':
            cout << " is hidden in Cave " << home->get_id() << endl; //id of the cave
            break;
        case 'p':
            cout << " is panicked!!!! And has a size of " << size << endl;
            break;
        default:
            break;
    }
}

// function prints stuff
void Fish::start_attack(Fish* fishptr)
{
    if (is_alive()) {
        cout << " I cannot attack. I am only shark food" << endl;
    }
    else
        cout << display_code << get_id() << ": Dead." << endl;
}

// function prints more stuff
bool Fish::start_mating(Fish* fishptr)
{
    cout << "I cannot mate. My primary goal is to hunt tunas" << endl;
    return false;
}

// function subtracts energy from fish
void Fish::get_bitten(int attack_strength)
{
    energy -= attack_strength;
    if (energy <= 0)
    {
        cout << display_code << get_id() << ": Oh no! I've become chum!" << endl;
        state = 'x';
    }
    else {
        cout << display_code << get_id() << ": Ouch!" << endl;
    }
}

bool Fish::is_alive()
{
    if (state == 'x') {
        return false;
    }
    else
        return true;
}

Cave* Fish::get_home()
{
    return home;
}

char Fish::get_state()
{
    return state;
}


// save function
void Fish::save(ofstream& file) {
    GameObject::save(file);
    file << this->energy << endl;
    file << this->size << endl;
    cout << "Fish" << endl;
}