#include "all_interface.h"
#include "main.h"
#include "struct.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

extern resources player;
extern buildings oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;

void show_internal_info()
{
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "|";
}

void run_interface_2(vector<string> &cmd)
{
    string internal_2_cmd;
    while (getline(cin, internal_2_cmd))
    {
        // show default information/ interface2
        show_internal_info();
        vector<string> split_cmd = split(internal_2_cmd);
        if (split_cmd[0] == "show")
        {
            if (split_cmd[1] == "built")
            {
                if (player.population > 10000)
                {
                    // do something
                    cout << player.population; // testing
                }
            }
            else if (split_cmd[1] == "buildable")
            {
                // show available buildings
                cout << "success1" << endl; // testing
            }
            else if (split_cmd[1] == "info")
            {
                if (split_cmd[2] == " ")
                {
                    // show info
                    cout << "success2" << endl; // testing
                }
            }
            else
            {
                cout << "Invalid command" << endl;
            }
        }
        else if (split_cmd[0] == "build")
        {
            if (split_cmd[2] == " ")
            {
                cout << "success3" << endl; // testing
                // bulding count + split_cmd[1]
            }
        }
        else if (split_cmd[0] == "return")
        {
            cout << "return to main" << endl;
        }
        else
        {
            cout << "Invalid command" << endl;
        }
    }
    cout << "interface 2" << endl; // testing
}
