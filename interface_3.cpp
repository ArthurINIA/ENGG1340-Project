#include <vector>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;
extern resources player, millitaryval, diplomaticval;
extern buildings oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;


string eventl[20];
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
int event(){
    int randomevent = rand() % 20;
    if (randomevent == 1){
        diplomaticval += 20;
    }
}

void printmap(){
    
}

void instruction(){
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "In this interface you can choose to or not to attack the unoccupied land or other countries." << endl;
    cout << "REMINDER! YOU WILL NOT KNOW THE REQUIRED MILLITARY VALUES THAT MAKE YOU OCCUPIED SUCCESSFULLY" << endl;
    cout << "THINK WISELY BEFORE ATTACK" << endl;
}



void run_interface_3(vector<string> &cmd){
    cout << "interface 3" << endl; //testing
    cout << "Please enter show / attack / peace :";
    cin >> input ;
    if (input == "show"){
        printmap();
    }else if (input == "attack"){
        int attnum = 0;
        printmap();
        cout << "Enter the number of the land you would like to attack: ";
        cin >> attnum;
        while (attnum<2 || attnum> 15){
            cout << "Enter the number of the land you would like to attack: ";
            cin >> attnum;
        }
    }else if (input == "peace"){
        event();
    }else{
        cout << "Invalid command." << endl;
        return;
    }
    
    
}
