#include "all_interface.h"
#include <iostream>
#include <string>
using namespace std;

void show_i1(vector<string> content);

void run_interface_1(vector<string> &cmd)
{
    string food, fuel, metal, population, soldier, tank;
    int add;
    vector<string> show_vec;
    show_vec.push_back("Livelihood index: " + to_string(player.livelihood));
    show_vec.push_back("Military index: " + to_string(player.military));
    show_vec.push_back("Diplomacy index: " + to_string(player.diplomacy));
    add = 1000 + player.livelihood * 5;
    if (add > 0)
    {
        population = "+" + to_string(add);
    }
    else
    {
        population = to_string(add);
    }
    show_vec.push_back("Population round add: " + population);
    add = building["oil-refinery"].qty_owned * building["oil-refinery"].production.fuel;
    if (building["factory"].qty_owned > 0)
    {
        add -= min(player.metal / 300, player.fuel / 300) * 300;
    }
    if (add > 0)
    {
        fuel = "+" + to_string(add);
    }
    else
    {
        fuel = to_string(add);
    }
    show_vec.push_back("Fuel round add: " + fuel);
    add = building["mine"].qty_owned * building["mine"].production.metal;
    if (building["factory"].qty_owned > 0)
    {
        add -= min(player.metal / 300, player.fuel / 300) * 300;
    }
    if (add > 0)
    {
        metal = "+" + to_string(add);
    }
    else
    {
        metal = to_string(add);
    }
    show_vec.push_back("Metal round add: " + metal);
    add = building["farm"].qty_owned * building["farm"].production.food - player.soldier * 0.1;
    if (add > 0)
    {
        food = "+" + to_string(add);
    }
    else
    {
        food = to_string(add);
    }
    show_vec.push_back("Food round add: " + food);
    add = building["recruiting-office"].qty_owned * building["recruiting-office"].production.soldier;
    if (player.soldier + add > player.population)
    {
        add = player.population - player.soldier;
    }
    soldier = "+" + to_string(add);
    show_vec.push_back("Soldier round add: " + soldier);
    add = building["factory"].qty_owned * building["factory"].production.tank;
    if (building["factory"].qty_owned * 300 > player.metal || building["factory"].qty_owned * 300 > player.fuel)
    {
        for (int i = building["factory"].qty_owned; i != 0; i--)
        {
            if (i * 300 > player.metal && i * 300 > player.fuel)
            {
                add = i * building["factory"].production.tank;
                break;
            }
            add = 0;
        }
    }
    tank = "+" + to_string(add);
    show_vec.push_back("Tank round add: " + tank);
    /*for (map<string, Building>::iterator it = building.begin(); it != building.end(); ++it)
    {
        int x = building[it->first].qty_owned * building[it->first].production.food - player.soldier * 0.1;
        built_vec.push_back(it->first + ": Owned " + to_string(it->second.qty_owned));
    }*/
    show_i1(show_vec);
}

void show_i1(vector<string> content)
{

    string s;
    string str1 = "Food: " + to_string(player.food), str2 = "Fuel: " + to_string(player.fuel), str3 = "Metal: " + to_string(player.metal), str4 = "Population: " + to_string(player.population);
    // cout << content << endl;
    vector<string> vec1 = {str1}, vec2 = {str2}, vec3 = {str3}, vec4 = {str4};
    gameScreen.divide(1, 1, 120, 5, "resource-bar");
    gameScreen.divide(1, 1, 40, 5, "interface-name");
    gameScreen.divide(40, 1, 60, 5, "resource-1");
    gameScreen.divide(60, 1, 80, 5, "resource-2");
    gameScreen.divide(80, 1, 100, 5, "resource-3");
    gameScreen.divide(100, 1, 120, 5, "resource-4");
    gameScreen.divide(1, 5, 40, 29, "manual");
    gameScreen.divide(40, 5, 120, 29, "game-content");

    gameScreen.drawAll("interface-name", "center", {"Interface 1: Fundemental Data"});
    gameScreen.drawAll("resource-1", "center", vec1);
    gameScreen.drawAll("resource-2", "center", vec2);
    gameScreen.drawAll("resource-3", "center", vec3);
    gameScreen.drawAll("resource-4", "center", vec4);
    gameScreen.drawAll("game-content", "center", content);
    vector<string> i1_sidebarInfo = {"Command List", "to i2", "to i3", "to i4", "end", "quit", "help"};
    gameScreen.drawAll("manual", "center", i1_sidebarInfo);
    gameScreen.print();
}

// testing code
void printNum(string s)
{
    cout << stoi(s) << endl;
}

/*void printUI1()
{
    cout << "+-----------------------------------------------------------------------------+" << endl;
    cout << "|                               Interface 1                                   |" << endl;
    cout << "|-----------------------------------------------------------------------------|" << endl;
    cout << "|*Resource 01: Food                                                          *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 02: Fuel                                                          *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 03: Metal                                                         *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 04: Population                                                    *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*City index 01: Diplomacy                                                   *|" << endl;
    cout << "|*Rate:                                                                      *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*City index 02: Livelihood                                                  *|" << endl;
    cout << "|*Rate:                                                                      *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*City index 03: Military                                                    *|" << endl;
    cout << "|*Rate:                                                                      *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|                                   Done!                                     |" << endl;
    cout << "+-----------------------------------------------------------------------------+" << endl;
}*/

/*int main(){
    //test printNum
    string num;
    cin >> num;
    printNum(num);
}*/
