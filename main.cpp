#include "main.h"
#include "all_interface.h"
#include <random>
#include <array>
using namespace std;

int curGameDay = 0;
UI gameScreen, startScreen;
Country player[4]; //Player, PC1, PC2, PC3
map<string, Building> building;
i3Map wldMap[4][4];

string countryList[4] = {"Player", "PC1", "PC2", "PC3"};
string buildingList[6] = {"farm", "oil-refinery", "mine", "house", "recruiting-office", "factory"};
set<string> valid_interface_option({"to", "show", "build", "move", "admin"});
map<string, int> interface_id = {
    {"i1", 1}, {"admin", 1}, {"i2", 2}, {"internal", 2}, {"i3", 3}, {"external", 3}, {"i4", 4}, {"news", 4}};


int main(){
    printIntro();
    int cur_interface = 1;
    //if start a new game
    //init players
    
    for(int i = 0; i < 4; i++){
        player[i].init(70000, 100, 100, 4000, 0, 500, 0, 0);
        for(int j = 0; j < 6; j++){
            string bu = buildingList[j];
            player[i].qty_owned[bu] = building[bu].init_qty;
            player[i].build_lim[bu] = building[bu].limit_per_land;
        }
    }
    init_interface_2();
    init_i3();

    //the game engine
    for (int round = curGameDay; round < 20; round++, curGameDay++){
        for(int uid = 0; uid < 4; uid++){
            if (uid == 0){
                //random boost or debuff
                pick_random_event();
                
                while (1)
                {
                    string raw_cmd = ""; // read command line from player
                    readLine(raw_cmd);
                    //split the lines of raw command into blocks of string
                    vector<string> cmd = split(raw_cmd);
                    if (cmd[0] == "to")
                    {
                        //correct interface name
                        if (interface_id.count(cmd[1]))
                        {
                            //current interface may change
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
                        break; //stop recieving commands for today's action
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
            else{
                npc_decision(uid);
            }
        }
        round_result();
    }
    end_game("survived");
}

void npc_decision(int uid){
    //base amount of actions the pc can make per round
    int actionLimit[3] = {0, 1, 0};
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 3);
    
    //x is .first, y is .second
    pair<int, int> main_city[4] = {
        {0,0},{3,0}, {0,3}, {3,3}
    },
    line_of_defense[4][3] = {
        {{1,0}, {0,1}, {1,1}},
        {{2,0}, {2,1}, {3,1}},
        {{0,2}, {1,2}, {1,3}},
        {{2,3}, {3,2}, {2,2}}
    }; 

    for(int i = 0; i < actionLimit[uid] + distrib(gen); i++){
        //first priority is move soldier to strenghen the surroundings
        int x = main_city[uid].first, y = main_city[uid].second;
        //check if main city has excess soldier to send
        if(wldMap[x][y].army[uid].soldier > 300){
            srand(time(0));
            int randChoice = 1 + rand() % 3;
            int x2 = line_of_defense[uid][randChoice].first;
            int y2 = line_of_defense[uid][randChoice].second;
            //send 300 soldiers to one of the near land
            wldMap[x][y].army[uid].soldier -= 300;
            wldMap[x2][y2].army[uid].soldier += 300;
            continue;
        }
        //second priority is to build farm
        if(player[uid].metal > 250 && player[uid].qty_owned["farm"] < player[uid].build_lim["farm"]){
            player[uid] -= building["farm"].cost;
            player[uid].qty_owned["farm"]++;
            continue;
        }
        //third priority is to build recruiting office
        if(player[uid].metal > 50 && player[uid].qty_owned["recruiting-office"] < player[uid].build_lim["recruiting-office"]){
            player[uid] -= building["recruiting-office"].cost;
            player[uid].qty_owned["recruiting-office"]++;
            continue;
        }
    }
}

void round_result(){
    // working

    // cal external changes
    // put this first, coz war loss can reduce land, which destroy some of the player's building
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            vector<int> cty;
            for (int i = 0; i < 4; i++)
                if (wldMap[x][y].army[i].soldier || wldMap[x][y].army[i].tank)
                    cty.push_back(i);
            if (cty.empty()){
                wldMap[x][y].owner = "nobody";
            }
            else if (cty.size() == 1){
                string ctyList[] = {"Player", "PC1", "PC2", "PC3"};
                if(wldMap[x][y].owner != ctyList[cty[0]])
                    for(string bu: buildingList)
                        player[cty[0]].build_lim[bu] += building[bu].limit_per_land;
                wldMap[x][y].owner = ctyList[cty[0]];
                // gain land addition
            }
            // war simulation!
            else if(cty.size() == 2){
                //I only made conservative npc, so each land at most 2 different countries
                Military_Resouces &A = wldMap[x][y].army[cty[0]];
                Military_Resouces &B = wldMap[x][y].army[cty[1]];

                //tank is stronger, calculate tank first
                if(A.tank && B.tank){
                    auto cal = [&](int id1, int troopWin, int id2, int troopLose){
                        troopWin -= troopLose;
                        player[id1].tank -= troopLose;
                        troopLose = 0;
                        player[id2].tank = 0;
                    };
                    if(A.tank >= B.tank)
                        cal(cty[0], A.tank, cty[1], B.tank);
                    else
                        cal(cty[1], B.tank, cty[0], A.tank);
                }
                //then if one side still have tank, use tank to destroy the enemy soldier
                if((A.tank > 0) ^ (B.tank > 0)){
                    auto cal = [&](int id1, int troopWin, int id2, int troopLose){
                        int killed = min(troopLose, troopWin * 40);
                        player[id2].soldier -= killed;
                        troopLose -= killed;
                    };
                    if(A.tank)
                        cal(cty[0], A.tank, cty[1], B.soldier);
                    else
                        cal(cty[1], B.tank, cty[0], A.soldier);
                }
                //after that calculate the soldier fight
                if(A.soldier && B.soldier){
                    auto cal = [&](int id1, int troopWin, int id2, int troopLose){
                        troopWin -= troopLose;
                        player[id1].soldier -= troopLose;
                        troopLose = 0;
                        player[id2].soldier = 0;
                    };
                    if(A.soldier >= B.soldier)
                        cal(cty[0], A.soldier, cty[1], B.soldier);
                    else
                        cal(cty[1], B.soldier, cty[0], A.soldier);
                }
                
                //cty[0] now marks the winner
                if(B.soldier || B.tank) swap(cty[0], cty[1]);
                string ctyList[] = {"Player", "PC1", "PC2", "PC3"};
                if(wldMap[x][y].owner != ctyList[cty[0]]){
                    //winner gets more room to build their buildings
                    for(string bu: buildingList)
                        player[cty[0]].build_lim[bu] += building[bu].limit_per_land;
                    if(wldMap[x][y].owner != "nobody"){
                        //int id = ctyList.find(wldMap[x][y].owner);
                        int id = (wldMap[x][y].owner == "Player"
                            ? 0
                            : wldMap[x][y].owner[2] - '0');
                        //lose land, lose some building
                        for(string bu: buildingList){
                            player[id].build_lim[bu] -= building[bu].limit_per_land;
                            if(player[id].qty_owned[bu] > player[id].build_lim[bu]) 
                                player[id].qty_owned[bu] = player[id].build_lim[bu];
                        }
                            
                    }
                }
                wldMap[x][y].owner = ctyList[cty[0]];
                // gain land addition
                //then next part, cal internal econ, will see who remains in this land
            }
        }
    }

    // cal internal econ
    pair<int, int> main_city[4] = {
        {0,0}, {3,0}, {0,3}, {3,3}
    };
    //loop through the player
    for(int i = 0; i < 4; i++){
        cout << countryList[i] << endl;
        cout << "before:" << endl << player[i]<< endl; // testing

        //resources consumption
        //--not enough food will stop producing army and citizens
        bool starvation = (player[i].food < player[i].soldier * 2 + player[i].tank * 2 + player[i].citizen);
        //--food consumption
        player[i].food = max(0, player[i].food - player[i].soldier * 2);
        player[i].food = max(0, player[i].food - player[i].tank * 2);
        if(player[i].food < player[i].citizen){
            player[i].citizen -= player[i].food;
            player[i].food = 0;
        }else{
            player[i].food -= player[i].citizen;
        }

        //resources production
        int x = main_city[i].first, y = main_city[i].second;
        //loop through the bilding list
        for(int j = 0; j < 6; j++){
            string bu = buildingList[j];
            int qty = player[i].qty_owned[bu];
            if(!qty) continue;
            
            if(bu != "recruiting-office" && bu != "factory"){
                player[i] += building[bu].production * qty;
                continue;
            }
            
            if(bu == "recruiting-office" && !starvation){
                for(int k = 1; k <= qty; k++){
                    if(!player[i].citizen) break;
                    int gain = (player[i].citizen < building[bu].production.soldier) 
                        ? player[i].citizen                     
                        : building[bu].production.soldier;
                    //citizens are recruited to be soldier
                    player[i].citizen -= gain;
                    player[i].soldier += gain;
                    wldMap[x][y].army[i].soldier += gain;
                }
            }
            if(bu == "factory" && !starvation){
                for(int k = 1; k <= qty; k++){
                    if(!player[i].citizen) break;
                    int gain = (player[i].citizen < building[bu].production.tank) 
                        ? player[i].citizen                     
                        : building[bu].production.tank;
                    //citizens are recruited to be tank driver
                    player[i].citizen -= gain;
                    player[i].tank += gain;
                    wldMap[x][y].army[i].tank += gain;
                }
            }   
        }
        
        cout << "after:" << endl << player[i]<< endl << endl; // testing        
    }
    
    //determine destruction of countries

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
Resources &Resources::operator*(const int &b)
{
    this->food *= b, this->fuel *= b, this->metal *= b, this->citizen *= b, this->soldier *= b, this->tank *= b;
    return *this;
}
// food, fuel, metal, ppl, tank, soldier, milFac, maxPop;
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
void readLine(string &str){
    while(1){
        char c = getchar();
        if(c == '\n' && str.size() > 0) return;
        if(c != '\n') str += c;
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
bool check_res(int id, Resources res){
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

void end_game(string status)
{
    if(status == "survive"){
        system("clear");
        cout << "mission complete! Survived!" << endl;
    }else if(status == "fail"){
        system("clear");
        cout << "mission failed!" << endl;
    }
}