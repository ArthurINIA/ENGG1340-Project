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
    int food = 350, fuel = 100, metal = 100, population = 10000, tanks = 0, soldiers = 0, max_population = 0;
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
    int build_limit = 50, qty_owned = 0;
    Resources cost, production;
    // void init(std::string s1, std::string s2, std::string s3);
};
std::ostream &operator<<(std::ostream &os, Resources const &x);
std::ostream &operator<<(std::ostream &os, Building const &x);
// class objects that share between interfaces
extern Resources player, AI[4];
// extern Building oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;
extern std::map<std::string, Building> building;

// testing code
void printNum(std::string s);

#endif
