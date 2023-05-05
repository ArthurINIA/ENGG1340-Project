#include "all_interface.h"
using namespace std;

void init_interface_2()
{
    // food, fuel, metal, ppl, tank, soldier, milFac, maxPop;
    building["farm"] = Building();
    building["farm"].name = "farm";
    building["farm"].requirement = "25 metal";
    building["farm"].cost.init(0, 0, 25, 0, 0, 0, 0, 0);
    building["farm"].description = "add 500 units of food per round.";
    building["farm"].production.init(500, 0, 0, 0, 0, 0, 0, 0);
    building["farm"].effect = "500 food";
    building["farm"].init_qty = 0;
    building["farm"].limit_per_land = 20;

    building["oil-refinery"] = Building();
    building["oil-refinery"].name = "oil-refinery";
    building["oil-refinery"].requirement = "70 metal";
    building["oil-refinery"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["oil-refinery"].description = "add 50 units of fuel per round.";
    building["oil-refinery"].production.init(0, 50, 0, 0, 0, 0, 0, 0);
    building["oil-refinery"].effect = "50 fuel";
    building["oil-refinery"].init_qty = 2;
    building["oil-refinery"].limit_per_land = 2;

    building["mine"] = Building();
    building["mine"].name = "mine";
    building["mine"].requirement = "70 metal";
    building["mine"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["mine"].description = "add 50 units of metal per round.";
    building["mine"].production.init(0, 0, 50, 0, 0, 0, 0, 0);
    building["mine"].effect = "50 metal";
    building["mine"].init_qty = 0;
    building["mine"].limit_per_land = 2;

    building["house"] = Building();
    building["house"].name = "house";
    building["house"].requirement = "20 metal, 20 fuel";
    building["house"].cost.init(0, 20, 20, 0, 0, 0, 0, 0);
    building["house"].description = "Increase citizen limit by 1000. Initially 5 houses.";
    building["house"].production.init(0, 0, 0, 1000, 0, 0, 0, 0);
    building["house"].effect = "Increase citizen by 1000.";
    building["house"].init_qty = 5;
    building["house"].limit_per_land = 20;

    building["recruiting-office"] = Building();
    building["recruiting-office"].name = "recruiting office";
    building["recruiting-office"].requirement = "10 metal";
    building["recruiting-office"].cost.init(0, 0, 10, 0, 0, 0, 0, 0);
    building["recruiting-office"].description = "recruit 300 units of soldiers per round.";
    building["recruiting-office"].production.init(0, 0, 0, 0, 0, 300, 0, 0);
    building["recruiting-office"].effect = "recruit 300 units of soldiers per round.";
    building["recruiting-office"].init_qty = 0;
    building["recruiting-office"].limit_per_land = 3;

    building["factory"] = Building();
    building["factory"].name = "factory";
    building["factory"].requirement = "120 metal, 500 citizen";
    building["factory"].cost.init(0, 0, 120, 500, 0, 0, 0, 0);
    building["factory"].description = "add 10 units of tank if have 300 metal and 300 fuel.";
    building["factory"].production.init(0, 0, 0, 0, 10, 0, 0, 0);
    building["factory"].effect = "10 tank unit";
    building["factory"].init_qty = 0;
    building["factory"].limit_per_land = 1;

    /*
    building["military-laboratory"] = Building(); // extra variables needed?
    building["military-laboratory"].name = "military laboratory";
    building["military-laboratory"].requirement = "upgrade needs 30% metal, 30% fuel";
    building["military-laboratory"].cost.init(0, 0, 70, 0, 0, 0, 0, 0);
    building["military-laboratory"].description = "Boost 30% power of militrary force per upgrade.";
    building["military-laboratory"].production.init(0, 0, 50, 0, 0, 0, 0.05, 0);
    building["military-laboratory"].effect = "30% military factor";
    building["military-laboratory"].init_qty = 1;

    building["casino"] = Building(); // extra indexes needed
    building["casino"].name = "casino";
    building["casino"].requirement = "200 metal, 50 fuel";
    building["casino"].cost.init(0, 50, 200, 0, 0, 0, 0, 0);
    building["casino"].description = "Increase index of livelihood.";
    building["casino"].production.init(0, 0, 0, 0, 0, 0, 0, 0);
    building["casino"].effect = "Increase index of livelihood.";
    building["casino"].init_qty = 0;
    */

    // gameScreen init
    gameScreen.divide(1, 1, 120, 5, "resource-bar");
    gameScreen.divide(1, 1, 40, 5, "interface-name");
    gameScreen.divide(40, 1, 60, 5, "resource-1");
    gameScreen.divide(60, 1, 80, 5, "resource-2");
    gameScreen.divide(80, 1, 100, 5, "resource-3");
    gameScreen.divide(100, 1, 120, 5, "resource-4");
    gameScreen.divide(1, 5, 40, 29, "manual");
    gameScreen.divide(40, 5, 120, 29, "game-content");
}

void show_internal(vector<string> content, string hAlign = "center")
{
    string s;
    string str1 = "Food: " + to_string(player[0].food), str2 = "Fuel: " + to_string(player[0].fuel), str3 = "Metal: " + to_string(player[0].metal), str4 = "Citizen: " + to_string(player[0].citizen);
    gameScreen.drawAll("interface-name", "center", {"Day : " + to_string(curGameDay), "Interface 2: Internal Action"});
    gameScreen.drawAll("resource-1", "center", {str1});
    gameScreen.drawAll("resource-2", "center", {str2});
    gameScreen.drawAll("resource-3", "center", {str3});
    gameScreen.drawAll("resource-4", "center", {str4});
    gameScreen.divide(40, 5, 120, 29, "game-content");
    gameScreen.drawAll("game-content", hAlign, content);
    vector<string> i2_sidebarInfo = {"Command List:", "show buildable", "show info", "build", "to i1", "to i3", "to i4", "end", "quit", "help"};
    gameScreen.drawAll("manual", "center", i2_sidebarInfo);
    gameScreen.print();
}

vector<string> list_buildable();

void run_interface_2(vector<string> &cmd)
{
    vector<string> content;
    // show default information/ interface2
    if (cmd[0] == "to")
    {
        content = list_buildable(); // show available buildings
        content.push_back(" ");
        content.push_back("  Everyday the normal citizen eat 1 unit of food, solider eat 2.");
        show_internal(content);
    }
    else if (cmd[0] == "show")
    {
        if (cmd.size() < 3)
        {
            vector<string> guide = {"You can type:", "show built", "show buildable", "show info BUILDING_NAME"};
            show_internal(guide);
            return;
        }
        if (cmd[1] == "built")
        {
            vector<string> built_vec;
            for (map<string, Building>::iterator it = building.begin(); it != building.end(); ++it)
            {
                built_vec.push_back(it->first + ": Owned " + to_string(player[0].qty_owned[it->first]));
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
                    info_vec.push_back("  Name: " + building[cmd[2]].name);
                    info_vec.push_back("  Requirement: " + building[cmd[2]].requirement);
                    info_vec.push_back("  Cost: " + to_string(building[cmd[2]].cost.food) + " food, " + to_string(building[cmd[2]].cost.fuel) + " fuels, " + to_string(building[cmd[2]].cost.metal) + " metal, " + to_string(building[cmd[2]].cost.citizen) + " citizen");
                    info_vec.push_back("  Description: " + building[cmd[2]].description);
                    info_vec.push_back("  Production: " + to_string(building[cmd[2]].production.food) + " food, " + to_string(building[cmd[2]].production.fuel) + " fuels, " + to_string(building[cmd[2]].production.metal) + " matal, " + to_string(building[cmd[2]].production.citizen) + " citizen");
                    info_vec.push_back("  " + to_string(building[cmd[2]].production.tank) + " tank, " + to_string(building[cmd[2]].production.soldier) + " soldiers, " + to_string(building[cmd[2]].production.military_factor) + " military factor, " + to_string(building[cmd[2]].production.max_population) + " max citizen");
                    content = info_vec;
                    show_internal(content, "left");
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
            return;
        }
        if (!building.count(cmd[2]))
        {
            show_internal(vector<string>{"Doesn't exist such building"});
            return;
        }

        int qty = -1;
        bool ok_to_stoi = true;
        for (char c : cmd[1])
            if (!isdigit(c))
                ok_to_stoi = false;
        if (ok_to_stoi)
            qty = stoi(cmd[1]);
        if (qty == -1)
        {
            show_internal(vector<string>{"Invalid quantity of the building"});
            return;
        }

        if (player[0].build_lim[cmd[2]] < player[0].qty_owned[cmd[2]] + qty)
        {
            show_internal(vector<string>{"Building Limit of " + cmd[2] + " has reached"});
            return;
        }

        if (!check_res(0, building[cmd[2]].cost))
        {
            show_internal(vector<string>{"Unsuccess purchase.", " ", "Not enough resources to pay for."});
            return;
        }

        // finally can perform purchase
        player[0].qty_owned[cmd[2]] += qty;
        player[0].food -= building[cmd[2]].cost.food * qty;
        player[0].fuel -= building[cmd[2]].cost.fuel * qty;
        player[0].metal -= building[cmd[2]].cost.metal * qty;
        player[0].citizen -= building[cmd[2]].cost.citizen * qty;

        vector<string> build_vec;
        build_vec.push_back(cmd[1] + " " + cmd[2] + " are built successfully.");
        show_internal(build_vec);
    }
    else
    {
        cout << "Invalid command" << endl;
    }
}

vector<string> list_buildable()
{
    vector<string> show;
    for (string bu : buildingList)
    {
        int build_count = player[0].build_lim[bu] - player[0].qty_owned[bu];
        Resources cur = building[bu].cost;
        if (cur.food)
            build_count = min(build_count, player[0].food / cur.food);

        if (cur.fuel)
            build_count = min(build_count, player[0].fuel / cur.fuel);

        if (cur.metal)
            build_count = min(build_count, player[0].metal / cur.metal);

        if (cur.citizen)
            build_count = min(build_count, player[0].citizen / cur.citizen);
        show.push_back(bu + " : Right now you can buy at most " + to_string(build_count));
    }

    return show;
}
