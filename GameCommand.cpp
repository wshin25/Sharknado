//
//  GameCommand.cpp
//  PA3
//

//#include <stdio.h>
#include "GameCommand.h"
//#include "CartPoint.h"
//#include "Model.h"
//#include "Fish.h"
//#include "CoralReef.h"
//#include "Cave.h"
#include "InputHandling.h"
//#include "Shark.h"
//#include "Sharknado.h"


using namespace std;

void do_swim_command(Model&	model)
{
    int fish_id;
    double x_in,y_in;
    cin >> fish_id >> x_in >> y_in;
    CartPoint * cpPtr = new CartPoint(x_in,y_in);
    Fish* fishPtr = model.get_Fish_ptr(fish_id);
    fishPtr->start_swimming(*cpPtr);
}

void do_go_command(Model& model)
{
    cout << "Advancing one tick" << endl;
    model.update();
}

void do_run_command(Model& model)
{
    cout << "Advancing to next event" << endl;
    bool update = false;
    int counter = 0;
    while (update == false && counter < 5) {
        update = model.update();
        counter++;
    }
}

void do_eat_command(Model& model)
{
    int fish_id,reef_id;
    cin >> fish_id >> reef_id;
    CoralReef* reefPtr = model.get_CoralReef_ptr(reef_id);
    Fish* fishPtr = model.get_Fish_ptr(fish_id);
    fishPtr->start_eating(reefPtr);
}

void do_float_command(Model& model)
{
    int fish_id;
    if(!(cin >> fish_id))
        throw InvalidInput("Was expecting an integer");
    Fish* fishPtr = model.get_Fish_ptr(fish_id);
    if (fishPtr == (Fish*)NULL)
        throw InvalidInput("Invalid Fish ID");
    fishPtr->float_in_place();
}

void do_zoom_command(Model&	model)
{
    int fish_id,cave_id;
    if(!(cin >> fish_id))
        throw InvalidInput("Was expecting an integer");
    if(!(cin >> cave_id))
        throw InvalidInput("Was expecting an integer");
    Cave* cavePtr = model.get_Cave_ptr(cave_id);
    if (cavePtr == (Cave*)NULL)
        throw InvalidInput("Invalid Cave ID");
    Fish* fishPtr = model.get_Fish_ptr(fish_id);
    if (fishPtr == (Fish*)NULL)
        throw InvalidInput("Invalid Fish ID");
    fishPtr->start_hiding(cavePtr);
}

void do_attack_command(Model& model)
{
    int fish_id1, fish_id2;
    cin >> fish_id1 >> fish_id2;
    if(!fish_id1 || !fish_id2)
        throw InvalidInput("Was expecting an integer");
    Fish* fishPtr1 = model.get_Fish_ptr(fish_id1);
    if (fishPtr1 == (Fish*)NULL)
        throw InvalidInput("Invalid Predator Fish ID");
    Fish* fishPtr2 = model.get_Fish_ptr(fish_id2);
    if (fishPtr2 == (Fish*)NULL)
        throw InvalidInput("Invalid Prey Fish ID");
    fishPtr1->start_attack(fishPtr2);
}

void handle_new_command(Model& model)
{
    char type;
    int id,id_home;
    double x,y;
    
    if (!(cin >> type))
        throw InvalidInput(" Was expecting a character");
    if (type == 's') {
        cin >> id;
        Shark* sharkPtr = model.add_Shark_ptr(id);
        if (sharkPtr == (Shark*)NULL)
            throw InvalidInput("Invalid Shark ID");
        model.add_new_object(sharkPtr);
    }
    else if (type == 't') {
        cin >> id >> id_home;
        Tuna* tunaPtr = model.add_Tuna_ptr(id,id_home);
        if (tunaPtr == (Tuna*)NULL)
            throw InvalidInput("Invalid Tuna ID");
        model.add_new_object(tunaPtr);
    }
    else {
        cin >> id >> x >> y;
        if (type == 'c') {
            Cave* cavePtr = model.add_Cave_ptr(id,x,y);
            if (cavePtr == (Cave*)NULL)
                throw InvalidInput("Invalid Cave ID");
            model.add_new_object(cavePtr);
        }
        else if (type == 'r') {
            CoralReef* reefPtr = model.add_CoralReef_ptr(id,x,y);
            if (reefPtr == (CoralReef*)NULL)
                throw InvalidInput("Invalid Coral Reef ID");
            model.add_new_object(reefPtr);
        }
    }
}

void do_save_command(Model& model)
{
    string namefile;
    // input name file
    cin >> namefile;
    // add extension
    namefile += ".txt";
    // save model in it
    ofstream file;
    file.open(namefile.c_str());
    if (file.is_open()) {
        model.save(file);
        file.close();
        cout << "Game saved" << endl;
    }
    else {
        cout << "File could not be opened" << endl;
    }
    View view= View();
    model.display(view);
}