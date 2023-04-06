#include <iostream>
#include <string>
#include <vector>
#include "main.h"
#include "all_interface.h"
#include "struct.h"
using namespace std;

resources player;
buildings oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;

// list of functions
// debug message printer
void testing()
{
}
vector<string> split(string raw_line)
{
    // split the string by space and return a vecetor of strings
    vector<string> rt;
    string cur = "";
    for (char i : raw_line)
    {
        if (i != ' ')
            cur += i;
        else
        {
            // if space, add the current string to the return vector, then clear the current string;
            rt.push_back(cur);
            cur = "";
        }
    }
    // boundary case of the last string
    if (cur != "")
        rt.push_back(cur);
    return rt;
}

string countryList[] = {"Player", "PC1", "PC2", "PC3"};

int main()
{
    printIntro();
    player.food = 350;
    player.fuel = 100;
    player.metal = 100;
    player.population = 70000;
    for (int round = 0; round < 50; round++)
    {
        for (string curCountry : countryList)
        {
            pick_random_event();

            if (curCountry == "Player")
            {
                // read command line from player
                string raw_cmd;
                while (getline(cin, raw_cmd))
                {
                    vector<string> cmd = split(raw_cmd);
                    if (cmd[0] == "to")
                    {
                        if (cmd[1] == "i1" || cmd[1] == "admin-panel")
                            run_interface_1(cmd);
                        else if (cmd[1] == "i2" || cmd[1] == "internal")
                            run_interface_2(cmd);
                        else if (cmd[1] == "i3" || cmd[1] == "world-map")
                            run_interface_3(cmd);
                        else if (cmd[1] == "i4" || cmd[1] == "world-news")
                            run_interface_4(cmd);
                        else
                            cout << "This interface does not exist!" << endl;
                    }
                    else if (cmd[0] == "end")
                    {
                        cout << "Today has come to an end." << endl;
                        break;
                    }
                    else if (cmd[0] == "quit")
                    {
                        // save game
                        cout << "Game Saved" << endl;
                        // close game
                        exit(0);
                    }
                    else if (cmd[0] == "help")
                    {
                        // manual
                    }
                    else
                    {
                        cout << "Invalid Operation!" << endl;
                    }
                }
            }
            round_result();
        }
    }
    end_game();
}

void printIntro()
{
    string introStory[] = {
        "In the last century, the Earth was overdeveloped by human civilization, and the energy catastrophe and the pollution storm were unprecedented destructive forces that reverted to the civilized world.", "The catastrophe not only set back human civilization in terms of technology and desertification of most of the land, but also brought about a horrific change to the earth - \"a black miasma covering the outer atmosphere, with daylight no longer within reach\".", "Talents spring up in the turbulent days, your country's rising stars of the future have been put into new energy research, cold fusion technology is about to be completed.", "The countries are struggling for land, searching for rare raw energy under the region, for the sake of national peace and security.", "You, as a commander, please keep your resources intact and hold the border until the cold fusion arrives.", "......", "......", "01-Jan-2023", "  Nuclear Department Head: Greetings sir, I have a good news to you.", "  Nuclear Department Head: The testing phase of the cold fusion has come to the last step.", "                      You: How many days are needed?", "  Nuclear Department Head: 50 more days before our new era.", "  Nuclear Department Head: Please protect us from the neighbouring threats.", "......", "......", "Can you keep your country alive in the next 50 days?"};
    for (string x : introStory)
        cout << x << endl;
}

void pick_random_event()
{
}

void processAction(string cmd)
{
    /*
    show_data();
    internal_actions();
    external_actions();
    */
}

void round_result()
{
}

void end_game()
{
}