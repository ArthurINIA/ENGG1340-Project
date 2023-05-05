#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include "all_interface.h"
//list of functions

//utility functions
void readLine(std::string &str);
std::vector<std::string> split(std::string raw_line);
void go_interface(int id, std::vector<std::string> &cmd);

//game procedure functions
void start_game();
void printIntro();
void pick_random_event();
void end_game(std::string status);

void npc_decision(int uid);


#endif