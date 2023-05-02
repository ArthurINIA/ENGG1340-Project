#include "all_interface.h"
#include "main.h"
#include "struct.h"
#include "UI.h"
#include <string>
#include <algorithm>
using namespace std;

int country [16][3] = {{1, 0, 0}, {2, 50000,0}, {3, 70000, 0}, {4, 130000, 0},{5, 70000, 0}, {6, 100000, 0}, {7, 130000, 0}, {8, 180000, 0}, {9, 140000, 0}, {10, 170000, 0}, {11, 250000, 0}, {12, 140000, 0}, {13, 210000, 0}, {14, 270000, 0}, {15, 300000, 0}, {16, 260000, 0}};
int alliance [3]={0,0,0};
int count_alliance = 0;
void show_map(){

}

bool check_exist(int code){
    if (code >=1 and code <=16){
        if (country[code-1][0] != 1){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}



void run_interface_3(vector<string> &cmd){
    UI gameScreen;
    int target_country;
    if (cmd == "show map"){

    }else if(cmd == "attack"){
        show_map;
        cout << "Select a country :"<< endl;
        cin >> target_country;
        if (check_exist(target_country)){
            if(player.military_factor >= country[target_country-1][2]){
                // get the land
                country[target_country-1][0] = 1;
                play.military_factor /= 2;
            }else{
                if (count_alliance!= 0){
                    int ran = rand() % 3;
                    if(alliance[ran] != 0){
                        cout << "alliance will help you." << endl;
                        country[(alliance[ran])-1][2] += 150;
                        if ((player.military_factor*1.3 >= country[target_country-1][1])){
                            cout << "You win" << endl;
                            // get the land
                            country[target_country-1][0] = 1;
                            play.military_factor /= 3;
                        } else{
                            cout << "You lose" << endl;
                            player.military_factor *= 0.1;
                        }
                    }
                }
                    
                
            }
        }
    }else if(cmd == "ally"){
        show_map;
        cout << "Select a country :"<< endl;
        cin >> target_country;
        if (country[target_country-1][2] >= 700){
            alliance[count_alliance] = target_country;
            count_alliance +=1;
            cout << "success" << endl;
        }else{
            cout << "fail" << endl;
        }
    }else{
        cout << "Invalid command" << endl;
    }
}
