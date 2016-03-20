//
//  Model.cpp
//  PA3
//

#include "Model.h"

using namespace std;

// default constructor
Model::Model()
{
    // set time to zero
    time = 0;
    count = 0;
    
    // dynamically allocate object pointers
    CartPoint* cpPtr = new CartPoint(5,1); // location of cave 1
    Cave* cavePtr1 = new Cave(1,*cpPtr); //cave 1
    *cpPtr = CartPoint(6,2); // location of cave 2
    Cave* cavePtr2 = new Cave(2,*cpPtr); // cave 2
    *cpPtr = CartPoint(1,20); // location of reef 1
    CoralReef* reefPtr1 = new CoralReef(1,*cpPtr); // reef 1
    *cpPtr = CartPoint(20,1); // location of reef 2
    CoralReef* reefPtr2 = new CoralReef(2,*cpPtr); // reef 2
    *cpPtr = CartPoint(20,20); // location of reef 3
    CoralReef* reefPtr3 = new CoralReef(3,*cpPtr); // reef 3
    Tuna* tunaPtr1 = new Tuna(1,cavePtr1,this); // tuna 1
    Tuna* tunaPtr2 = new Tuna(2,cavePtr2,this); // tuna 2
    Tuna* tunaPtr3 = new Tuna(3,cavePtr2,this); // tuna 3
    Shark* sharkPtr1 = new Shark(4,this); // shark 1
    Shark* sharkPtr2 = new Shark(5,this); // shark 2

    // make object_ptrs
    object_ptrs.push_back(cavePtr1);
    object_ptrs.push_back(cavePtr2);
    object_ptrs.push_back(reefPtr1);
    object_ptrs.push_back(reefPtr2);
    object_ptrs.push_back(reefPtr3);
    object_ptrs.push_back(tunaPtr1);
    object_ptrs.push_back(tunaPtr2);
    object_ptrs.push_back(tunaPtr3);
    object_ptrs.push_back(sharkPtr1);
    object_ptrs.push_back(sharkPtr2);
    
    // make cave_ptrs
    cave_ptrs.push_back(cavePtr1);
    cave_ptrs.push_back(cavePtr2);
    
    // make reef_ptrs
    reef_ptrs.push_back(reefPtr1);
    reef_ptrs.push_back(reefPtr2);
    reef_ptrs.push_back(reefPtr3);
    
    // make fish_ptrs
    fish_ptrs.push_back(tunaPtr1);
    fish_ptrs.push_back(tunaPtr2);
    fish_ptrs.push_back(tunaPtr3);
    fish_ptrs.push_back(sharkPtr1);
    fish_ptrs.push_back(sharkPtr2);
    
    // make active_ptrs
    active_ptrs = object_ptrs;
    
    Sharknado* sharknado = new Sharknado(this);
    sharknado_ptr.push_back(sharknado);
    
    cout << "Model default constructed" << endl;
}

// destructor
Model::~Model()
{
    for (list<GameObject*>::iterator iter=object_ptrs.begin(); iter!=object_ptrs.end(); iter++) {
        delete *iter;
    }
    delete *sharknado_ptr.begin();
    fish_ptrs.clear();
    reef_ptrs.clear();
    cave_ptrs.clear();
    object_ptrs.clear();
    dead_ptrs.clear();
    sharknado_ptr.clear();
    cout << "Model destructed" << endl;
}

// public member functions
Fish* Model::get_Fish_ptr(int id_num)
{
    for (list<Fish*>::iterator iter=fish_ptrs.begin();iter!=fish_ptrs.end();iter++) {
        if((*iter)->get_id() == id_num) {
            return *iter;
        }
    }
    return NULL;
}

// UPDATE FUNCTION
bool Model::update()
{
    time++;
    bool status = false;
    bool up = false;
    for (list<GameObject*>::iterator iter=active_ptrs.begin(); iter!=active_ptrs.end(); iter++) {
        up = (*iter)->update();
        if (up == true) {
            status = true;
        }
        if (!(*iter)->is_alive()) {
            active_ptrs.erase(iter);
            cout << "Dead object removed" << endl;
        }
    }
    // update sharknado
    (*sharknado_ptr.begin())->update();
    return status;
}

void Model::display(View& view)
{
    cout << "Time: " << time << endl;
    view.clear();
    for (list<GameObject*>::iterator iter=active_ptrs.begin(); iter!=active_ptrs.end(); iter++) {
        view.plot(*iter);
    }
    view.draw();
}

void Model::show_status()
{
    cout << "---Fish---" << endl;
    for (list<Fish*>::iterator iter=fish_ptrs.begin(); iter!=fish_ptrs.end(); iter++) {
        (*iter)->show_status();
    }
    cout << "---Cave---" << endl;
    for (list<Cave*>::iterator iter=cave_ptrs.begin(); iter!=cave_ptrs.end(); iter++) {
        (*iter)->show_status();
    }
    cout << "---Reef---" << endl;
    for (list<CoralReef*>::iterator iter=reef_ptrs.begin(); iter!=reef_ptrs.end(); iter++) {
        (*iter)->show_status();
    }
}

Tuna* Model::find_a_mate_for(Tuna* tunaPtr)
{
    for (list<Fish*>::iterator iter=fish_ptrs.begin(); iter!=fish_ptrs.end(); iter++) {
        if (typeid(*iter) == typeid(Shark*)) continue;
        if (tunaPtr->get_home()/*->get_id()*/ == (*iter)->get_home()/*->get_id()*/ && tunaPtr->get_id() != (*iter)->get_id()) {
            //cout << tunaPtr->get_home()->get_id() << endl;
            if (tunaPtr->get_home()->get_space() + tunaPtr->get_size() + (*iter)->get_size() == 100) {
                if (tunaPtr->get_home()->get_space() >= 10) {
                    if (tunaPtr->get_size() >= 20 && tunaPtr->get_size() <= 60 && (*iter)->get_size() >= 20 && (*iter)->get_size() <= 60) {
                        
                        return dynamic_cast<Tuna*>(*iter);
                    }
                }
            }
        }
    }
    return NULL;
}

// adds a baby tuna
void Model::add_baby_tuna(Cave* home)
{
    int id = 1;
    // figure out lowest id num of baby tuna
    for (list<Fish*>::iterator iter=fish_ptrs.begin(); iter!=fish_ptrs.end(); iter++) {
        if (id ==(*iter)->get_id()) {
            id++;
        }
    }
    Tuna* tunaPtr = new Tuna(id,home,this);
    cout << "Tuna " << tunaPtr->get_id() << " was born in cave " << tunaPtr->get_home()->get_id() << endl;
    object_ptrs.push_back(tunaPtr);
    fish_ptrs.push_back(tunaPtr);
}

// adds a new object to the corresponding lists
void Model::add_new_object(GameObject* objectPtr)
{
    object_ptrs.push_back(objectPtr);
    if (objectPtr->get_display_code() == 'T' || objectPtr->get_display_code() == 'S') {
        fish_ptrs.push_back(dynamic_cast<Fish*>(objectPtr));
    }
    else if (objectPtr->get_display_code() == 'C')
    {
        cave_ptrs.push_back(dynamic_cast<Cave*>(objectPtr));
    }
    else
        reef_ptrs.push_back(dynamic_cast<CoralReef*>(objectPtr));
}

int Model::get_time()
{
    return time;
}

// adds a shark and returns its pointer
Shark* Model::add_Shark_ptr(int id)
{
    for (list<Fish*>::iterator iter=fish_ptrs.begin();iter!=fish_ptrs.end();iter++) {
        if((*iter)->get_id() == id) {
            return NULL;
        }
    }
    Shark* sharkPtr = new Shark(id,this);
    cout << "Created a new shark with id " << sharkPtr->get_id() << " at " << sharkPtr->get_location() << endl;
    return sharkPtr;
}

// adds a tuna and returns its pointer
Tuna* Model::add_Tuna_ptr(int id, int home_id)
{
    for (list<Fish*>::iterator iter=fish_ptrs.begin();iter!=fish_ptrs.end();iter++) {
        if((*iter)->get_id() == id) {
            return NULL;
        }
    }
    for (list<Cave*>::iterator iter=cave_ptrs.begin(); iter!=cave_ptrs.end(); iter++) {
        if ((*iter)->get_id() == home_id) {
            Tuna* tunaPtr = new Tuna(id,(*iter),this);
            cout << "Created a new tuna with id " << tunaPtr->get_id() << " at " << tunaPtr->get_location() << endl;
            return tunaPtr;
        }
    }
    return NULL;
}

// adds a cave and returns its pointer
Cave* Model::add_Cave_ptr(int id_num, double x, double y)
{
    for (list<Cave*>::iterator iter=cave_ptrs.begin(); iter!=cave_ptrs.end(); iter++) {
        if ((*iter)->get_id() == id_num)
            return NULL;
    }
    Cave* cavePtr = new Cave(id_num,CartPoint(x,y));
    cout << "Created a new cave with id " << cavePtr->get_id() << " at " << cavePtr->get_location() << endl;
    return cavePtr;
}

// adds a coral reef and returns its pointer
CoralReef* Model::add_CoralReef_ptr(int id_num, double x, double y)
{
    for (list<CoralReef*>::iterator iter =reef_ptrs.begin();iter!=reef_ptrs.end(); iter++) {
        if ((*iter)->get_id() == id_num)
            return NULL;
    }
    CoralReef* reefPtr = new CoralReef(id_num,CartPoint(x,y));
    cout << "Created a new coral reef with id " << reefPtr->get_id() << " at " << reefPtr->get_location() << endl;
    return reefPtr;
}



CoralReef* Model::get_CoralReef_ptr(int id_num)
{
    for (list<CoralReef*>::iterator iter =reef_ptrs.begin();iter!=reef_ptrs.end(); iter++) {
        if ((*iter)->get_id() == id_num)
            return (*iter);
    }
    return NULL;
}

Cave* Model::get_Cave_ptr(int id_num)
{
    for (list<Cave*>::iterator iter=cave_ptrs.begin(); iter!=cave_ptrs.end(); iter++) {
        if ((*iter)->get_id() == id_num)
            return (*iter);
    }
    return NULL;
}

void Model::delete_objects()
{
    count = 0;
    cout << "----------The Sharknado Claimed----------" << endl;
    for (list<Fish*>::iterator iter=fish_ptrs.begin(); iter!=fish_ptrs.end(); iter++) {
        if ((*iter)->get_state() != 'h') {
            cout << "(" << count << ") - " << (*iter)->get_display_code() << (*iter)->get_id() << endl;
            dead_ptrs.push_back(*iter);
            fish_ptrs.remove(*iter);
            count++;
        }
    }
    cout <<  "-----------------------------------------" << endl;
}

void Model::show_history()
{
    count = 0;
    cout << "----------The History of Sharknado's Wrath----------" << endl;
    for (list<Fish*>::iterator iter=dead_ptrs.begin(); iter!=dead_ptrs.end(); iter++) {
        cout << "(" << count << ") - " << (*iter)->get_display_code() << (*iter)->get_id() << endl;
        count++;
    }
    cout << "----------------------------------------------------" << endl;
}


//// save function
void Model::save(ofstream& file) {
    // Catalog
    file << this->time << endl;
    file << this->active_ptrs.size() << endl;
    // Each object's info
    for (list<GameObject*>::iterator iter=active_ptrs.begin(); iter!=active_ptrs.end();iter++) {
        file << (*iter)->get_display_code() << (*iter)->get_id() << endl;
        cout << (*iter)->get_display_code() << (*iter)->get_id() << endl;
        (*iter)->save(file);
    }
}

//
//void Model::restore(ifstream& file) {
//    
//    string line;
//    // need to delete everything first
//    this->~Model();
//    getline(file,line);
//    time=atoi(line.c_str());
//    int num_elements;
//    getline(file,line);
//    num_elements=atoi(line.c_str());
//    
//    char type;
//    string s_id;
//    int id;
//    CartPoint location = CartPoint();
//    
//    for (int i=0; i < num_elements; i++) {
//        getline(file,line);
//        type= line[0];
//        s_id = line[1];
//        id=atoi(s_id.c_str());
//        
//        // transform upper to lowercase letter (easier switch)
//        int ascii;
//        ascii= type;
//        if ( ascii < 97) ascii += 32;
//        type= ascii;
//        // create all + add appropriate list
//        switch (type) {
//            case 'g': {
//                Gold_Mine *temp_g = new Gold_Mine(id,location);
//                object_ptrs.push_back(temp_g);
//                active_ptrs.push_back(temp_g);
//                mine_ptrs.push_back(temp_g);
//                break;}
//            case 't': {
//                Town_Hall *temp_h = new Town_Hall(id,location);
//                object_ptrs.push_back(temp_h);
//                active_ptrs.push_back(temp_h);
//                hall_ptrs.push_back(temp_h);
//                break;}
//            case 'm':{
//                Miner *temp_m = new Miner(id,location);
//                object_ptrs.push_back(temp_m);
//                active_ptrs.push_back(temp_m);
//                person_ptrs.push_back(temp_m);
//                break;}
//            case 's':{
//                Soldier *temp_s = new Soldier(id,location);
//                object_ptrs.push_back(temp_s);
//                active_ptrs.push_back(temp_s);
//                person_ptrs.push_back(temp_s);
//                
//                break;}
//            case 'i':{
//                Inspector *temp_i = new Inspector(id,location);
//                object_ptrs.push_back(temp_i);
//                active_ptrs.push_back(temp_i);
//                person_ptrs.push_back(temp_i);
//                break;}
//        }
//    }
//    
//    
//    // end function
//}