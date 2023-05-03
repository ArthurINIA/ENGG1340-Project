#include "main.h"
#include "all_interface.h"
#include <random>
#include <array>
using namespace std;

UI gameScreen;

string countryList[] = {"Player", "PC1", "PC2", "PC3"};
int AI_buildings[3][8] = {{2, 0, 0, 0, 0, 5, 1, 0}, {2, 0, 0, 0, 0, 5, 1, 0}, {2, 0, 0, 0, 0, 5, 1, 0}};
set<string> valid_interface_option({"show", "build", "status", "attack", "move"});
map<string, int> interface_id = {
    {"i1", 1}, {"admin", 1}, {"i2", 2}, {"internal", 2}, {"i3", 3}, {"external", 3}, {"i4", 4}, {"news", 4}};

Resources player, AI[3], buffer;


int main()
{
    printIntro();
    int cur_interface = 1;
    player.init(350, 100, 100, 70000, 0, 500, 0, 0);
    init_interface_2();
    init_i3();
    for (int round = 0; round < 20; round++)
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
            
        }
        round_result();
    }
    end_game();
}

//NPC control
bool AI_check_res(string name, Resources res)
{
    int x = name[2] - '1';
    return (AI[x].food > res.food && AI[x].fuel > res.fuel 
        && AI[x].metal > res.metal && AI[x].population > res.population);
}

void execute_AI_actions(const string &curCountry)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 3);
    map<string, array<int, 7>> AI_move = {
        {"PC1", array<int, 7>{0, 5, 0, 7000, 300, 300, 300}},
        {"PC2", array<int, 7>{1, 4, 0, 2000, 500, 500, 750}},
        {"PC3", array<int, 7>{2, 4, 0, 2000, 1000, 1000, 1000}}};
    for (int i = 0; i < AI_move[curCountry][1] + distrib(gen); i++)
    {
        /*
        if (1 /can move soldier/)
        {
            // move soldier
        }
        */
        if (AI[AI_move[curCountry][0]].soldier < AI_move[curCountry][3] && AI_check_res(curCountry, building["recruiting-office"].cost))
        {
            AI_buildings[AI_move[curCountry][0]][4] += 1;
            AI[AI_move[curCountry][0]] -= building["recuiting-office"].cost;
            continue;
        }
        if (AI[AI_move[curCountry][0]].metal < AI_move[curCountry][4] && AI_check_res(curCountry, building["mine"].cost))
        {
            AI_buildings[AI_move[curCountry][0]][3] += 1;
            AI[AI_move[curCountry][0]] -= building["mine"].cost;
            continue;
        }
        if (AI[AI_move[curCountry][0]].fuel < AI_move[curCountry][5] && AI_check_res(curCountry, building["oil-refinery"].cost))
        {
            AI_buildings[AI_move[curCountry][0]][0] += 1;
            AI[AI_move[curCountry][0]] -= building["oil-refinery"].cost;
            continue;
        }
        if (AI[AI_move[curCountry][0]].food < AI_move[curCountry][6] && AI_check_res(curCountry, building["farm"].cost))
        {
            AI_buildings[AI_move[curCountry][0]][2] += 1;
            AI[AI_move[curCountry][0]] -= building["farm"].cost;
            continue;
        }
    }
}

// list of functions
// class functions
Resources &Resources::operator+=(const Resources &b)
{
    this->food += b.food, this->fuel += b.fuel, this->metal += b.metal, this->population += b.population, this->soldier += b.soldier, this->tank += b.tank;
    return *this;
}
Resources &Resources::operator-=(const Resources &b)
{
    this->food -= b.food, this->fuel -= b.fuel, this->metal -= b.metal, this->population -= b.population, this->soldier -= b.soldier, this->tank -= b.tank;
    return *this;
}
Resources &Resources::operator*(const int &b)
{
    this->food *= b, this->fuel *= b, this->metal *= b, this->population *= b, this->soldier *= b, this->tank *= b;
    return *this;
}
//food, fuel, metal, ppl, tank, soldier, milFac, maxPop;
void Resources::init(int v1, int v2, int v3, int v4, int v5, int v6, double v7, int v8)
{
    food = v1, fuel = v2, metal = v3, population = v4, tank = v5, soldier = v6, military_factor = v7, max_population = v8;
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
    system("clear");
    string introStory[] = {
        "In the last century, the Earth was overdeveloped by human civilization, and the energy catastrophe and the pollution storm were unprecedented destructive forces that reverted to the civilized world.", "The catastrophe not only set back human civilization in terms of technology and desertification of most of the land, but also brought about a horrific change to the earth - \"a black miasma covering the outer atmosphere, with daylight no longer within reach\".", "Talents spring up in the turbulent days, your country's rising stars of the future have been put into new energy research, cold fusion technology is about to be completed.", "The countries are struggling for land, searching for rare raw energy under the region, for the sake of national peace and security.", "You, as a commander, please keep your resources intact and hold the border until the cold fusion arrives.", "......", "......", "01-Jan-2023", "  Nuclear Department Head: Greetings sir, I have a good news to you.", "  Nuclear Department Head: The testing phase of the cold fusion has come to the last step.", "                      You: How many days are needed?", "  Nuclear Department Head: 20 more days before our new era.", "  Nuclear Department Head: Please protect us from the neighbouring threats.", "......", "......", "Can you keep your country alive in the next 20 days?"};
    for (string x : introStory)
        cout << x << endl;
}

void pick_random_event()
{
}

void end_game()
{
}