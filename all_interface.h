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

bool check_res(Resources res);
bool AI_check_res(string name, Resources res)
{
    if (name == "PC1")
    {
        // cout << player.food << " " << res.food << " " << player.fuel << " " << res.fuel << " " << player.metal << " " << res.metal << " " << player.population << " " << res.population;
        if (AI[0].food > res.food && AI[0].fuel > res.fuel && AI[0].metal > res.metal && AI[0].population > res.population)
        {
            // cout << "true";
            return true;
        }
        else
        {
            // cout << "false";
            return false;
        }
    }
    else if (name == "PC2")
    {
        // cout << player.food << " " << res.food << " " << player.fuel << " " << res.fuel << " " << player.metal << " " << res.metal << " " << player.population << " " << res.population;
        if (AI[1].food > res.food && AI[1].fuel > res.fuel && AI[1].metal > res.metal && AI[1].population > res.population)
        {
            // cout << "true";
            return true;
        }
        else
        {
            // cout << "false";
            return false;
        }
    }
    else if (name == "PC1")
    {
        // cout << player.food << " " << res.food << " " << player.fuel << " " << res.fuel << " " << player.metal << " " << res.metal << " " << player.population << " " << res.population;
        if (AI[2].food > res.food && AI[2].fuel > res.fuel && AI[2].metal > res.metal && AI[2].population > res.population)
        {
            // cout << "true";
            return true;
        }
        else
        {
            // cout << "false";
            return false;
        }
    }
}

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
std::ostream &operator<<(std::ostream &os, Resources const &x);
std::ostream &operator<<(std::ostream &os, Building const &x);
// class objects that share between interfaces
extern Resources player, AI[3], buffer;
// extern Building oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;
extern std::map<std::string, Building> building;

// testing code
void printNum(std::string s);

#endif
