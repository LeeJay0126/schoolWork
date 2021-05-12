//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 8
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main()
{

    int userInput;
    cout << "Enter your input between 1 to 10: ";
    cin >> userInput;

    if (userInput >= 1 && userInput <= 10)
    {
        for (int i = 1; i <= userInput; i++)
        {
            for (int j = 1; j <= userInput; j++)
            {
                if (j == i)
                {
                    cout << j;
                }
                else
                {
                    cout << "*";
                }
                if (j == userInput)
                {
                    cout << endl;
                }
            }
        }

        for (int i = userInput; i >= 1; i--)
        {
            for (int j = 1; j <= userInput; j++)
            {
                if (j == i)
                {
                    cout << j;
                }
                else
                {
                    cout << "*";
                }
                if (j == userInput)
                {
                    cout << endl;
                }
            }
        }
    }else{
        cout << "Please Enter an integer between 1 and 10";
    }
}