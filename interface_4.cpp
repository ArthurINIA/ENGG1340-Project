#include "all_interface.h"
#include "UI.h"
using namespace std;

void show_round_result(vector<string> content);
void round_result()
{
    //unfinished
    //cout << "calculating result" << endl;

    //cal external changes
    //put this first, coz war loss can reduce land, which destroy some of the player's building
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            vector<int> cty;
            for(int i = 0; i < 4; i++) 
                if(wldMap[x][y].army[i].soldier || wldMap[x][y].army[i].tank) 
                    cty.push_back(i);
            if(cty.empty()){
                wldMap[x][y].owner = "nobody";
            }
            else if(cty.size() == 1){
                string ctyList[] = {"Player", "PC1", "PC2", "PC3"};
                wldMap[x][y].owner = ctyList[cty[0]];
                //gain land addition
            }
            else{
                //war simulation!
            }
        }
    }

    //cal internal econ
    cout << "before:" << endl << player << endl; //testing
    for(map<string, Building>::iterator it = building.begin(); it != building.end(); it++){
        Building cur = it->second;
        player += cur.production * cur.qty_owned;
        if(it->first == "recruiting-office" && cur.qty_owned){
            wldMap[0][0].army[0].soldier += 750;
        }
        //not yet add daily tank if there is factory
    }
    cout << "after:" << endl << player << endl; //testing
}

void run_interface_4(vector<string> &cmd)
{
    // cout << "interface 4" << endl; // testing
    //cal_result();

    vector<string> content; // contains all result

    show_round_result(content);
}

void show_round_result(vector<string> content)
{
    // cout << "+-------------------------------------------------------------------------------------+" << endl;
    //  cout << "|";
    UI gameScreen;
    string s;
    string str1 = "Food: " + to_string(player.food), str2 = "Fuel: " + to_string(player.fuel), str3 = "Metal: " + to_string(player.metal), str4 = "Population: " + to_string(player.population);
    // cout << content << endl;
    vector<string> vec1 = {str1}, vec2 = {str2}, vec3 = {str3}, vec4 = {str4};
    gameScreen.divide(1, 1, 120, 5, "resource-bar");
    gameScreen.divide(1, 1, 40, 5, "interface-name");
    gameScreen.divide(40, 1, 60, 5, "resource-1");
    gameScreen.divide(60, 1, 80, 5, "resource-2");
    gameScreen.divide(80, 1, 100, 5, "resource-3");
    gameScreen.divide(100, 1, 120, 5, "resource-4");
    gameScreen.divide(1, 5, 40, 29, "manual");
    gameScreen.divide(40, 5, 120, 29, "game-content");

    gameScreen.drawAll("interface-name", "center", {"Interface 4: Round Result"});
    gameScreen.drawAll("resource-1", "center", vec1);
    gameScreen.drawAll("resource-2", "center", vec2);
    gameScreen.drawAll("resource-3", "center", vec3);
    gameScreen.drawAll("resource-4", "center", vec4);
    gameScreen.drawAll("game-content", "center", content);
    vector<string> i4_sidebarInfo = {"Try typing the following:", "show buildable", "show info", "build", "to i1", "to i2", "to i3", "end", "quit", "help"};
    gameScreen.drawAll("manual", "center", i4_sidebarInfo);
    gameScreen.print();
}