#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class ui_region
{
private:
    // stores xy-coordinates of the top-left corner and the bottom-right corner
public:
    int ulx = 0, uly = 0, lrx = 0, lry = 0;
    int w = 0, h = 0;
    ui_region(){};
    ui_region(int x1, int y1, int x2, int y2);
};

class UI
{
    char grid[122][47];                // the screen as a char array;
    std::string wdcolor[122][47], bgcolor[122][47]; //color setting of each grid, default dark brown word, black background
public:
    // private:
    int SCREEN_W = 120, SCREEN_H = 29; // dimension of the screen
    // char grid[SCREEN_W + 2][SCREEN_H + 2]; //the screen as a char array;
    std::map<std::string, ui_region> regionList; // stores the subdivided region in the UI screen;
    std::string cur_region;
    std::map<std::string, int> drawLineCounter; // for drawLine()
    std::string *drawBufferStorage;
    int drawBufferStorage_size = 0;
    // public:
    // constructor, init
    UI();
    // print the whole screen
    void print();
    // ability to set and divide the screen into different regions
    void divide(int x1, int y1, int x2, int y2, std::string Cname);

    // 2 modes to add content to the screen, add line by line or add all at once to a screen area
    /*
        add content line by line to the screen for a specific componets
        drawLineStart() tell the program to start putting the input
        drawLine() accept input line by line
        drawLineStop() tell the program to stop the input mode when inputting is finished, then it will start doing the positioning work
    */
    void drawLineStart(std::string tarArea);
    void drawLine(std::string hAlign, std::string contentToAdd);
    void drawLineStop();
    // set the background color and the word color of the next line
    void setBackgroundColor(int x1, int y1, int x2, int y2, std::string color);
    void setWordColor(int x1, int y1, int x2, int y2, std::string color);
    /*
        add all content at once by giving an array
    */
    void drawAll(std::string tarArea, /* string vAlign, */ std::string hAlign, std::vector<std::string> contentToAdd);
    //separate the content by '\n'
    void drawAll(std::string tarArea, /* string vAlign, */ std::string hAlign, std::string raw_string);
};

#endif