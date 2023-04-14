#include "all_interface.h"
#include "main.h"
#include "struct.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern resources player;
extern buildings oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;

void show_internal_heading()
{
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "|";
}

void run_interface_2(vector<string> &cmd)
{
    // show default information/ interface2
    show_internal_heading();
    if(cmd[0] == "to"){
        cout << "interface 2" << endl; // testing
    }
    else if (cmd[0] == "show")
    {
        if (cmd[1] == "built")
        {
            if (player.population > 10000)
            {
                // do something
                cout << player.population << endl; // testing
            }
        }
        else if (cmd[1] == "buildable")
        {
            // show available buildings
            cout << "success1" << endl; // testing
        }
        else if (cmd[1] == "info")
        {
            if(cmd.size() > 2){
                if (cmd[2] == " " /*valid_building_name.count(cmd[2])*/)
                {
                    // show info
                    cout << "success2" << endl; // testing
                }else{
                    cout << "We do not have this building option" << endl;
                }
            }
            else{
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
        if (cmd.size() < 3){
            cout << "please add quantity and then the name of building." << endl;
        }
        else if (cmd.size() >= 3 /* && valid_building_name.count(cmd[2]) */)
        {
            cout << "success3" << endl; // testing
            // bulding count + cmd[1]
        }
        else{
            cout << "Unsuccessful Command" << endl;
        }
    }
    else
    {
        cout << "Invalid command" << endl;
    }
    
}
