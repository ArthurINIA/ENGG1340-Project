#include "all_interface.h"
#include "main.h"
#include "struct.h"
using namespace std;

map<string, Building> building;


void init_interface_2(){
    //cout << "Your country resources:\n" << player; //success
    building["oil-refinery"] = Building();
    //cout << "oil-refinery " << building.count("oil-refinery") << endl; // success
    building["oil-refinery"].name = "oil-refinery";
    building["oil-refinery"].requirement = "70 metal";
    building["oil-refinery"].cost.init(0, 0, 70, 0);
    building["oil-refinery"].description = "add 50 units of fuel per round, maximum 2 per land";
    building["oil-refinery"].production.init(0, 50, 0, 0);
    building["oil-refinery"].effect = "50 fuel";
    building["oil-refinery"].qty_owned = 2;
    //cout << building["oil-refinery"]; //success

    building["factory"] = Building();


    building["factory"].cost.init(0, 0, 120, 0);

    building["farm"] = Building();


    building["farm"].cost.init(0, 0, 0, 0);

    building["mine"] = Building();


    building["mine"].cost.init(0, 0, 70, 0);



    
    building["mine"].qty_owned = 3;

    
}

void show_internal_heading()
{
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    //cout << "|";
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
            list_buildable();// show available buildings
        }
        else if (cmd[1] == "info")
        {
            if (cmd.size() > 2)
            {
                if (building.count(cmd[2]))
                {
                    // show info
                    cout << "success2" << endl; // testing
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

void list_buildable(){
    map<string, Building>::iterator it;
    for(it = building.begin(); it != building.end(); it++){
        set<int> x;
        if(it->second.build_limit) x.insert(it->second.build_limit);
        Resources cur = it->second.cost;
        if(player.food && cur.food && player.food >= cur.food) x.insert(player.food / cur.food);
        if(player.fuel && cur.fuel && player.fuel >= cur.fuel) x.insert(player.fuel / cur.fuel);
        if(player.metal && cur.metal && player.metal >= cur.metal) x.insert(player.metal / cur.metal);
        if(player.ppl && cur.ppl && player.ppl >= cur.ppl) x.insert(player.ppl / cur.ppl);
        if(!x.empty()) 
            cout << setw(16) << it->first << " : Right now you can buy at most " << *x.begin() << endl;  
    }
}