//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 7
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main()
{

    cout << "Enter your input: ";
    int userInput;
    cin >> userInput;
    string numberList = " ";
    int number = 0;
    int i = 2;
    int validator = 0;

    do
    {
        if (userInput % i == 0)
        {
            number = i;
            cout << number << "    ";
            userInput /= number;
            i = 2;
        }
        else
        {
            i++;
        }
        if (i > userInput)
        {
            validator = 1;
        }
    } while (!(validator == 1));
    
}