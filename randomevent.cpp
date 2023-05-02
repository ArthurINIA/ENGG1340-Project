#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int event(){
    int randomevent = rand() % 20;
    cout << eventl[randomevent] << endl;
    if (randomevent == 0){
        int eventpick = rand()%3;
        if (eventpick == 0){
            maplist[0].allianceval += 50;
        }
        if (eventpick == 1){
            maplist[3].allianceval += 50;
        }
        if (eventpick == 2){
            maplist[15].allianceval += 50;
        }
        
    }
    if (randomevent == 2){
        agriculture -=200;
        economy -= 300;
    }
    if (randomevent == 4){
        agriculture -= 700;
    }
    if (randomevent == 6){
        player.millitary -= 1000;
    }
    if (randomevent == 8){
        manpower -= 100000;
    }
    if (randomevent == 9){
        oil_refinery -= 1;
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
        economy *= 1.1;
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
        millitaryval *= 1.2;
    }
    if (randomevent == 17){
        agriculture *= 1.3;
        economy *= 1.1;
    }
    if (randomevent == 18){
        manpower *= 0.5;
    }
    if (randomevent == 19){
        player.millitary *= 1.2;
        manpower *= 0.9;
    }
    return 0;
}
