#include "all_interface.h"
#include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include "struct.h"
using namespace std;

void show_internal_info()
{
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "|"
}

void run_interface_2(vector<string> &cmd, int &population)
{
    string internal_2_cmd;
    while (getline(cin, internal_2_cmd))
    {
        vector<string> split_cmd = split(internal_2_cmd);
        if (split_cmd[0] == "show")
        {
            // show default information/ interface2
            show_internal_info();
            if (split_cmd[1] == "built")
            {
                if (population > 10000)
                {
                    // do something
                    cout << population; // testing
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
