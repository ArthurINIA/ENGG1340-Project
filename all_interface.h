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
#include "main.h"

extern int curGameDay, curCountry;
extern UI gameScreen, startScreen, i4;
extern int starve[4];

void init_interface_2();
void init_i3();
void init_i4();

void run_interface_1(std::vector<std::string> &cmd);
void run_interface_2(std::vector<std::string> &cmd);
void run_interface_3(std::vector<std::string> &cmd);
void run_interface_4(std::vector<std::string> &cmd);

void pick_random_event();
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
    int food = 350, fuel = 100, metal = 100, citizen = 10000;
    int max_population = 0, livelihood = 50, military = 50, diplomacy = 50;
    double military_factor = 0;
    Resources() : food(0), fuel(0), metal(0), citizen(0), military_factor(0), max_population(0) {}
    void init(int v1, int v2, int v3, int v4, int v5, int v6, double v7, int v8);
    Resources &operator+=(const Resources &b);
    Resources &operator-=(const Resources &b);
    Resources &operator*=(const int &b);
    Resources operator*(const int &b);
};
class Building
{
public:
    std::string name, requirement, description, effect;
    int limit_per_land = 30, init_qty = 0;
    Resources cost, production;
};
// world map material
class i3Map
{
public:
    Military_Resouces army[4];
    string owner = "nobody";
};
class Country : public Resources
{
public:
    bool dead = false;
    std::map<std::string, int> build_lim;
    std::map<std::string, int> qty_owned;
};

std::ostream &operator<<(std::ostream &os, Resources const &x);
std::ostream &operator<<(std::ostream &os, Building const &x);

// useful constants that share between interfaces
extern string buildingList[6], countryList[4];
// class objects that share between interfaces
extern Country player[4]; // Player, PC1, PC2, PC3
extern std::map<std::string, Building> building;
extern i3Map wldMap[4][4];

// helper functions
bool check_res(int id, Resources res);
void save_data();
void load_data();
void show_round_result(vector<string> content);

// testing code
void printNum(std::string s);

#endif
