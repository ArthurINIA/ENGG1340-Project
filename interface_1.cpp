#include "all_interface.h"
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

/*int main(){
    //test printNum
    string num;
    cin >> num;
    printNum(num);
}*/