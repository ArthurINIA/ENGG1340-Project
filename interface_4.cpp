#include "all_interface.h"
#include "UI.h"
using namespace std;

void run_interface_4(vector<string> &cmd){
    vector<string> content; // contains all result
    if(cmd[0] == "admin"){
        for(int i = 0; i < 4; i++){
            content.push_back(countryList[i] + " resources");
            content.push_back(
                "food: " + to_string(player[i].food)
                + "fuel: " + to_string(player[i].fuel)
                + "metal: " + to_string(player[i].metal)
                + "citizen: " + to_string(player[i].citizen)
                + "soldier: " + to_string(player[i].soldier)
                + "tank: " + to_string(player[i].tank)
            );
            for(int j = 0; j < 3; j++){
                string bu = buildingList[j*2];
                string tt = bu;
                tt += " Owned" + to_string(player[i].qty_owned[bu]);
                tt += " build Lim" + to_string(player[i].build_lim[bu]);
                tt += "\t";
                bu = buildingList[j*2 + 1];
                tt += bu;
                tt += " Owned " + to_string(player[i].qty_owned[bu]);
                tt += " Lim " + to_string(player[i].build_lim[bu]);
                tt += "\t";
                content.push_back(tt);
            }
        }
    }

    show_round_result(content);
}

void show_round_result(vector<string> content)
{
    string s;
    string str1 = "Food: " + to_string(player[0].food), str2 = "Fuel: " + to_string(player[0].fuel), str3 = "Metal: " + to_string(player[0].metal), str4 = "Citizen: " + to_string(player[0].citizen);
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
    
    //cout << "ok" <<endl; //testing
    //for(auto x: content) cout << x << endl; //testing
    gameScreen.drawAll("game-content", "center", content);
    
    vector<string> i4_sidebarInfo = {"Try typing the following:", "show buildable", "show info", "build", "to i1", "to i2", "to i3", "end", "quit", "help"};
    gameScreen.drawAll("manual", "center", i4_sidebarInfo);
    gameScreen.print();
}