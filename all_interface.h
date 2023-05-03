#ifndef ALL_INTERFACE_H
#define ALL_INTERFACE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include "UI.h"

extern UI gameScreen, startScreen;

void init_interface_2();
void init_i3();

void run_interface_1(std::vector<std::string> &cmd);
void run_interface_2(std::vector<std::string> &cmd);
void run_interface_3(std::vector<std::string> &cmd);
void run_interface_4(std::vector<std::string> &cmd);

void show_data();
void internal_actions();
void external_actions();
void round_result();

// classes
class Military_Resouces
{
public:
    int soldier = 0, tank = 0;
};
class Resources : public Military_Resouces
{
public:
    int food = 350, fuel = 100, metal = 100, population = 10000;
    int max_population = 0, livelihood = 50, military = 50, diplomacy = 50;
    double military_factor = 0;
    Resources() : food(0), fuel(0), metal(0), population(0), military_factor(0), max_population(0) {}
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
std::ostream &operator<<(std::ostream &os, Resources const &x);
std::ostream &operator<<(std::ostream &os, Building const &x);
// class objects that share between interfaces
extern Resources player, AI[3], buffer;
// extern Building oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;
extern std::map<std::string, Building> building;

//world map material
class i3Map{
    public:
        Military_Resouces army[4];
        string owner = "nobody";
};
extern i3Map wldMap[4][4];

//NPC functions
bool check_res(Resources res);
bool AI_check_res(std::string name, Resources res);
void execute_AI_actions(const std::string &curCountry);

// testing code
void printNum(std::string s);

#endif
