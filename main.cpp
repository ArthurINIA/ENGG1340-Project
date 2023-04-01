#include <iostream>
#include <string>
#include "all_interface.h"
using namespace std;

void pick_random_event();

void processAction(string cmd)
{
    show_data();
    internal_actions();
    external_actions();
    round_result();
}

// GRACE HERE
int main()
{
    for (int round = 0; round < 50; round++)
    {
        for (int curCountry : countryList)
        {
            pick_random_event();

            // let player make decision;
            while (getline(cin, cmd))
            {
                if (cmd == “end”)
                {
                    // may need to print sth
                    break;
                }
                processAction(cmd);
            }

            round_result();
        }
    }
    end_game();
}
// testing for github update
