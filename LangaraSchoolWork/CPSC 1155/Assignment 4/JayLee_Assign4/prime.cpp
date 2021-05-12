//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

    cout << "Enter the start point : ";
    int startPoint;
    cin >> startPoint;
    cout << "Enter the number of prime numbers: ";
    int numberOfPrime;
    cin >> numberOfPrime;
    cout << "Enter how many numbers to display per row: ";
    int rows;
    cin >> rows;

    int divCounter;
    int primeCounter = 0;

    for (int i = startPoint; i < numberOfPrime; i++)
    {

        divCounter = 0;
        int j;
        for (j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                divCounter++;
            }
        }
        if (divCounter == 2)
        {
            primeCounter++;
            cout << left<< setw(5) << j-1;
            if ((primeCounter % rows) == 0)
            {
                cout << endl;
            }
        }
    }
}