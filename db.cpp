#include <fstream>
#include "all_interface.h"
using namespace std;

void save_data(){
    ofstream fout("save.txt");
    fout << curGameDay << endl;
    for(int i = 0; i < 4; i++){
        Country &P = player[i];
        fout << P.dead << endl;
        fout << P.food << " " << P.fuel << " " << P.metal << " " << P.citizen << endl;
        fout << P.soldier << " " << P.tank << endl;
        for(string j : buildingList){
            fout << P.build_lim[j] << " " << P.qty_owned[j] << endl;
        }
    }
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            i3Map &P = wldMap[x][y];
            fout << P.owner << endl;
            for(int i = 0; i < 4; i++) fout << P.army[i].soldier << " " << P.army[i].tank << " \n"[i == 3];
        }
    }
}
void load_data(){
    ifstream fin("save.txt");
    fin >> curGameDay;
    for(int i = 0; i < 4; i++){
        Country &P = player[i];
        fin >> P.dead;
        fin >> P.food >> P.fuel >> P.metal >> P.citizen;
        fin >> P.soldier>> P.tank;
        for(string j : buildingList){
            fin >> P.build_lim[j] >> P.qty_owned[j];
        }
    }
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            i3Map &P = wldMap[x][y];
            fin >> P.owner;
            for(int i = 0; i < 4; i++) fin >> P.army[i].soldier >> P.army[i].tank;
        }
    }
}