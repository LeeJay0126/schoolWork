//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 8
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{

    int hour;

    cout << "Enter hour: ";
    cin >> hour;

    if (hour < 18)
    {
        cout << "afternoon";
    }
    else if (hour < 12)
    {
        cout << "morning";
    }
    else if (hour < 6)
    {
        cout << "night";
    }
    else
    {
        cout << "evening";
    }
}