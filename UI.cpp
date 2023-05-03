#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "all_interface.h"
#include "UI.h"
using namespace std;

UI::UI()
{
    // clean whole screen to be spaces
    for (int i = 1; i <= SCREEN_H; i++)
        for (int j = 1; j <= SCREEN_W; j++)
            grid[j][i] = ' ';
    // the root region to be the who;e screen
    regionList["whole"] = ui_region(1, 1, SCREEN_W, SCREEN_H);
}

void UI::print()
{
    system("clear");
    for (int i = 1; i <= SCREEN_H; i++)
        for (int j = 1; j <= SCREEN_W; j++)
            cout << grid[j][i] << "\0\n"[j == SCREEN_W];
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
        if (hAlign == "left" || (hAlign == "center" && i <= len2 / 2))
            tt = ' ' + tt;
        else if (hAlign == "right" || (hAlign == "center" && i > len2 / 2))
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

void UI::setBackgroundColor(string bgColor)
{
}
void UI::setwordColor(string wdColor)
{
}

void UI::drawAll(string tarArea, /* string vAlign, */ string hAlign, vector<string> contentToAdd)
{
    drawLineStart(tarArea);
    for (string x : contentToAdd)
        drawLine(hAlign, x);
    drawLineStop();
}

ui_region::ui_region(int x1, int y1, int x2, int y2)
{
    ulx = x1, uly = y1, lrx = x2, lry = y2;
    w = lrx - ulx + 1;
    h = lry - uly + 1;
}

/*int main()
{
    UI gameScreen;
    string s;
    // gameScreen.print();
    gameScreen.divide(1, 1, 120, 5, "resource-bar");
    gameScreen.divide(1, 1, 40, 5, "interface-name");
    gameScreen.divide(40, 1, 60, 5, "resource-1");
    gameScreen.divide(60, 1, 80, 5, "resource-2");
    gameScreen.divide(80, 1, 100, 5, "resource-3");
    gameScreen.divide(100, 1, 120, 5, "resource-4");
    gameScreen.divide(1, 5, 40, 29, "manual");
    gameScreen.divide(40, 5, 120, 29, "game-content");

    gameScreen.drawAll("interface-name", "center", {"Interface 2: Internal Action"});
    gameScreen.drawAll("resource-1", "center", {"Food: xxxx"});
    gameScreen.drawAll("resource-2", "center", {"Fuel: xxxx"});
    gameScreen.drawAll("resource-3", "center", {"Metal: xxxx"});
    gameScreen.drawAll("resource-4", "center", {"Population: xxxx"});
    gameScreen.drawLineStart("manual");
    gameScreen.drawLine("center", "user manual");
    gameScreen.drawLine("center", "sdfsdfsdf");
    gameScreen.drawLineStop();
    gameScreen.print();
}*/