#include "all_interface.h"
#include "main.h"
#include "struct.h"
#include "UI.h"
#include <string>
using namespace std;

map<string, Building> building;

/*string struct_to_string(Resources res){
    string result = to_string()
}*/

void init_interface_2()
{
    // cout << "Your country resources:\n" << player; //success
    building["oil refinery"] = Building();
    // cout << "oil-refinery " << building.count("oil-refinery") << endl; // success
    //  food fuel metal population
    building["oil refinery"].name = "oil-refinery";
    building["oil refinery"].requirement = "70 metal";
    building["oil refinery"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["oil refinery"].description = "add 50 units of fuel per round, maximum 2 per land";
    building["oil refinery"].production.init(0, 50, 0, 0, 0, 0, 0, 0);
    building["oil refinery"].effect = "50 fuel";
    building["oil refinery"].qty_owned = 2;
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

    building["recruiting office"] = Building(); // extra resouces needed
    building["recruiting office"].name = "recruiting office";
    building["recruiting office"].requirement = "10 metal";
    building["recruiting office"].cost.init(0, 0, 10, 0, 0, 0, 0, 0);
    building["recruiting office"].description = "recruit 750 units of soldiers per round. Maximum 1 recruiting office per land.";
    building["recruiting office"].production.init(0, 0, 0, 0, 0, 750, 0, 0);
    building["recruiting office"].effect = "recruit 750 units of soldiers per round.";
    building["recruiting office"].qty_owned = 0;

    building["house"] = Building(); // extra resouces needed
    building["house"].name = "house";
    building["house"].requirement = "20 metal, 20 fuel";
    building["house"].cost.init(0, 20, 20, 0, 0, 0, 0, 0);
    building["house"].description = "Increase population limit by 1000. Initially 5 houses.";
    building["house"].production.init(0, 0, 0, 0, 0, 0, 0, 1000);
    building["house"].effect = "Increase population limit by 1000.";
    building["house"].qty_owned = 5;

    building["military laboratory"] = Building(); // extra variables needed?
    building["military laboratory"].name = "military laboratory";
    building["military laboratory"].requirement = "upgrade needs 30% metal, 30% fuel";
    building["military laboratory"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["military laboratory"].description = "Boost 30% power of militrary force per upgrade.";
    building["military laboratory"].production.init(0, 0, 50, 0, 0, 0, 0.05, 0);
    building["military laboratory"].effect = "30% military factor";
    building["military laboratory"].qty_owned = 1;

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
    vector<string> content;
    // show default information/ interface2
    if (cmd[0] == "to" && (cmd[1] == "i2" || cmd[1] == "internal") && cmd.size() == 2)
    {
        show_internal(content);
    }
    if (cmd[2] == "show")
    {
        if (cmd[3] == "built")
        {
            vector<string> built_vec;
            for (map<string, Building>::iterator it = building.begin(); it != building.end(); ++it)
            {
                built_vec.push_back(it->first + ": Owned " + to_string(it->second.qty_owned));
            }
            content = built_vec;
            show_internal(content);
        }
        else if (cmd[3] == "buildable")
        {
            content = list_buildable(); // show available buildings
            show_internal(content);
        }
        else if (cmd[3] == "info")
        {
            if (cmd.size() > 4)
            {
                if (building.count(cmd[4]) > 0)
                {
                    vector<string> info_vec;
                    info_vec.push_back("Name: " + building[cmd[4]].name);
                    info_vec.push_back("Requirement: " + building[cmd[4]].requirement);
                    info_vec.push_back("Cost: " + to_string(building[cmd[4]].cost));
                    info_vec.push_back("Description: " + building[cmd[4]].description);
                    info_vec.push_back("Production: " + to_string(building[cmd[4]].production));
                    show_internal(content);
                }
                else
                {
                    cout << "We do not have this building option" << endl;
                }
            }
            else
            {
                cout << "info of all buildings" << endl;
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
            cout << "please add quantity and then the name of building." << endl;
        }
        else if (cmd.size() >= 3 && building.count(cmd[2]))
        {
            cout << "success3" << endl; // testing
            // bulding count + cmd[1]
        }
        else
        {
            cout << "Unsuccessful Command" << endl;
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
        set<int> x;
        if (it->second.build_limit)
            x.insert(it->second.build_limit);
        Resources cur = it->second.cost;
        if (player.food && cur.food && player.food >= cur.food)
            x.insert(player.food / cur.food);
        if (player.fuel && cur.fuel && player.fuel >= cur.fuel)
            x.insert(player.fuel / cur.fuel);
        if (player.metal && cur.metal && player.metal >= cur.metal)
            x.insert(player.metal / cur.metal);
        if (player.population && cur.population && player.population >= cur.population)
            x.insert(player.population / cur.population);
        if (!x.empty())
            show.push_back(it->first + " : Right now you can buy at most " + to_string(*x.begin()));
    }
    // cout << show;
    return show;
}