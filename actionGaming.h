#pragma once
#include <Vector>
#include <windows.h>
#include <conio.h>
#include<iomanip>
#include<stack>

class actionGaming
//#define N 9
{
public:
	std::vector< std::vector<char>> sudokuboard;
    int N = 9;
	std::stack<char> Undo;
	std::stack<char> Redo;
	int col;
	int row;
	bool b = true;
	bool t = false;
	int fill = 0;
public:
	actionGaming(void);
	bool checkColumn(int, char);
	bool checkBox(int, int, char);
	void showGame(int);
	bool checkRow(int, char);
	void sudoku();
	bool winGame(int&,int&, int&, int&);
	//design
	void color(int);
	void gotoxy(int, int);
	//menu
	void menu(int&,char&);
	void info();
	void sitting();
	//Undo && Redo
	void WRITE(char,int ,int);
	void UNDO();
	void REDO();
	void Movement(int, int);
	//rondom
	void level(int);
	//levels
	void numLevels();
	//ask help
	char askHelp(int,int);
	//timer
	void timer(int&,int&);
};

