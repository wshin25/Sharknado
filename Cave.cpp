//
//  Cave.cpp
//  PA3
//

#include "Cave.h"

using namespace std;

//default constructor
Cave::Cave() : GameObject(display_code,1)
{
    space = 100;
    display_code = 'c';
    state = 'e';
    cout << "Cave default constructed" << endl;
}

// constructor
Cave::Cave(int in_id, CartPoint in_loc) : GameObject(display_code,in_id,in_loc)
{
    //id_num = in_id;
    space = 100;
    display_code = 'c';
    state = 'e';
    cout << "Cave constructed" << endl;
}

// destructor
Cave::~Cave()
{
    cout << "Cave destructed" << endl;
}

// public member functions

bool Cave::hide_fish(Fish* fish_to_hide)
{
    if (space >= fish_to_hide->get_size() && !(fish_to_hide->is_hidden())) {
        space -= fish_to_hide->get_size();
        return true;
    }
    else
        return false;
}

bool Cave::release_fish(Fish* fish_to_release)
{
    if (fish_to_release->is_hidden()) {
        space += fish_to_release->get_size();
        return true;
    }
    else
        return false;
}

bool Cave::update()
{
    if (space == 0 && state == 'e') {
        state = 'p';
        display_code = 'C';
        cout << "Cave " << get_id() << " is packed like sardines" << endl;
        return true;
    }
    else if (space != 0 && state == 'p') {
        state = 'e';
        display_code = 'c';
        return true;
    }
    else return false;
}

void Cave::show_status()
{
    cout << "Cave Status: ";
    GameObject::show_status();
    cout << " has a space of " << space << endl;
}

double Cave::get_space()
{
    return space;
}

// save function
void Cave::save(ofstream & file) {
    GameObject::save(file);
    file << this->space << endl;
    cout << "Cave" << endl;
}