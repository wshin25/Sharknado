//
//  PA4.cpp
//  PA3
//

#include <stdio.h>
#include "GameObject.h"
#include "GameCommand.h"
#include "CartPoint.h"
#include "Model.h"
#include "Fish.h"
#include "Cave.h"
#include "CoralReef.h"
#include "View.h"
#include "InputHandling.h"
#include "Sharknado.h"

using namespace std;
int main() {
    
    Model model = Model();
    model.show_status();
    
    View view = View();
    char command;
    model.display(view);
    
    do {
        cout << "Enter command: ";
        cin >> command;
        try {
            switch (command){
                case 's':
                    do_swim_command(model);
                    break;
                case 'e':
                    do_eat_command(model);
                    break;
                case 'f':
                    do_float_command(model);
                    break;
                case 'z':
                    do_zoom_command(model);
                    break;
                case 'g':
                    do_go_command(model);
                    model.show_status();
                    break;
                case 'r':
                    do_run_command(model);
                    model.show_status();
                    break;
                case 'a':
                    do_attack_command(model);
                    model.show_status();
                    break;
                case 'n':
                    handle_new_command(model);
                    //model.show_status();
                    break;
                case 'q':
                    model.show_history();
                    break;
                case 'S':
                    do_save_command(model);
                    break;
            }
            if (command != 'q')
                model.display(view);
        }
        catch (InvalidInput& except)
        {
            cout << "Invalid input - " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(80,'\n');
        }
        
    }while (command != 'q');
    
    return 0;
}
