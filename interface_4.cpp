#include "all_interface.h"
#include "UI.h"
using namespace std;

UI i4 = UI();
vector<string> history;

void init_i4()
{
    // i4.divide(1, 1, 120, 5, "resource-bar");
    i4.divide(1, 1, 20, 5, "interface-name"); // initialize interface 4 UI interface
    // i4.divide(40, 1, 60, 5, "resource-1");
    // i4.divide(60, 1, 80, 5, "resource-2");
    // i4.divide(80, 1, 100, 5, "resource-3");
    // i4.divide(100, 1, 120, 5, "resource-4");
    i4.divide(1, 5, 20, 29, "manual");
    i4.divide(20, 1, 120, 29, "game-content");
}

void run_interface_4(vector<string> &cmd)
{
    vector<string> content;                  // contains all result
    if (cmd[0] == "to" && cmd[2] == "admin") // below is debugging
    {
        for (int i = 0; i < 4; i++)
        {
            content.push_back(countryList[i] + " resources");
            content.push_back(
                "food: " + to_string(player[i].food) + " fuel: " + to_string(player[i].fuel) + " metal: " + to_string(player[i].metal) + " citizen: " + to_string(player[i].citizen) + " soldier: " + to_string(player[i].soldier) + " tank: " + to_string(player[i].tank));
            for (int j = 0; j < 3; j++)
            {
                string bu = buildingList[j * 2];
                string tt = bu;
                tt += " Owned: " + to_string(player[i].qty_owned[bu]);
                tt += " build limit:" + to_string(player[i].build_lim[bu]);
                tt += " ";
                bu = buildingList[j * 2 + 1];
                tt += bu;
                tt += " Owned " + to_string(player[i].qty_owned[bu]);
                tt += " Lim " + to_string(player[i].build_lim[bu]);
                content.push_back(tt);
            }
        }
    }

    show_round_result(content);
}

void show_round_result(vector<string> content)
{
    // history = content;
    string str1 = "Food: " + to_string(player[0].food), str2 = "Fuel: " + to_string(player[0].fuel), str3 = "Metal: " + to_string(player[0].metal), str4 = "Citizen: " + to_string(player[0].citizen);
    // cout << content << endl;
    vector<string> vec1 = {str1}, vec2 = {str2}, vec3 = {str3}, vec4 = {str4};

    i4.drawAll("interface-name", "center", {"Day : " + to_string(curGameDay), "Interface 4:", "Round Result"});
    // i4.drawAll("resource-1", "center", vec1);
    // i4.drawAll("resource-2", "center", vec2);
    // i4.drawAll("resource-3", "center", vec3);
    // i4.drawAll("resource-4", "center", vec4);

    // cout << "ok" <<endl; //testing
    // for(auto x: content) cout << x << endl; //testing
    i4.drawAll("game-content", "center", content);

    vector<string> i4_sidebarInfo = {"Try typing", "the following:", "show buildable", "show info", "build", "to i1", "to i2", "to i3", "end", "quit", "help"};
    i4.drawAll("manual", "center", i4_sidebarInfo);
    i4.print();
}