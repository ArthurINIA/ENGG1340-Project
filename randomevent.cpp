#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int event(){
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
    return 0;
}
