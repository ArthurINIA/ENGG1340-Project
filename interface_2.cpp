#include "all_interface.h"
#include "main.h"
#include "struct.h"
using namespace std;

map<string, Building> building;

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

void show_internal_heading()
{   
    system("clear"); 
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    // cout << "|";
}

void list_buildable();

void run_interface_2(vector<string> &cmd)
{
    // show default information/ interface2
    show_internal_heading();
    if (cmd[0] == "to")
    {
        cout << "interface 2" << endl; // testing
    }
    else if (cmd[0] == "show")
    {
        if (cmd[1] == "built")
        {
            // show all quantity of building
        }
        else if (cmd[1] == "buildable")
        {
            list_buildable(); // show available buildings
        }
        else if (cmd[1] == "info")
        {
            if (cmd.size() > 2)
            {
                if (building.count(cmd[2]))
                {
                    // show info
                    cout << building[cmd[2]];
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

void list_buildable()
{
    map<string, Building>::iterator it;
    ///*
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
            cout << setw(16) << it->first << " : Right now you can buy at most " << *x.begin() << endl;
    }
    //*/
    /*
    for(it = building.begin(); it != building.end(); it++){ 
        set<int> x;
        if(it->second.build_limit) x.insert(it->second.build_limit);
        Resources cur = it->second.cost;
        if(buffer.food && cur.food && buffer.food >= cur.food) x.insert(buffer.food / cur.food);
        if(buffer.fuel && cur.fuel && buffer.fuel >= cur.fuel) x.insert(buffer.fuel / cur.fuel);
        if(buffer.metal && cur.metal && buffer.metal >= cur.metal) x.insert(buffer.metal / cur.metal);
        if(buffer.ppl && cur.ppl && buffer.ppl >= cur.ppl) x.insert(buffer.ppl / cur.ppl);
        if(!x.empty()) 
            cout << setw(16) << it->first << " : Right now you can buy at most " << *x.begin() << endl;  
    }
    */
}