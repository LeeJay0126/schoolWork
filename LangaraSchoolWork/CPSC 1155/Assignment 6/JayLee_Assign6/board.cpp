//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 8
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
void createBoard(int[][5]);
void randomPosition(int board[][5]);
void display(int board[][5]);

int main()
{

    srand(time(0));
    int array[5][5];

    createBoard(array);
    randomPosition(array);

    display(array);
}

void createBoard(int board[][5])
{
    int k = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = k;
            k++;
        }
    }
}

void randomPosition(int board[][5])
{
    int randomNumber;
    int temp = 0;
    ;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            randomNumber = (int)(1 + (rand() % 25));
            x = randomNumber / 5;
            y = randomNumber % 5;
            temp = board[x][y];
            board[x][y] = board[i][j];
            board[i][j] = temp;
        }
    }
}

void display(int board[][5])
{

    cout << "-------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "|" << left << setw(4) << board[i][j];
            if (j == 4)
            {
                cout << "|";
            }
        }
        cout << endl;
        cout << "-------------------------" << endl;
    }
}