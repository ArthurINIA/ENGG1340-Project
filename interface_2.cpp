#include "all_interface.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void run_interface_2(vector<string> &cmd, int &population)
{
    // string internal_2_command;
    if (cmd[2] == "to")
    {
        if (cmd[3] == " ")
        {
            if (population > 10000)
            {
                // do something
                cout << population; // testing
            }
        }
    }
    cout << "interface 2" << endl; // testing
}
