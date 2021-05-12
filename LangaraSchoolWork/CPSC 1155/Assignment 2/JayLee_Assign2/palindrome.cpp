//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    int sixDigits;
    int digit1;
    int digit2;
    int digit3;
    int digit4;
    int digit5;
    int digit6;

    cout << "Enter your six digits: ";
    cin >> sixDigits;
    ;

    digit1 = sixDigits % 10;
    sixDigits /= 10;
    digit2 = sixDigits % 10;
    sixDigits  /= 10;
    digit3 = sixDigits % 10;
    sixDigits /= 10;
    digit4 = sixDigits % 10;
    sixDigits /= 10;
    digit5 = sixDigits % 10;
    sixDigits /= 10;
    digit6 = sixDigits % 10;

    if (digit1 == digit6)
    {
        if (digit2 == digit5)
        {
            if (digit3 == digit4)
            {
                cout << "These digits are palindrome.";
            }
            else
            {
                cout << "These digits are not palindrome.";
            }
        }
        else
        {
            cout << "These digits are not palindrome.";
        }
    }
    else
    {
        cout << "These digits are not palindrome.";
    }
}