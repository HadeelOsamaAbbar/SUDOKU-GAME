#include "actionGaming.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include<iomanip>
#include<ctime>

using namespace std;

actionGaming::actionGaming() {
    sudokuboard = {
           {'5','8','1','2','3','4','9','7','6'},
           {'6','2','7','5','8','9','3','1','4'},
           {'3','4','9','7','1','6','5','8','2'},
           {'4','3','6','1','7','8','2','9','5'},
           {'1','5','2','9','6','3','7','4','8'},
           {'9','7','8','4','2','5','6','3','1'},
           {'7','6','4','8','9','2','1','5','3'},
           {'8','9','3','6','5','1','4','2','7'},
           {'2','1','5','3','4','7','8','6','9'}
    };
}
void actionGaming::sudoku() {
    sudokuboard = {
           {'5','8','1','2','3','4','9','7','6'},
           {'6','2','7','5','8','9','3','1','4'},
           {'3','4','9','7','1','6','5','8','2'},
           {'4','3','6','1','7','8','2','9','5'},
           {'1','5','2','9','6','3','7','4','8'},
           {'9','7','8','4','2','5','6','3','1'},
           {'7','6','4','8','9','2','1','5','3'},
           {'8','9','3','6','5','1','4','2','7'},
           {'2','1','5','3','4','7','8','6','9'}
    };
}
bool actionGaming::checkColumn(int c, char value)
{

    for (int r = 0; r < N; r++)
        if (sudokuboard[r][c] == value)
            return true;
    return false;
}

bool actionGaming::checkRow(int r, char value)
{
     
    for (int c = 0; c < N; c++)
        if (sudokuboard[r][c] == value)
            return true;
    return false;
}

bool actionGaming::checkBox(int initial_row, int initial_column, char value)
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (sudokuboard[r + initial_row][c + initial_column] == value)
                return true;
    return false;
}

void actionGaming::showGame(int num)
{
    level(num);
    int g = 20;
    for (int r = 0; r < N; r++) {
        cout << "\t   ";
        for (int c = 0; c < N; c++)
        {
            if (c == 3 || c == 6)
                cout << " | ";
            cout << sudokuboard[r][c] << " ";
        }g++;
        if (r == 2 || r == 5)
        {
            cout << endl;
            cout << "\t   ";
            for (int k = 0; k < N - 1; k++)
                cout << "---";
        }
        cout << endl;
    }
}
//--------menu-----------
void actionGaming::color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void actionGaming::gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void actionGaming::menu(int &count, char &key) {

    int set[] = { 5,5,5,11,10,1,4,15 };
    gotoxy(15, 5);

    color(set[0]);
    cout << "1. Start ";

    gotoxy(15, 6);
    color(set[1]);
    cout << "2. Information ";

    gotoxy(15, 7);
    color(set[2]);
    cout << "3. End ";
    
    color(7);
    key = _getch();
    if (key == 72 && (count == 2 || count == 3)) {//up
        count--; cout << count;
    }

    if (key == 80 && (count == 1 || count == 2)) {//down
        count++; cout << count;
    }
   
}
void actionGaming::info() {
    int set[] = { 11,11,11,11,10,1,4,15 };
    color(set[6]);
    cout << "\n\n\t\tSUDOKU GAME\n";
    color(set[7]);
    cout << "It is a puzzle that needs little introduction."
        << "\nThe object is to put a digit from 1 to N\nin each cell of the grid,\n" <<
        "so that every row, column, and bold region\ncontains each digit once,\n"
        << "where N is the number of rows and columns in \nthe puzzle\n\n";
    color(set[7]);
    cout << "Developed by:\n";
    color(set[5]);
    cout << "Hadeel Osama\tManar Mahmoud\tHajer Ahmed\n"
        << "Wejdan Fawy\tYasmin Ahmed\tMariem A Almomem\n";

}
//-----sitting-------
void actionGaming::sitting() {
    color(4);
    cout << "\n\n  press [U] to Undo\t" << "press [A] to Restart\n"
        << "  press [R] to Redo\t" << "press [E] to End\n"
        << "  press [M] to Menu\t" << "press [H] to Help\n\n";
}
//--------redo && undo------------

void actionGaming::WRITE(char value, int col,int row)
{
    Undo.push(value);
    Movement(col,row);
}
void actionGaming::UNDO()
{
    sudokuboard[row - 1][col - 1] = ' ';
    char value = Undo.top();
    Undo.pop();
    Redo.push(value);
}
void actionGaming::REDO()
{
    char value = Redo.top();
    Redo.pop();
    Undo.push(value);
    sudokuboard[row - 1][col - 1] = value;
}
void actionGaming::Movement(int col, int row)
{
    this->col = col;
    this->row = row;
    
}
//----rondom sudoku-----
void actionGaming::level(int num) {
    int n = 0;
    if (b == true) {
        if (num == 1)
            n = 2;
        else if (num == 2)
            n = 40;
        else if (num == 3)
            n = 50;
        srand(time(0));
        fill = 0;
        for (int i = 0; i < n; i++) {
            int p1 = rand() % 9;
            int p2 = rand() % 9;
            if (sudokuboard[p1][p2] != ' ') {
                sudokuboard[p1][p2] = ' ';
                fill++;
            }
        }
        //cout << "fill: "<<fill<<"\n";
        b = false;
    }
}
//-----num of levels------
void actionGaming::numLevels() {

    int set[] = { 7,7,7,11,10,1,9,15 };
    gotoxy(22, 9);
    color(set[6]);
    cout << "1. Easy ";

    gotoxy(22, 10);
    color(set[6]);
    cout << "2. Mediam ";

    gotoxy(22, 11);
    color(set[6]);
    cout << "3. Hard ";
     

}
//-------ask help --------
char actionGaming::askHelp(int row, int col) {
    char j = '1';
    for (int i = 0; i < 9; i++)
    {      
        if (!checkBox((row - 1) - (row - 1) % 3, (col - 1) - (col - 1) % 3, j) && !checkRow(row - 1, j) && !checkColumn(col - 1, j))
            return j;
        j++;
    }
     
}
void actionGaming::timer(int &m, int &s)
{
    time_t nowTime;
    struct tm nowLocal;
    nowTime = time(NULL);
    nowLocal = *localtime(&nowTime);
    m = nowLocal.tm_min;
    s = nowLocal.tm_sec;
    
}
//-------when the user win------
bool actionGaming::winGame(int &menuC,int& endC, int&m1, int&s1) {
    int x = 0;
    char in;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (sudokuboard[r][c] != ' ')
            {
                x++;
            }
        }
    }
    if (x == 81) {
        color(4);
       
        int m2 = 0, s2 = 0;
        timer(m2, s2);
        
        m2 -= m1;
        s2 -= s1;
        if (m2 < 0) {
            m2 *= -1;
        }
        if (s2 < 0) {
            s2 *= -1;
        }
        cout << "\tYOU WINNED ^.^ :) (: (-.-)\n";
        color(15);
        cout << "\tTotal Time is: ";
        if (m2 < 10)
            cout << '0';
        cout << m2 << ":";
        if (s2 < 10)
            cout << '0';
        cout<< s2 << '\n';
        
        while (true)
        {
            color(1);
            cout << "\n\t1. Play agian\n\t2. Close\n";
            cout << "\t";
            cin >> in;
            if (in == '1')
            {
                menuC = 0;
                system("cls");
                return true;
            }
            else if (in == '2') {
                endC = 1;
                return true;
            }
            else
            {
                cout << "\tInvalid input\n";
            }
        }
        
    }
    else
        return false;
}