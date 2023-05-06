#include "main.h"
#include "all_interface.h"
#include <random>
#include <array>
using namespace std;

int curGameDay = -1; // set game day
UI gameScreen, startScreen;
Country player[4];              // Player, PC1, PC2, PC3
map<string, Building> building; // set map for calling building parameters
i3Map wldMap[4][4];             // set world map

int starve[4] = {0, 0, 0, 0}; // set starve array for 4 countries

string countryList[4] = {"Player", "PC1", "PC2", "PC3"};                                            // set country list
string buildingList[6] = {"farm", "oil-refinery", "mine", "house", "recruiting-office", "factory"}; // set building list
set<string> valid_interface_option({"to", "show", "build", "move", "admin"});                       // set valid connand
map<string, int> interface_id = {
    {"i1", 1}, {"admin", 1}, {"i2", 2}, {"internal", 2}, {"i3", 3}, {"external", 3}, {"i4", 4}, {"news", 4}}; // set interface id

int main()
{
    start_game();
    init_interface_2();    // initialize interface 2 for setting all buiulding parameter
    init_i4();             // initialize interface 4 screen output
    int cur_interface = 1; // set current interface to interface1
    // the game engine
    for (int round = curGameDay; round <= 20; round++, curGameDay++) // 20 game day loop
    {
        for (int uid = 0; uid < 4; uid++) // loop for 4 countries
        {
            if (uid == 0) // if country is player
            {
                // random boost or debuff
                pick_random_event();

                while (1)
                {
                    string raw_cmd = ""; // read command line from player
                    readLine(raw_cmd);
                    // split the lines of raw command into blocks of string
                    vector<string> cmd = split(raw_cmd);
                    if (cmd[0] == "to")
                    {
                        // correct interface name
                        if (interface_id.count(cmd[1]))
                        {
                            // current interface may change
                            cur_interface = interface_id[cmd[1]];
                            go_interface(cur_interface, cmd);
                        }
                        else
                        {
                            cout << "This interface does not exist!" << endl;
                        }
                    }
                    else if (valid_interface_option.count(cmd[0])) // if first block of command is valid
                    {
                        go_interface(cur_interface, cmd);
                    }
                    else if (cmd[0] == "end")
                    {

                        break; // stop recieving commands for today's action, break 4 country loop
                    }
                    else if (cmd[0] == "quit")
                    {
                        // save game
                        save_data();
                        cout << "Game Saved" << endl;
                        // close game
                        exit(0);
                    }
                    else if (cmd[0] == "help")
                    {
                        // manual
                        vector<string> content;
                        content.push_back("Interface1:");
                        content.push_back("it shows the basic resources' amount and round add.");
                        content.push_back("Interface2:");
                        content.push_back("type show buildable to show what you can build.");
                        content.push_back("type build [NUM] [buildingNAME] to build.");
                        content.push_back("type show info [buildingNAME] to show info of them.");
                        content.push_back("(buildingNAME is the same as you see in show buildable.)");
                        content.push_back("Interface3:");
                        content.push_back("type move [NUM] [soldier/tank] from [x,y] to [x,y] to move troops.");
                        content.push_back("Interface4:");
                        content.push_back("show round result.");
                        content.push_back("**Type end to end round**");
                        content.push_back("**Type quit to save and quit game**");
                        gameScreen.divide(40, 5, 120, 29, "game-content");
                        gameScreen.drawAll("game-content", "left", content);
                        gameScreen.print();
                    }
                    else
                    {
                        cout << "Invalid Operation!" << endl;
                    }
                }
            }
            else
            {
                if (!player[uid].dead) // if npc country not dead, make random decision for them
                    npc_decision(uid);
            }
        }
        round_result(); // show round random event, construct a random story line for 20 random events throughout the game
        save_data();
        if (player[0].dead) // if player dead, break 20 day loop
        {
            break;
        }
    }
    if (player[0].dead) // check player dead flag, output different ending
    {
        end_game("failed");
    }
    else
    {
        end_game("survive");
    }
}

void npc_decision(int uid)
{
    // base amount of actions the pc can make per round
    int actionLimit[3] = {0, 1, 0};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 3);

    // x is .first, y is .second
    pair<int, int> main_city[4] = {
        {0, 0}, {3, 0}, {0, 3}, {3, 3}},                                                                                                  // set initail city coordinates
        line_of_defense[4][3] = {{{1, 0}, {0, 1}, {1, 1}}, {{2, 0}, {2, 1}, {3, 1}}, {{0, 2}, {1, 2}, {1, 3}}, {{2, 3}, {3, 2}, {2, 2}}}; // setting defense line for all countries

    for (int i = 0; i < actionLimit[uid] + distrib(gen); i++) // random number of moves
    {
        // first priority is move soldier to strenghen the surroundings
        int x = main_city[uid].first, y = main_city[uid].second;
        // check if main city has excess soldier to send
        if (wldMap[x][y].army[uid].soldier > 300)
        {
            srand(time(0));
            int randChoice = rand() % 3; // randomly choose a land nearby to move soldier
            int x2 = line_of_defense[uid][randChoice].first;
            int y2 = line_of_defense[uid][randChoice].second;
            // send 300 soldiers to one of the near land
            wldMap[x][y].army[uid].soldier -= 300;
            wldMap[x2][y2].army[uid].soldier += 300;
            continue;
        }
        // second priority is to build mine
        if (player[uid].metal <= 100 && player[uid].qty_owned["mine"] < player[uid].build_lim["mine"])
        {
            player[uid] -= building["mine"].cost;
            player[uid].qty_owned["mine"]++;
            continue;
        }
        // third priority is to build farm
        if (player[uid].metal > 250 && player[uid].qty_owned["farm"] < player[uid].build_lim["farm"])
        {
            player[uid] -= building["farm"].cost;
            player[uid].qty_owned["farm"]++;
            continue;
        }
        // fourth priority is to build house
        if (player[uid].metal > 20 && player[uid].fuel > 20 && player[uid].qty_owned["house"] < player[uid].build_lim["house"])
        {
            player[uid] -= building["house"].cost;
            player[uid].qty_owned["house"]++;
            continue;
        }
        // fifth priority is to build recruiting office
        if (player[uid].metal > 50 && player[uid].qty_owned["recruiting-office"] < player[uid].build_lim["recruiting-office"])
        {
            player[uid] -= building["recruiting-office"].cost;
            player[uid].qty_owned["recruiting-office"]++;
            continue;
        }
    }
}

void round_result()
{
    // working
    pair<int, int> main_city[4] = {
        {0, 0}, {3, 0}, {0, 3}, {3, 3}};
    vector<string> content;
    content.push_back("Today has come to an end.");
    // cal external changes
    // put this first, coz war loss can reduce land, which destroy some of the player's building

    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            vector<int> cty;
            for (int i = 0; i < 4; i++)
                if (wldMap[x][y].army[i].soldier || wldMap[x][y].army[i].tank)
                    cty.push_back(i); // any country have troops on land will be pushed to cty
            if (cty.empty())
            {
                wldMap[x][y].owner = "nobody"; // if no country have troops on the land, nobody owns the land
            }
            else if (cty.size() == 1) // if only 1 country have troops on it, land owner is the conutry
            {
                string ctyList[] = {"Player", "PC1", "PC2", "PC3"};
                if (wldMap[x][y].owner != ctyList[cty[0]])
                    for (string bu : buildingList)
                        player[cty[0]].build_lim[bu] += building[bu].limit_per_land;
                wldMap[x][y].owner = ctyList[cty[0]];
                // gain land addition
            }
            // war simulation!
            else if (cty.size() == 2) // if 2 countries have troops on same land
            {
                // I only made conservative npc, so each land at most 2 different countries
                // getting army parameters of 2 countries
                Military_Resouces &A = wldMap[x][y].army[cty[0]];
                Military_Resouces &B = wldMap[x][y].army[cty[1]];

                // tank is stronger, calculate tank first
                if (A.tank && B.tank)
                {
                    auto cal = [&](int &id1, int &troopWin, int &id2, int &troopLose)
                    {
                        troopWin -= troopLose;
                        player[id1].tank -= troopLose;
                        troopLose = 0;
                        player[id2].tank = 0;
                    };
                    if (A.tank >= B.tank)
                        cal(cty[0], A.tank, cty[1], B.tank);
                    else
                        cal(cty[1], B.tank, cty[0], A.tank);
                }
                // then if one side still have tank, use tank to destroy the enemy soldier
                // tank cannot be destroyed by soldier, tank can destroy tank*40 amount of soldier
                if ((A.tank > 0) ^ (B.tank > 0))
                {
                    auto cal = [&](int &id1, int &troopWin, int &id2, int &troopLose)
                    {
                        int killed = min(troopLose, troopWin * 40);
                        player[id2].soldier -= killed;
                        troopLose -= killed;
                    };
                    if (A.tank)
                        cal(cty[0], A.tank, cty[1], B.soldier);
                    else
                        cal(cty[1], B.tank, cty[0], A.soldier);
                }
                // after that calculate the soldier fight
                if (A.soldier && B.soldier)
                {
                    // cout << "before" << A.soldier << ' ' << B.soldier << endl; // test

                    auto cal = [&](int &id1, int &troopWin, int &id2, int &troopLose)
                    {
                        troopWin -= troopLose;
                        player[id1].soldier -= troopLose;
                        troopLose = 0;
                        player[id2].soldier = 0;
                    };
                    if (A.soldier >= B.soldier)
                        cal(cty[0], A.soldier, cty[1], B.soldier);
                    else
                        cal(cty[1], B.soldier, cty[0], A.soldier);

                    // cout << "after" << A.soldier << ' ' << B.soldier << endl; // test
                    // cin.get(); // test
                }

                // cty[0] now marks the winner
                if (B.soldier || B.tank)
                    swap(cty[0], cty[1]);
                string ctyList[] = {"Player", "PC1", "PC2", "PC3"};
                if (wldMap[x][y].owner != ctyList[cty[0]])
                {
                    // winner gets more room to build their buildings
                    for (string bu : buildingList)
                        player[cty[0]].build_lim[bu] += building[bu].limit_per_land;
                    if (wldMap[x][y].owner != "nobody")
                    {
                        // int id = ctyList.find(wldMap[x][y].owner);
                        int id = (wldMap[x][y].owner == "Player"
                                      ? 0
                                      : wldMap[x][y].owner[2] - '0');
                        // lose land, lose some building
                        for (string bu : buildingList)
                        {
                            player[id].build_lim[bu] -= building[bu].limit_per_land;
                            if (player[id].qty_owned[bu] > player[id].build_lim[bu])
                                player[id].qty_owned[bu] = player[id].build_lim[bu];
                        }
                    }
                }
                wldMap[x][y].owner = ctyList[cty[0]];
                // gain land addition
                // then next part, cal internal econ, will see who remains in this land
            }
        }
    }

    // determine collapse of countries
    for (int i = 0; i < 4; i++)
    {
        int x = main_city[i].first;
        int y = main_city[i].second;
        if (wldMap[x][y].owner != countryList[i]) // if country no longer own their initial city, country collapse
        {
            player[i].dead = true;
        }
        if (starve[i] >= 3)
        {
            player[i].dead = true;
        }
    }

    // cal internal econ
    // loop through the player
    for (int i = 0; i < 4; i++)
    {
        if (player[i].dead)
            continue;
        // cout << countryList[i] << endl;
        // cout << "before:" << endl << player[i]<< endl; // testing

        // resources consumption
        //--not enough food will stop producing army and citizens
        bool starvation = (player[i].food < player[i].soldier * 2 + player[i].tank * 2 + player[i].citizen);
        //--food consumption
        if (starvation) // if starvation flag is true, corresponding starve value increase
        {
            starve[i] += 1;
        }
        else
        {
            starve[i] = 0;
        }
        player[i].citizen += player[i].qty_owned["house"] * 500; // calculate resouces for npc countries
        player[i].food = max(0, player[i].food - player[i].soldier * 2);
        player[i].food = max(0, player[i].food - player[i].tank * 2);
        if (player[i].food < player[i].citizen)
        {
            player[i].citizen -= player[i].food;
            player[i].food = 0;
        }
        else
        {
            player[i].food -= player[i].citizen;
        }

        // resources production
        int x = main_city[i].first, y = main_city[i].second;
        // loop through the bilding list
        for (int j = 0; j < 6; j++)
        {
            string bu = buildingList[j];
            int qty = player[i].qty_owned[bu];
            if (!qty)
                continue;

            /*
            if(bu == "oil-refinery"){
                content.push_back(countryList[i]+" fuel");
                content.push_back("before : "+to_string(player[i].fuel)); //testing
                content.push_back("plus: "+to_string(building[bu].production.fuel)+" * "+to_string(qty));//testing
            }
            */

            if (bu != "recruiting-office" && bu != "factory") // add resources to country
            {
                Resources temp = building[bu].production;
                player[i] += temp * qty;
                continue;
            }

            /*
            if(bu == "oil-refinery"){
                content.push_back("after = "+to_string(player[i].fuel));//testing;
            }
            */

            if (bu == "recruiting-office" && !starvation) // add soldier and decrease citizen
            {
                for (int k = 1; k <= qty; k++)
                {
                    if (!player[i].citizen)
                        break;
                    int gain = (player[i].citizen < building[bu].production.soldier)
                                   ? player[i].citizen
                                   : building[bu].production.soldier;
                    // citizens are recruited to be soldier
                    player[i].citizen -= gain;
                    player[i].soldier += gain;
                    wldMap[x][y].army[i].soldier += gain;
                }
            }
            if (bu == "factory" && !starvation) // add tank and decrease citizen
            {
                for (int k = 1; k <= qty; k++)
                {
                    if (!player[i].citizen)
                        break;
                    int gain = (player[i].citizen < building[bu].production.tank)
                                   ? player[i].citizen
                                   : building[bu].production.tank;
                    // citizens are recruited to be tank driver
                    player[i].citizen -= gain;
                    player[i].tank += gain;
                    wldMap[x][y].army[i].tank += gain;
                }
            }
        }
        // cout << "after:" << endl << player[i]<< endl << endl; // testing
    }
    show_round_result(content);
}

// list of functions
// class functions
Resources &Resources::operator+=(const Resources &b)
{
    this->food += b.food, this->fuel += b.fuel, this->metal += b.metal, this->citizen += b.citizen, this->soldier += b.soldier, this->tank += b.tank;
    return *this;
}
Resources &Resources::operator-=(const Resources &b)
{
    this->food -= b.food, this->fuel -= b.fuel, this->metal -= b.metal, this->citizen -= b.citizen, this->soldier -= b.soldier, this->tank -= b.tank;
    return *this;
}
Resources &Resources::operator*=(const int &b)
{
    this->food *= b, this->fuel *= b, this->metal *= b, this->citizen *= b, this->soldier *= b, this->tank *= b;
    return *this;
}
Resources Resources::operator*(const int &b)
{
    this->food *= b, this->fuel *= b, this->metal *= b, this->citizen *= b, this->soldier *= b, this->tank *= b;
    return *this;
    // Resources temp = (*this);
    // temp.food *= b, temp.fuel *= b, temp.metal *= b, temp.citizen *= b, temp.soldier *= b, temp.tank *= b;
    // return temp;
}
// food, fuel, metal, citizen, tank, soldier, milFac, maxPop;
void Resources::init(int v1, int v2, int v3, int v4, int v5, int v6, double v7, int v8)
{
    food = v1, fuel = v2, metal = v3, citizen = v4, tank = v5, soldier = v6, military_factor = v7, max_population = v8;
}
std::ostream &operator<<(std::ostream &os, Resources const &x)
{
    return os << "food = " << x.food << "\t"
              << "fuel = " << x.fuel << "\t"
              << "metal = " << x.metal << "\t"
              << "citizen = " << x.citizen << endl
              << "soldier = " << x.soldier << "\t"
              << "tank = " << x.tank << endl;
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
void readLine(string &str) // readLine function, read until \n
{
    while (1)
    {
        char c = getchar();
        if (c == '\n' && str.size() > 0)
            return;
        if (c != '\n')
            str += c;
    }
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
bool check_res(int id, Resources res) // check if resources are enough for operations
{
    return (player[id].food >= res.food && player[id].fuel >= res.fuel && player[id].metal >= res.metal && player[id].citizen >= res.citizen);
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
void start_game()
{
    startScreen.divide(1, 1, 120, 29, "whole");

    startScreen.divide(100, 1, 120, 29, "start-menu");
    startScreen.drawAll("start-menu", "center", {"Choose game:", " ", "new", " ", "previous"});

    startScreen.divide(1, 1, 100, 29, "intro"); // intro story
    vector<string> introStory = {
        "  In the last century, the Earth was overdeveloped by human civilization, and the pollution",
        "  storm were unprecedented destructive forces that reverted to the civilized world.        ",
        " ",
        "  The catastrophe not only set back human civilization in terms of technology and desertifi",
        "  cation of most of the land, but also brought about a horrific change to the Earth - \"a   ",
        "  black miasma covering the outer atmosphere, with daylight no longer within reach\".       ",
        " ",
        "  Talents spring up in the turbulent days, your country's rising stars of the future have  ",
        "  been put into new energy research, cold fusion technology is about to be completed.      ",
        " ",
        "  The countries are struggling for land, searching for rare raw energy under the region,",
        "  for the sake of national peace and security.",
        " ",
        "  You, as a commander, please keep your resources intact and hold the border until the",
        "  cold fusion arrives.",
        "......",
        "  01-Jan-2023",
        "    Nuclear Department Head: Greetings sir, I have a good news to you.",
        "    Nuclear Department Head: The testing phase of the cold fusion will be finished soon",
        "                        You: How many days do you need?",
        "    Nuclear Department Head: 20 more days before our new era.",
        "    Nuclear Department Head: Please protect us from the neighbouring threats.",
        "......",
        " ",
        "  Can you keep your country alive in the next 20 days?"};
    startScreen.drawAll("intro", "left", introStory);

    startScreen.print();

    string mode;
    while (1)
    {
        readLine(mode);
        if (mode == "new")
        {
            init_game();
            return;
        }
        if (mode == "previous" || mode == "load")
        {
            // load;
            load_data();
            if (curGameDay == -1)
                init_game();
            return;
        }
        mode = "";
    }
}

void init_game()
{
    // if start a new game
    curGameDay = 1;
    init_interface_2();
    init_i3();
    init_i4();
    // init players
    for (int i = 0; i < 4; i++)
    {
        player[i].init(70000, 100, 100, 4000, 0, 500, 0, 0);
        for (int j = 0; j < 6; j++)
        {
            string bu = buildingList[j];
            player[i].qty_owned[bu] = building[bu].init_qty;
            player[i].build_lim[bu] = building[bu].limit_per_land;
        }
    }

    vector<string> dummy = {""};
    run_interface_1(dummy);
}

/*
void pick_random_event()
{
}
*/

void end_game(string status) // output different ending
{
    vector<string> content;
    // cout << "testing";
    // cin.get();
    if (status == "survive")
    {
        content.push_back("mission complete! Survived!");
        show_round_result(content);
        exit(0);
    }
    else if (status == "failed")
    {
        content.push_back("mission failed!");
        show_round_result(content);
        exit(0);
    }
}