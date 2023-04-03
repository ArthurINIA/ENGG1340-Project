#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
//list of functions

//utility functions
std::vector<std::string> split(std::string raw_line);
//game procedure functions
void printIntro();
void pick_random_event();
void processAction(std::string cmd);
void end_game();


#endif