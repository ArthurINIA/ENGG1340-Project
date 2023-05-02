#include "main.h"
#include "all_interface.h"
#include "struct.h"
#include <ctime>
#include <cstdlib>
using namespace std;

string countryList[] = {"Player", "PC1", "PC2", "PC3"};
int AI_buildings[3][8] = {{2, 0, 0, 0, 0, 5, 1, 0}, {2, 0, 0, 0, 0, 5, 1, 0}, {2, 0, 0, 0, 0, 5, 1, 0}};
set<string> valid_interface_option({"show", "build", "status", "attack", "protect"});
map<string, int> interface_id = {
    {"i1", 1}, {"admin", 1}, {"i2", 2}, {"internal", 2}, {"i3", 3}, {"external", 3}, {"i4", 4}, {"news", 4}};

Resources player, AI[3], buffer;

void execute_AI_actions(const std::string &curCountry)
{
    srand(time(NULL));
    int randomNumber = rand() % 100;
    if (curCountry == "PC1")
    {
        // Country 1 is aggressive and tries to do every single action per round

        while (AI_check_res(curCountry, building["recruiting-office"].cost) == true)
        {
            AI_buildings[0][4] += 1;
            AI[0].food -= building["recruiting-office"].cost.food;
            AI[0].fuel -= building["recruiting-office"].cost.fuel;
            AI[0].metal -= building["recruiting-office"].cost.metal;
            AI[0].population -= building["recruiting-office"].cost.population;
        }

        while (AI_check_res(curCountry, building["farm"].cost) == true)
        {
            AI_buildings[0][2] += 1;
            AI[0].food -= building["farm"].cost.food;
            AI[0].fuel -= building["farm"].cost.fuel;
            AI[0].metal -= building["farm"].cost.metal;
            AI[0].population -= building["farm"].cost.population;
        }

        while (AI_check_res(curCountry, building["mine"].cost) == true)
        {
            AI_buildings[0][3] += 1;
            AI[0].food -= building["mine"].cost.food;
            AI[0].fuel -= building["mine"].cost.fuel;
            AI[0].metal -= building["mine"].cost.metal;
            AI[0].population -= building["mine"].cost.population;
        }

        while (AI_check_res(curCountry, building["oil-refinery"].cost) == true)
        {
            AI_buildings[0][0] += 1;
            AI[0].food -= building["oil-refinery"].cost.food;
            AI[0].fuel -= building["oil-refinery"].cost.fuel;
            AI[0].metal -= building["oil-refinery"].cost.metal;
            AI[0].population -= building["oil-refinery"].cost.population;
        }
    }

    if (curCountry == "PC2")
    {
        // Country 2 has balanced inclinations
        if (randomNumber < 25)
        {
            while (AI_check_res(curCountry, building["recruiting-office"].cost) == true)
            {
                AI_buildings[1][4] += 1;
                AI[1].food -= building["recruiting-office"].cost.food;
                AI[1].fuel -= building["recruiting-office"].cost.fuel;
                AI[1].metal -= building["recruiting-office"].cost.metal;
                AI[1].population -= building["recruiting-office"].cost.population;
            }
        }
        else if (randomNumber < 50)
        {
            while (AI_check_res(curCountry, building["farm"].cost) == true)
            {
                AI_buildings[1][2] += 1;
                AI[1].food -= building["farm"].cost.food;
                AI[1].fuel -= building["farm"].cost.fuel;
                AI[1].metal -= building["farm"].cost.metal;
                AI[1].population -= building["farm"].cost.population;
            }
        }
        else if (randomNumber < 75)
        {
            while (AI_check_res(curCountry, building["mine"].cost) == true)
            {
                AI_buildings[1][3] += 1;
                AI[1].food -= building["mine"].cost.food;
                AI[1].fuel -= building["mine"].cost.fuel;
                AI[1].metal -= building["mine"].cost.metal;
                AI[1].population -= building["mine"].cost.population;
            }
        }
        else
        {
            while (AI_check_res(curCountry, building["oil-refinery"].cost) == true)
            {
                AI_buildings[1][0] += 1;
                AI[1].food -= building["oil-refinery"].cost.food;
                AI[1].fuel -= building["oil-refinery"].cost.fuel;
                AI[1].metal -= building["oil-refinery"].cost.metal;
                AI[1].population -= building["oil-refinery"].cost.population;
            }
        }
    }
    if (curCountry == "PC3")
    {
        // Country 3 is peaceful

        // Example probability distribution
        if (randomNumber < 10)
        {
            while (AI_check_res(curCountry, building["recruiting-office"].cost) == true)
            {
                AI_buildings[2][4] += 1;
                AI[2].food -= building["recruiting-office"].cost.food;
                AI[2].fuel -= building["recruiting-office"].cost.fuel;
                AI[2].metal -= building["recruiting-office"].cost.metal;
                AI[2].population -= building["recruiting-office"].cost.population;
            }
        }
        else if (randomNumber < 40)
        {
            while (AI_check_res(curCountry, building["farm"].cost) == true)
            {
                AI_buildings[2][2] += 1;
                AI[2].food -= building["farm"].cost.food;
                AI[2].fuel -= building["farm"].cost.fuel;
                AI[2].metal -= building["farm"].cost.metal;
                AI[2].population -= building["farm"].cost.population;
            }
        }
        else if (randomNumber < 70)
        {
            while (AI_check_res(curCountry, building["mine"].cost) == true)
            {
                AI_buildings[2][3] += 1;
                AI[2].food -= building["mine"].cost.food;
                AI[2].fuel -= building["mine"].cost.fuel;
                AI[2].metal -= building["mine"].cost.metal;
                AI[2].population -= building["mine"].cost.population;
            }
        }
        else
        {
            while (AI_check_res(curCountry, building["oil-refinery"].cost) == true)
            {
                AI_buildings[2][0] += 1;
                AI[2].food -= building["oil-refinery"].cost.food;
                AI[2].fuel -= building["oil-refinery"].cost.fuel;
                AI[2].metal -= building["oil-refinery"].cost.metal;
                AI[2].population -= building["oil-refinery"].cost.population;
            }
        }
    }
}

int main()
{
    printIntro();
    int cur_interface = 1;
    player.init(350, 100, 100, 70000, 0, 0, 0, 0);
    init_interface_2();
    for (int round = 0; round < 50; round++)
    {
        for (string curCountry : countryList)
        {
            pick_random_event();

            if (curCountry == "Player")
            {
                string raw_cmd; // read command line from player
                while (getline(cin, raw_cmd))
                {
                    // cout << player.food << " " << player.fuel << " " << player.metal << " " << player.population << endl;
                    vector<string> cmd = split(raw_cmd);
                    if (cmd[0] == "to")
                    {
                        if (interface_id.count(cmd[1]))
                        {
                            cur_interface = interface_id[cmd[1]];
                            go_interface(cur_interface, cmd);
                        }
                        else
                        {
                            cout << "This interface does not exist!" << endl;
                        }
                    }
                    else if (valid_interface_option.count(cmd[0]))
                    {
                        go_interface(cur_interface, cmd);
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
            else if (curCountry != "Player")
            {
                execute_AI_actions(curCountry);
            }
            round_result();
        }
    }
    end_game();
}

// list of functions
// class functions
Resources &Resources::operator+=(const Resources &b)
{
    this->food += b.food, this->fuel += b.fuel, this->metal += b.metal, this->population += b.population;
    return *this;
}
Resources &Resources::operator-=(const Resources &b)
{
    this->food -= b.food, this->fuel -= b.fuel, this->metal -= b.metal, this->population -= b.population;
    return *this;
}
void Resources::init(int v1, int v2, int v3, int v4, int v5, int v6, double v7, int v8)
{
    food = v1, fuel = v2, metal = v3, population = v4, tanks = v5, soldiers = v6, military_factor = v7, max_population = v8;
}
std::ostream &operator<<(std::ostream &os, Resources const &x)
{
    return os << "food = " << x.food << "\t"
              << "fuel = " << x.fuel << "\n"
              << "metal = " << x.metal << "\t"
              << "ppl = " << x.population << endl;
}
std::ostream &operator<<(std::ostream &os, Building const &x)
{
    return os << "Building :\t" << x.name << "\n"
              << "requirement :\t" << x.requirement << "\n"
              << "description :\t" << x.description << "\n"
              << "effect: \t" << x.effect << "\n"
              << "cost--------------------------\n"
              << x.cost
              << "production--------------------\n"
              << x.production
              << "------------------------------" << endl;
}
// utility functions
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

void go_interface(int id, vector<string> &cmd)
{
    if (id == 1)
        run_interface_1(cmd);
    else if (id == 2)
        run_interface_2(cmd);
    else if (id == 3)
        run_interface_3(cmd);
    else if (id == 4)
        run_interface_4(cmd);
}

// game procedure functions
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

void round_result()
{
}

void end_game()
{
}