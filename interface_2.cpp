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
    //cout << building["oil-refinery"]; //success
}

void show_internal_heading()
{
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "|";
}

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
            // show available buildings
            cout << "success1" << endl; // testing
        }
        else if (cmd[1] == "info")
        {
            if (cmd.size() > 2)
            {
                if (cmd[2] == " " /*valid_building_name.count(cmd[2])*/)
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
        else if (cmd.size() >= 3 /* && valid_building_name.count(cmd[2]) */)
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
