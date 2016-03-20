//
//  CoralReef.cpp
//  PA3
//

#include "CoralReef.h"

using namespace std;

// default constructor
CoralReef::CoralReef() : GameObject(display_code,get_id())
{
    display_code = 'R';
    state = 'f';
    amount = 100;
    cout << "CoralReef default constructed" << endl;
}

// constructor
CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject(display_code,in_id,in_loc)
{
    display_code = 'R';
    state = 'f';
    amount = 100;
    cout << "CoralReef constructed" << endl;
}

// destructor
CoralReef::~CoralReef()
{
    cout << "CoralReef destructed" << endl;
}

// public member functions
bool CoralReef::is_empty()
{
    if (amount == 0) {
        return true;
    }
    else
        return false;
}

double CoralReef::provide_food(double amount_to_provide = 20.0)
{
    if (amount >= amount_to_provide) {
        amount -= amount_to_provide;
        return amount_to_provide;
    }
    else {
        double current_amount = amount;
        amount = 0;
        return current_amount;
    }
}

bool CoralReef::update()
{
    if (amount == 0 && state == 'f') {
        this->state = 'e';
        this->display_code = 'r';
        cout << "CoralReef " << get_id() << " has been depleted of food" << endl;
        return true;
    }
    else
        return false;
}

void CoralReef::show_status()
{
    cout << "CoralReef Status: ";
    GameObject::show_status();
    cout << " containing food " << amount << endl;
}

// save function
void CoralReef::save(ofstream& file) {
    GameObject::save(file);
    file << this->amount << endl;
    cout << "Reef" << endl;
}