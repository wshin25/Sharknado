//
//  GameCommand.h
//  PA3
//

#ifndef __PA3__GameCommand__
#define __PA3__GameCommand__

#include <stdio.h>
#include "Model.h"
#include <string>
#include <fstream>
using namespace std;

void do_swim_command(Model&);
void do_go_command(Model&);
void do_run_command(Model&);
void do_eat_command(Model&);
void do_float_command(Model&);
void do_zoom_command(Model&);
void do_attack_command(Model&);
void handle_new_command(Model&);
void do_save_command(Model&);
//void do_restore_command(Model&);
#endif /* defined(__PA3__GameCommand__) */
