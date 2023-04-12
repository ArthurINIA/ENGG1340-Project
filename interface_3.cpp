#include <vector>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;
extern resources player, millitaryval, diplomaticval;
extern buildings oil_refinery, factory, farm, house, recruiting_office, mine, casino, military_laboratory;


string eventl[20];
string input;
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
    if 
}
struct map{
    int num;
    int requiredpower;
};
void printmap(){
    
}

int instruction(){
    cout << "+-------------------------------------------------------------------------------------+" << endl;
    cout << "In this interface you can choose to or not to attack the unoccupied land or other countries." << endl;
    cout << "REMINDER! YOU WILL NOT KNOW THE REQUIRED MILLITARY VALUES THAT MAKE YOU OCCUPIED SUCCESSFULLY" << endl;
    cout << "If you don't have enough millitary value, you will lose ALL value you try to attack!" << endl;
    cout << "THINK WISELY BEFORE ATTACK" << endl;
    return 0;
}


void run_interface_3(vector<string> &cmd){
    cout << "interface 3" << endl; //testing
    instruction();
    cout << "Please enter show / attack / peace (no need spacing):";
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
        if (millitaryval >= requiredpower){
            // get the land
            millitaryval /=2;
        }else{
            int chosenum;
            cout << "Your millitary level is lower then the land you want to attack"<< endl;
            cout << "You can enter a number (1-3) to get a stragegy to see if you can win in the war." << endl;
            cout << " Wrong entering see as fail the war." << endl;
            cout << "Please enter (1-3) ";
            cin >> chosenum;
            int ran = rand()%4 +1;
            if (chosenum == ran){
                cout << "You win the war tragicly." << endl;
                //get the land
                millitaryval /= 5;
            }else{
                cout << "You lose in the war. " << endl;
                millitaryval = 0;
            }
        }

    }else if (input == "peace"){
        diplomaticval +=5;
        event();
    }else{
        cout << "Invalid command." << endl;
        return;
    }
    
    
}
