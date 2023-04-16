#include "all_interface.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

extern resources player;

void run_interface_1(vector<string> &cmd){
    //print admin panel
    cout << "interface 1" << endl; //testing
}

//testing code
void printNum(string s){
    cout << stoi(s) << endl;
}

int printUI1(){
    cout << "+-----------------------------------------------------------------------------+" << endl;
    cout << "|                               Interface 1                                   |" << endl;
    cout << "|-----------------------------------------------------------------------------|" << endl;
    cout << "|*Resource 01: Food                                                          *|" << endl;
    cout << "|*Total (units): " << setprecision(5) << player.food << "                                                            *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 02: Fuel                                                          *|" << endl;
    cout << "|*Total (units): " << setprecision(5) << player.fuel << "                                                            *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 03: Metal                                                         *|" << endl;
    cout << "|*Total (units): " << setprecision(5) << player.metal << "                                                            *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 04: Population                                                    *|" << endl;
    cout << "|*Total (units): " << setprecision(5) << player.population << "                                                            *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*City index 01: Diplomacy                                                   *|" << endl;
    cout << "|*Rate:                                                                      *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*City index 02: Livelihood                                                  *|" << endl;
    cout << "|*Rate:                                                                      *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*City index 03: Military                                                    *|" << endl;
    cout << "|*Rate:                                                                      *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|                                   Done!                                     |" << endl;
    cout << "+-----------------------------------------------------------------------------+" << endl;
}

/*int main(){
    //test printNum
    string num;
    cin >> num;
    printNum(num);
}*/

