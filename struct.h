#include <string>
using namespace std;

struct resources
{
    int population;
    int food;
    int fuel;
    int metal;
};

struct buildings
{
    string name;
    string requirement;
    string description;
    string effect;
    int quantity;
};