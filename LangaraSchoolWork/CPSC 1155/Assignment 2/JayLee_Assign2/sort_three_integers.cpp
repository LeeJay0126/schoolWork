//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    int intFirst;
    int intSecond;
    int intThird;
    int temp;

    cout << "Enter three integers: ";
    cin >> intFirst >> intSecond >> intThird;

    temp = 0;

    if (intFirst > intSecond)
    {
        temp = intFirst;
        intFirst = intSecond;
        intSecond = temp;

        if (intSecond > intThird)
        {
            temp = intSecond;
            intSecond = intThird;
            intThird = temp; 
            
            if (intFirst > intSecond)
            {
                temp = intFirst;
                intFirst = intSecond;
                intSecond = temp;
            }
        }
    }
    cout << intFirst << " " << intSecond << " " << intThird;
}