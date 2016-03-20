//
//  GameObject.cpp
//  PA3_UnderTheSea
//
#include <iostream>
#include "GameObject.h"
#include "Model.h"
#include <list>
using namespace std;

// constructor 1
GameObject::GameObject(char in_code, int in_id)
{
    id_num = in_id;
    display_code = in_code;
    location.x = 0.0;
    location.y = 0.0;
    cout << "GameObject default constructed" << endl;
}

// constructor 2
GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
    id_num = in_id;
    display_code = in_code;
    location = in_loc;
    cout << "GameObject constructed" << endl;
}

// destructor
GameObject::~GameObject()
{
    cout << "GameObject destructed" << endl;
}

// member functions
CartPoint GameObject::get_location()
{
    return location;
}

int GameObject::get_id()
{
    return id_num;
}

void GameObject::show_status()
{
    cout << display_code << " with ID " << id_num << " at location " << location;
}

void GameObject::drawself(char* grid)
{
    *grid = display_code;
    *(grid+1) = static_cast<char>(id_num);
}

bool GameObject::is_alive()
{
    return true;
}

void GameObject::set_location(int x,int y)
{
    location.x = x;
    location.y = y;
}

char GameObject::get_display_code()
{
    return display_code;
}


// save function
void GameObject::save(ofstream& file) {
    file << this->display_code << endl;
    file << this->id_num << endl;
    file << this->location.x << endl;
    file << this->location.y << endl;
    file << this->state << endl;
    cout << "GO" << endl;
}
//
//
//// restore function
//void GameObject::restore(ifstream& file, Model& model) {
//    string line;
//    getline(file,line);
//    display_code=line[0];
//    getline(file,line);
//    id_num=atoi(line.c_str());
//    getline(file,line);
//    location.x=atoi(line.c_str());
//    getline(file,line);
//    location.y=atoi(line.c_str());
//    getline(file,line);
//    state=line[0];
//}

