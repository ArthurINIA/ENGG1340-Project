#include "all_interface.h"
#include "main.h"
#include "UI.h"
#include <string>
#include <algorithm>
using namespace std;

std::map<string, Building> building;
/*string struct_to_string(Resources res)
{
    string result = "Food: " + to_string(res.food) + "Fuel: " + to_string(res.fuel) + "Metal: " + to_string(res.metal) + "Population: " + to_string(res.population);
}*/

bool check_res(Resources res)
{
    // cout << player.food << " " << res.food << " " << player.fuel << " " << res.fuel << " " << player.metal << " " << res.metal << " " << player.population << " " << res.population;
    if (player.food > res.food && player.fuel > res.fuel && player.metal > res.metal && player.population > res.population)
    {
        cout << "true";
        return true;
    }
    else
    {
        cout << "false";
        return false;
    }
}

void init_interface_2()
{
    // cout << "Your country resources:\n" << player; //success
    // building["oil refinery"] = Building();
    // cout << "oil-refinery " << building.count("oil-refinery") << endl; // success
    //  food fuel metal population
    building["oil-refinery"].name = "oil-refinery";
    building["oil-refinery"].requirement = "70 metal";
    building["oil-refinery"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["oil-refinery"].description = "add 50 units of fuel per round, maximum 2 per land";
    building["oil-refinery"].production.init(0, 50, 0, 0, 0, 0, 0, 0);
    building["oil-refinery"].effect = "50 fuel";
    building["oil-refinery"].qty_owned = 2;
    // cout << building["oil-refinery"]; //success

    building["factory"] = Building(); // extra resouces needed
    building["factory"].name = "factory";
    building["factory"].requirement = "120 metal, 500 population";
    building["factory"].cost.init(0, 0, 120, 500, 0, 0, 0, 0);
    building["factory"].description = "add 10 units of tank if choose so. 10 unit cost 300 metal and 300 fuel.";
    building["factory"].production.init(0, 0, 0, 0, 10, 0, 0, 0);
    building["factory"].effect = "10 tank unit";
    building["factory"].qty_owned = 0;

    building["farm"] = Building();
    building["farm"].name = "farm";
    building["farm"].requirement = "25 metal";
    building["farm"].cost.init(0, 0, 25, 0, 0, 0, 0, 0);
    building["farm"].description = "add 500 units of food per round.";
    building["farm"].production.init(500, 0, 0, 0, 0, 0, 0, 0);
    building["farm"].effect = "500 food";
    building["farm"].qty_owned = 0;

    building["mine"] = Building();
    building["mine"].name = "mine";
    building["mine"].requirement = "70 metal";
    building["mine"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["mine"].description = "add 50 units of metal per round. Maximum 3 mines per land.";
    building["mine"].production.init(0, 0, 50, 0, 0, 0, 0, 0);
    building["mine"].effect = "50 metal";
    building["mine"].qty_owned = 0;

    building["recruiting-office"] = Building(); // extra resouces needed
    building["recruiting-office"].name = "recruiting office";
    building["recruiting-office"].requirement = "10 metal";
    building["recruiting-office"].cost.init(0, 0, 10, 0, 0, 0, 0, 0);
    building["recruiting-office"].description = "recruit 750 units of soldiers per round. Maximum 1 recruiting office per land.";
    building["recruiting-office"].production.init(0, 0, 0, 0, 0, 750, 0, 0);
    building["recruiting-office"].effect = "recruit 750 units of soldiers per round.";
    building["recruiting-office"].qty_owned = 0;

    building["house"] = Building(); // extra resouces needed
    building["house"].name = "house";
    building["house"].requirement = "20 metal, 20 fuel";
    building["house"].cost.init(0, 20, 20, 0, 0, 0, 0, 0);
    building["house"].description = "Increase population limit by 1000. Initially 5 houses.";
    building["house"].production.init(0, 0, 0, 0, 0, 0, 0, 1000);
    building["house"].effect = "Increase population limit by 1000.";
    building["house"].qty_owned = 5;

    building["military-laboratory"] = Building(); // extra variables needed?
    building["military-laboratory"].name = "military laboratory";
    building["military-laboratory"].requirement = "upgrade needs 30% metal, 30% fuel";
    building["military-laboratory"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["military-laboratory"].description = "Boost 30% power of militrary force per upgrade.";
    building["military-laboratory"].production.init(0, 0, 50, 0, 0, 0, 0.05, 0);
    building["military-laboratory"].effect = "30% military factor";
    building["military-laboratory"].qty_owned = 1;

    building["casino"] = Building(); // extra indexes needed
    building["casino"].name = "casino";
    building["casino"].requirement = "200 metal, 50 fuel";
    building["casino"].cost.init(0, 50, 200, 0, 0, 0, 0, 0);
    building["casino"].description = "Increase index of livelihood.";
    building["casino"].production.init(0, 0, 0, 0, 0, 0, 0, 0);
    building["casino"].effect = "Increase index of livelihood.";
    building["casino"].qty_owned = 0;
}

void show_internal(vector<string> content)
{
    // cout << "+-------------------------------------------------------------------------------------+" << endl;
    //  cout << "|";
    UI gameScreen;
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

    gameScreen.drawAll("interface-name", "center", {"Interface 2: Internal Action"});
    gameScreen.drawAll("resource-1", "center", vec1);
    gameScreen.drawAll("resource-2", "center", vec2);
    gameScreen.drawAll("resource-3", "center", vec3);
    gameScreen.drawAll("resource-4", "center", vec4);
    gameScreen.drawAll("game-content", "center", content);
    gameScreen.drawLineStart("manual");
    gameScreen.drawLine("center", "user manual");
    gameScreen.drawLine("center", "sdfsdfsdf");
    gameScreen.drawLineStop();
    gameScreen.print();
}

vector<string> list_buildable();

void run_interface_2(vector<string> &cmd)
{
    init_interface_2();
    vector<string> content;
    // show default information/ interface2
    if (cmd[0] == "to" && (cmd[1] == "i2" || cmd[1] == "internal") && cmd.size() == 2)
    {
        show_internal(content);
    }
    else if (cmd[0] == "show")
    {
        if (cmd[1] == "built")
        {
            vector<string> built_vec;
            for (map<string, Building>::iterator it = building.begin(); it != building.end(); ++it)
            {
                built_vec.push_back(it->first + ": Owned " + to_string(it->second.qty_owned));
            }
            content = built_vec;
            show_internal(content);
        }
        else if (cmd[1] == "buildable")
        {
            content = list_buildable(); // show available buildings
            show_internal(content);
        }
        else if (cmd[1] == "info")
        {
            if (cmd.size() == 3)
            {
                if (building.count(cmd[2]) > 0)
                {
                    vector<string> info_vec;
                    info_vec.push_back("Name: " + building[cmd[2]].name);
                    info_vec.push_back("Requirement: " + building[cmd[2]].requirement);
                    info_vec.push_back("Cost: " + to_string(building[cmd[2]].cost.food) + " food, " + to_string(building[cmd[2]].cost.fuel) + " fuels, " + to_string(building[cmd[2]].cost.metal) + " metal, " + to_string(building[cmd[2]].cost.population) + " population");
                    info_vec.push_back("Description: " + building[cmd[2]].description);
                    info_vec.push_back("Production: " + to_string(building[cmd[2]].production.food) + " food, " + to_string(building[cmd[2]].production.fuel) + " fuels, " + to_string(building[cmd[2]].production.population) + " population");
                    info_vec.push_back(to_string(building[cmd[2]].production.tanks) + " tanks, " + to_string(building[cmd[2]].production.soldiers) + " soldiers, " + to_string(building[cmd[2]].production.military_factor) + " military factor, " + to_string(building[cmd[2]].production.max_population) + " max population");
                    info_vec.push_back("Quantity: " + to_string(building[cmd[2]].qty_owned));
                    content = info_vec;
                    show_internal(content);
                }
                else
                {
                    cout << "Building option does not exist." << endl;
                }
            }
            else
            {
                cout << "Please enter the building name." << endl;
            }
        }
        else
        {
            cout << "Invalid command" << endl;
        }
    }
    else if (cmd[0] == "build")
    {
        if (cmd.size() < 3)
        {
            show_internal(vector<string>{"Please add quantity and then name of building."});
        }
        else if (cmd.size() == 3 && building.count(cmd[2]) > 0 && stoi(cmd[1]) > 0)
        {
            if (building[cmd[2]].build_limit > building[cmd[2]].qty_owned + stoi(cmd[1]) && check_res(building[cmd[2]].cost))
            {
                building[cmd[2]].qty_owned += stoi(cmd[1]);
                vector<string> build_vec;
                player.food -= building[cmd[2]].cost.food * stoi(cmd[1]);
                player.fuel -= building[cmd[2]].cost.fuel * stoi(cmd[1]);
                player.metal -= building[cmd[2]].cost.metal * stoi(cmd[1]);
                player.population -= building[cmd[2]].cost.population * stoi(cmd[1]);
                build_vec.push_back(cmd[1] + " " + cmd[2] + " are built successfully.");
                show_internal(build_vec);
            }
            else
            {
                vector<string> build_vec = {"Unsuccess command."};
                show_internal(build_vec);
            }
        }
        else
        {
            vector<string> invalid_vec = {"Unsuccess command."};
            show_internal(invalid_vec);
        }
    }
    else
    {
        cout << "Invalid command" << endl;
    }
}

vector<string> list_buildable()
{
    map<string, Building>::iterator it;
    vector<string> show;
    for (it = building.begin(); it != building.end(); it++)
    {
        int build_count = it->second.build_limit;
        Resources cur = it->second.cost;

        if (cur.food)
            build_count = min(build_count, player.food / cur.food);

        if (cur.fuel)
            build_count = min(build_count, player.fuel / cur.fuel);

        if (cur.metal)
            build_count = min(build_count, player.metal / cur.metal);

        if (cur.population)
            build_count = min(build_count, player.population / cur.population);

        show.push_back(it->first + " : Right now you can buy at most " + to_string(build_count));
    }

    return show;
}
