// d2boh.h

#ifndef ALL_INTERFACE_H
#define ALL_INTERFACE_H

#include<iostream>
#include<string>
#include<vector>

void run_interface_1(std::vector<std::string> &cmd);
void run_interface_2(std::vector<std::string> &cmd);
void run_interface_3(std::vector<std::string> &cmd);
void run_interface_4(std::vector<std::string> &cmd);

void show_data();
void internal_actions();
void external_actions();
void round_result();

//testing code
void printNum(std::string s);

#endif
