#include <iostream>
#include <string>
#include "all_interface.h"
using namespace std;

//list of functions
void printIntro();
void pick_random_event();
void processAction(string cmd);
void end_game();

string countryList[] = {"Player", "PC1", "PC2", "PC3"};

int main()
{
    printIntro();
    for (int round = 0; round < 50; round++)
    {
        for (string curCountry : countryList)
        {
            pick_random_event();

            if(curCountry == "Player"){
                // let player make decision;
                string cmd;
                while (getline(cin, cmd))
                {
                    if (cmd == "end")
                    {
                        // may need to print sth
                        break;
                    }
                    processAction(cmd);
                }
            }
            
            round_result();
        }
    }
    end_game();
}

void printIntro(){
    string introStory[] = {
        "In the last century, the Earth was overdeveloped by human civilization, and the energy catastrophe and the pollution storm were unprecedented destructive forces that reverted to the civilized world."
        ,"The catastrophe not only set back human civilization in terms of technology and desertification of most of the land, but also brought about a horrific change to the earth - \"a black miasma covering the outer atmosphere, with daylight no longer within reach\"."
        ,"Talents spring up in the turbulent days, your country's rising stars of the future have been put into new energy research, cold fusion technology is about to be completed."
        ,"The countries are struggling for land, searching for rare raw energy under the region, for the sake of national peace and security."
        ,"You, as a commander, please keep your resources intact and hold the border until the cold fusion arrives."
        ,"......"
        ,"......"
        ,"01-Jan-2023"
        ,"  Nuclear Department Head: Greetings sir, I have a good news to you."
        ,"  Nuclear Department Head: The testing phase of the cold fusion has come to the last step."
        ,"                      You: How many days are needed?"
        ,"  Nuclear Department Head: 50 more days before our new era."
        ,"  Nuclear Department Head: Please protect us from the neighbouring threats."
        ,"......"
        ,"......"
        ,"Can you keep your country alive in the next 50 days?"
    };
    for(string x: introStory) cout << x << endl;
}

void pick_random_event(){

}

void processAction(string cmd)
{
    show_data();
    internal_actions();
    external_actions();
}

void end_game(){

}