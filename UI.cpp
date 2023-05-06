#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "UI.h"
using namespace std;

UI::UI()
{
    // clean whole screen to be spaces
    for (int i = 1; i <= SCREEN_H; i++)
        for (int j = 1; j <= SCREEN_W; j++)
            grid[j][i] = ' ', wdcolor[j][i] = "\033[38;5;95m", bgcolor[j][i] = "\033[40m";
    // the root region to be the who;e screen
    regionList["whole"] = ui_region(1, 1, SCREEN_W, SCREEN_H);
}

void UI::print()
{
    system("clear");
    for (int i = 1; i <= SCREEN_H; i++){
        for (int j = 1; j <= SCREEN_W; wdcolor[j][i]="\033[38;5;95m", bgcolor[j][i]="\033[40m", j++)
            cout << wdcolor[j][i] << bgcolor[j][i] << grid[j][i];
        cout << endl;
    }
}

void UI::divide(int x1, int y1, int x2, int y2, string Cname)
{
    regionList[Cname] = ui_region(x1, y1, x2, y2);
    // draw the boundaries
    grid[x1][y1] = grid[x1][y2] = grid[x2][y1] = grid[x2][y2] = '+';
    for (int x = x1 + 1; x <= x2 - 1; x++)
        grid[x][y1] = grid[x][y2] = '-';
    for (int y = y1 + 1; y <= y2 - 1; y++)
        grid[x1][y] = grid[x2][y] = '|';
}
// set middle / left / right
// vertical set middle, start at (numOfScreenRow - numOfContentRow) / 2s
// print
void UI::drawLineStart(string tarArea = "whole")
{
    drawLineCounter[tarArea] = 0;
    cur_region = tarArea;
    // create a dynamic array to store the line by line screen drawing
    drawBufferStorage = new string[SCREEN_H + 1];
    drawBufferStorage_size = 0;
}

void UI::drawLine(string hAlign, string contentToAdd)
{
    // assume always len0 >= len1 + 2
    int len0 = regionList[cur_region].w - 2;
    int len1 = contentToAdd.length();
    int len2 = len0 - len1;
    int *pos = &drawBufferStorage_size;
    string tt = contentToAdd;
    
    for (int i = 0; i < len2; i++)
    {
        if (hAlign == "right" || (hAlign == "center" && i <= len2 / 2))
            tt = ' ' + tt;
        else if (hAlign == "left" || (hAlign == "center" && i > len2 / 2))
            tt += ' ';
    }
    tt = "|" + tt + "|";
    drawBufferStorage[*pos] = tt;
    (*pos)++;
}
void UI::drawLineStop()
{
    int y1 = regionList[cur_region].uly;
    int y2 = regionList[cur_region].lry;
    int x1 = regionList[cur_region].ulx;
    int x2 = regionList[cur_region].lrx;
    int emtyRow = regionList[cur_region].h - 2 - drawBufferStorage_size;

    for (int i = 0, y = y1 + 1; y <= y2 - 1; y++)
    {
        for (int j = 0, x = x1; x <= x2; j++, x++)
        {
            // upper and lower spaces
            if (y < y1 + 1 + emtyRow / 2 || y >= y1 + 1 + emtyRow / 2 + drawBufferStorage_size)
            {
                grid[x][y] = " |"[x == x1 || x == x2];
            }
            // content
            else
            {
                grid[x][y] = drawBufferStorage[i][j];
                if (x == x2)
                    i++;
            }
        }
    }

    delete[] drawBufferStorage;
}

void UI::setBackgroundColor(int x1, int y1, int x2, int y2, string color)
{
    for(int y = y1; y <= y2; y++) for(int x = x1; x <= x2; x++) bgcolor[x][y] = color;
}
void UI::setWordColor(int x1, int y1, int x2, int y2, string color)
{
    for(int y = y1; y <= y2; y++) for(int x = x1; x <= x2; x++) wdcolor[x][y] = color;
}

void UI::drawAll(string tarArea, /* string vAlign, */ string hAlign, vector<string> contentToAdd)
{
    drawLineStart(tarArea);
    // loop through each line of the string to draw it one by one
    for (string x : contentToAdd)
        drawLine(hAlign, x);
    drawLineStop();
}

void UI::drawAll(string tarArea, /* string vAlign, */ string hAlign, string raw_output){
    //create a stringstream object to parse the string
    stringstream ss(raw_output); 
    // create a vector of strings to store the substrings
    vector<string> output_vec;
    string substr;
    while (getline(ss, substr, '\n')) { // loop through each line of the string
        output_vec.push_back(substr); // add the line to the vector
    }
    // print out the vector of strings
    drawAll(tarArea, hAlign, output_vec);
}

ui_region::ui_region(int x1, int y1, int x2, int y2)
{
    ulx = x1, uly = y1, lrx = x2, lry = y2;
    w = lrx - ulx + 1;
    h = lry - uly + 1;
}

void colortest(){
}