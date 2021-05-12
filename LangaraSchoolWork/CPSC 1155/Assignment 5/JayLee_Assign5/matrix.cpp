//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

int generate01()
{
    int random;
    random = (int)(rand() % 2);
    return random;
}

void printMatrix(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << left << setw(3) << generate01();
        }
        cout << endl;
    }
}

int main()
{
    int row;
    cout << "Enter row n : ";
    cin >> row;

    printMatrix(row);

    return 0;
}