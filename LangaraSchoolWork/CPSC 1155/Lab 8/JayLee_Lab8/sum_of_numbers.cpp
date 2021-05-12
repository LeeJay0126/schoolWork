//-------------------------------------------------------------
// Lab 8 Loops
// CPP program for CPSC 1155 Lab 8 Question 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{

    int numberOfRepetitions;
    int number;
    int result;

    cout << "Enter the times you want to repeat: ";
    cin >> numberOfRepetitions;

    for (int i = 0; i < numberOfRepetitions; i++)
    {

        cout << "Enter a number : ";
        cin >> number;

        for (int j = 1; j <= number; j++)
        {

            if (j == 1)
            {
                result = 1;
            }
            else
            {
                result += j;
            }
        }

        cout << "The sum of 1 to " << number << " is " << result << endl;
    }
}