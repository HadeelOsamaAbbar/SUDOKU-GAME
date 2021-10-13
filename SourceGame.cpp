#include <iostream>
#include<stdio.h>
#include <windows.h>
#include <conio.h>
#include<iomanip>
#include<Vector>
#include "actionGaming.h"
#include "SourceGame.h"
#include<windows.h>
using namespace std;

int main() {
    SetConsoleTitle(TEXT("SUDOKU GAME *-*"));
    int set[] = { 11,11,11,11,10,1,4,15,22 };
    int count = 1, endC = 0, menuC = 0, check = 0;
    int choose,choose2;
    int  h1 = 0, m1 = 0, s1 = 0;

    int countGame = 0, x = 0;
    int col = 0, row, numT = 0, numH=0;
    char key, keyGame{};
    char in,h;//h for help, in for input value from user
    bool found1 = false, found2 = false;
    actionGaming actGame;    
    while (true)
    {
        actGame.color(8);
        cout << "\n\t\tSODOKU GAME\n\n";
        actGame.gotoxy(12, 1);
        actGame.color(set[7]);

        cout << "\n\n\tMENU GAME:";
        while (true) {           
            actGame.menu(count, key);

            if (key == '\r') {
                if (count == 3)
                {
                    endC = 1;
                    break;
                }
                else if (count == 2) {
                    actGame.info();
                    actGame.color(set[6]);
                    cout << "\tpress [M] to back to Menu\n";
                    cout << "\tpress [E] to back to End\n";
                    
                    while (true)
                    {
                        cout << "\t";

                        cin >> in;
                        if (in == 'm' || in == 'M')
                        {
                            menuC = 1;
                            system("cls");
                            break;
                        }
                        else if (in == 'e' || in == 'E')
                        {
                            menuC = 0;
                            endC = 1;
                            break;
                        }
                        else {
                            cout << "\tInvalid\n";
                        }
                    }
                    break;
                }
                else if (count == 1) {
                    cout << "\n\n";
                    menuC = 0;
                    actGame.numLevels();
                    
                    
                    while (true)
                    {
                        cin >> choose;
                        if (choose == 1)
                        {
                            actGame.sitting();
                            actGame.color(set[1]);
                            cout << "\t\tLEVEL EASY\n\n";
                            break;
                        }
                        else if (choose == 2)
                        {
                            actGame.sitting();
                            actGame.color(set[1]);
                            cout << "\t\tLEVEL MEDIAM\n\n";
                            break;
                        }
                        else if (choose == 3) 
                        {
                            actGame.sitting();
                            actGame.color(set[1]);
                            cout << "\t\tLEVEL HARD\n\n";
                            break;
                        }
                        else
                        {
                            actGame.color(4);
                            cout << "\t\tInvalid\n";
                            cout << "\t\t";
                        }
                    }
                        
                        actGame.color(set[7]);
                        actGame.b = true;
                        
                        actGame.showGame(choose);
                        actGame.timer(m1, s1);
                        if (check == 0) {
                            break;
                        }
                    
                }
            }
        }
        if (menuC == 1)
            continue;
        actGame.color(set[4]);
        if (endC != 1)
            cout << "\n\tstart the game\n";
        while (true) {
            
            if (endC == 1)
            { 
                break;
            }
            actGame.color(set[4]);
            cout << "\tEnter value & col & row\n";
            cout << "\t";
            cin >> in;
            if (in >= '1' && in <= '9')
            {
                cin >> col >> row;
                if (col < 1 || col>9 || row < 1 || row>9)
                {
                    actGame.color(4);
                    cout << "\n\tinvalid Input,,Try agin\n";
                    continue;
                }

                else {
                    if (actGame.sudokuboard[row - 1][col - 1] != ' ') {
                        actGame.color(1);
                        cout << "\n\tUnavaliable place\n\n";
                    }                       
                    else if (actGame.checkBox((row - 1) - (row - 1) % 3, (col - 1) - (col - 1) % 3, in) || actGame.checkRow(row - 1, in) || actGame.checkColumn(col - 1, in)) {
                        numT++;
                        actGame.color(4);
                        cout << "\n\tWrong Input..\n\n";
                        if (numT == 4) {
                            actGame.color(4);
                            cout << "\n\tGAME OVER!! ^.^ :( ): (-_-)\n";
                            int s2 = 0, m2 = 0;
                            actGame.timer(m2,s2);
                            m2 -= m1;
                            s2 -= s1;
                            if (m2 < 0) {
                                m2 *= -1;
                            }
                            if (s2 < 0) {
                                s2 *= -1;
                            }
                            cout << "\tTotal Time is: ";
                            if (m2 < 10)
                                cout << '0';
                            cout << m2 << ":";
                            if (s2 < 10)
                                cout << '0';
                            cout << s2 << '\n';
                            found1 = false;
                            found2 = false;
                            while (true)
                            {
                                cout << "\n\t1. Play agian\n\t2. Close\n";
                                cin >> in;
                                if (in == '1')
                                {
                                    menuC = 0;
                                    system("cls");
                                    numT = 0;
                                    actGame.sudoku();
                                    break;
                                }
                                else if (in == '2') {
                                    endC = 1;
                                    actGame.sudoku();
                                    numT = 0;
                                    break;
                                }
                                else
                                {
                                    cout << "\tInvalid input\n";
                                }
                            }
                            break;
                        }
                        
                    }
                    else if (actGame.sudokuboard[row - 1][col - 1] == ' ') {
                        actGame.sudokuboard[row - 1][col - 1] = in;
                        actGame.WRITE(in, col, row);
                        found1 = true;
                        actGame.color(5);
                        cout << "\n\tGood Step\n\n";
                        x++;
                    }
                    
                    if (actGame.winGame(menuC, endC, m1, s1)) {
                        found1 = false;
                        found2 = false;
                        actGame.sudoku();
                        break;
                    }
                    else
                    {
                        actGame.color(set[7]);
                        actGame.showGame(choose);
                    }

                   

                }
            }
            else if (in == 'u' || in == 'U') {
                //undo code
                if (found1) {
                    actGame.UNDO();
                    actGame.color(4);
                    cout << "\tDone Undo\n";
                    found2 = true;
                    actGame.color(set[7]);
                    actGame.showGame(choose);
                }
                else
                {
                    actGame.color(4);
                    cout << "\n\tYou can't Undo.\n";
                }

            }
            else if (in == 'R' || in == 'r') {
                //redo code
                if (found2) {
                    actGame.REDO();
                    actGame.color(4);
                    cout << "\tDone Redo\n";
                    actGame.color(set[7]);
                    actGame.showGame(choose);
                }
                else
                {
                    actGame.color(4);
                    cout << "\n\tYou can't Redo.\n";
                }
            }
            else if (in == 'M' || in == 'm') {
                //menu code
                menuC = 0;
                system("cls");
                numH = 0;
                found1 = false;
                found2 = false;
                actGame.sudoku();
                break;
            }
            else if (in == 'A' || in == 'a') {
                //restart code
                menuC = 0;
                found1 = false;
                found2 = false;
                system("cls");
                numH = 0;
                actGame.sudoku();
                break;
            }
            else if (in == 'h' || in == 'H') {
                //help code
                if (numH >= 3)
                {
                    actGame.color(4);
                    cout << "\tYou can't use help again >.<\n";
                    continue;
                }
                cout << "\tEnter row and col\n";
                cin >> row >> col;
                if (row >= 1 && row <= 9 && col >= 1 && col <= 9) {
                    if (actGame.sudokuboard[row - 1][col - 1] == ' ')
                    {
                        h = actGame.askHelp(row, col);
                        actGame.sudokuboard[row - 1][col - 1] = h;
                        numH++;
                        actGame.color(5);
                        actGame.WRITE(h, col, row);
                        found1 = true;
                        cout << "\tDone Help\n";
                    }
                    else {
                        actGame.color(1);
                        cout << "\n\tUnavaliable place\n\n";
                        continue;
                    }
                }
                else
                {
                    actGame.color(4);
                    cout << "\tInvalid\n";
                }
                if (actGame.winGame(menuC, endC, m1, s1)) {
                    found1 = false;
                    found2 = false;
                    actGame.sudoku();
                    break;
                }
                else
                {
                    actGame.color(set[7]);
                    actGame.showGame(choose);
                }
                
            }
            else if (in == 'e' || in == 'E') {
                //end code
                endC = 1;
                continue;
            }
            else
            {
                cout << "\tInvalid\n";
                continue;
            }
            //system("cls");
            //break;
        }
        if (endC == 1)
        {
            actGame.color(set[8]);
            cout << "\n\n\n\t\tGOOD BYE o.o\n";
            break;
        }
    }
    actGame.color(0);
    return 0;
}


        


    


