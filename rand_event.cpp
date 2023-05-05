#include "all_interface.h"
#include <random>
using namespace std;

void pick_random_event(){
    
    string eventl[10];
    eventl[0] = "A peaceful day";
    eventl[1] = "Nothing happen"; 
    eventl[2] = "Wave of unemployment"; // farm, factory decrease
    eventl[3] = "Nothing happen";
    eventl[4] = "Food crisis"; // farm decrease
    eventl[5] = "Nothing happen"; 
    eventl[6] = "Defence Secretary of your city turn coat!"; // millitaryval decrease
    eventl[7] = "Nothing happen";
    eventl[8] = "Strike"; // manpower decrease in one round
    eventl[9] = "Oil refinery collapse"; // oil refinery -1
    
    srand(time(0));
    int pick = rand() % 10;
    
    vector<string> show; 
    show.push_back(eventl[pick]);
    show_round_result(show);
}
/*
int eventlist_content(){
    eventl[0] = "Help from other country"; // increase diplomaticval 
    eventl[1] = "Nothing happen"; 
    eventl[2] = "Wave of unemployment"; // farm, factory decrease
    eventl[3] = "Nothing happen";
    eventl[4] = "Food crisis"; // farm decrease
    eventl[5] = "Nothing happen"; 
    eventl[6] = "Defence Secretary of your city turn coat!"; // millitaryval decrease
    eventl[7] = "Nothing happen";
    eventl[8] = "Strike"; // manpower decrease in one round
    eventl[9] = "Oil refinery collapse"; // oil refinery -1
    eventl[10] = "Your country send a wreck hook to quake-afflicted country"; // increase diplomaticval
    eventl[11] = "Exchange Fund increased by 10%"; // econ increase
    eventl[12] = "Nothing happen";
    eventl[13] = "Econoy cooperation with other country"; // increase diplomaticval
    eventl[14] = "Military Laboratory has developed a new weapon"; // milliteryval increase
    eventl[15] = "Nothing happen";
    eventl[16]= "Nothing happen";
    eventl[17] = "A new fertilizer has developed in your country"; // farm factory increase
    eventl[18]= "Pandemic"; // manpower, born rate decrease
    eventl[19] = "Recruiting office in your country draft more army"; // milliteryval increase
    return 0;
}

void event(){
    int randomevent = rand() % 20;
    cout << eventl[randomevent] << endl;
    if (randomevent == 0){
        int eventpick = rand()%3;
        int eventpick = rand()%3;
        if (eventpick == 0){
            country[3][2] += 100;
        }
        if (eventpick == 1){
            country[12][2] += 100;
        }
        if (eventpick == 2){
            country[15][2] += 100;
        }
        
    }
    if (randomevent == 2){
        player.food -=200;
        player.metal *= 0.8;
    }
    if (randomevent == 4){
        player.food -= 700;
    }
    if (randomevent == 6){
        player.millitary_factor -= 1000;
    }
    if (randomevent == 8){
        player.population -= 100000;
    }
    if (randomevent == 9){
        play.fule *= 0.7;
    }
    if (randomevent == 10){
        int eventpick = rand()%3;
        if (eventpick == 0){
            country[3][2] += 100;
        }
        if (eventpick == 1){
            country[12][2] += 100;
        }
        if (eventpick == 2){
            country[15][2] += 100;
        }
    }
    if (randomevent == 11){
        player.metal *= 1.1;
    }
    if (randomevent == 13){
        int eventpick = rand()%3;
        if (eventpick == 0){
            country[3][2] += 100;
        }
        if (eventpick == 1){
            country[12][2] += 100;
        }
        if (eventpick == 2){
            country[15][2] += 100;
        }
    }
    if (randomevent == 14){
        player.millitary_factor *= 1.2;
    }
    if (randomevent == 17){
        player.food *= 1.3;
        player.metal *= 1.1;
    }
    if (randomevent == 18){
        player.population *= 0.5;
    }
    if (randomevent == 19){
        player.millitary_factor *= 1.2;
        player.population *= 0.9;
    }
}
*/