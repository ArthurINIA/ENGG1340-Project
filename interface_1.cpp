#include "all_interface.h"
#include <iostream>
#include <string>
using namespace std;

void run_interface_1(vector<string> &cmd)
{
    // print admin panel
    cout << "interface 1" << endl;                       // testing
    cout << "food: " << player.food << endl;             // testing
    cout << "fuel: " << player.fuel << endl;             // testing
    cout << "metal: " << player.metal << endl;           // testing
    cout << "population: " << player.population << endl; // testing
}

// testing code
void printNum(string s)
{
    cout << stoi(s) << endl;
}

int printUI1(){
    cout << "+-----------------------------------------------------------------------------+" << endl;
    cout << "|                               Interface 1                                   |" << endl;
    cout << "|-----------------------------------------------------------------------------|" << endl;
    cout << "|*Resource 01: Food                                                          *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 02: Fuel                                                          *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 03: Metal                                                         *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
    cout << "|*****************************************************************************|" << endl;
    cout << "|*Resource 04: Population                                                    *|" << endl;
    cout << "|*Total (units):                                                             *|" << endl;
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

