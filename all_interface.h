#ifndef ALL_INTERFACE_H
#define ALL_INTERFACE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include "main.h"

void init_interface_2();

void run_interface_1(std::vector<std::string> &cmd);
void run_interface_2(std::vector<std::string> &cmd);
void run_interface_3(std::vector<std::string> &cmd);
void run_interface_4(std::vector<std::string> &cmd);

void show_data();
void internal_actions();
void external_actions();
void round_result();

// classes
class Resources
{
public:
    int food = 350, fuel = 100, metal = 100, population = 10000, tanks = 0, soldiers = 0, max_population = 0, livelihood = 50, military = 50, diplomacy = 50;
    double military_factor = 0;
    Resources() : food(0), fuel(0), metal(0), population(0), tanks(0), soldiers(0), military_factor(0), max_population(0) {}
    void init(int v1, int v2, int v3, int v4, int v5, int v6, double v7, int v8);
    Resources &operator+=(const Resources &b);
    Resources &operator-=(const Resources &b);
};
class Building
{
public:
    std::string name, requirement, description, effect;
    int build_limit = 50, qty_owned = 8;
    Resources cost, production;
    // void init(std::string s1, std::string s2, std::string s3);
};

class military_resources{
public:
    int country [16][3] = {{1, 0, 0}, {2, 50000,0}, {3, 70000, 0}, {4, 130000, 0},{5, 70000, 0}, {6, 100000, 0}, {7, 130000, 0}, {8, 180000, 0}, {9, 140000, 0}, {10, 170000, 0}, {11, 250000, 0}, {12, 140000, 0}, {13, 210000, 0}, {14, 270000, 0}, {15, 300000, 0}, {16, 260000, 0}};
    // alliance list
    int alliance [3]={0,0,0};
    int count_alliance = 0;
};
std::ostream &operator<<(std::ostream &os, Resources const &x);
std::ostream &operator<<(std::ostream &os, Building const &x);
// class objects that share between interfaces
extern Resources player, AI[4], buffer;
// extern Building oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;
extern std::map<std::string, Building> building;

// testing code
void printNum(std::string s);

#endif
