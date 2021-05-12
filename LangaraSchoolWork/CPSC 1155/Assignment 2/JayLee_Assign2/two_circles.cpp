//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    double x1;
    double y1;
    double r1;
    double x2;
    double y2;
    double r2;
    double distance;

    cout << "Enter x1 , y1, r1 , x2, y2, r2 : ";
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    distance = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));

    if (r1 >= 0 && r2 >= 0)
    {

        if (distance <= (abs(r1 - r2)))
        {
            if (r1 > r2)
            {
                cout << "circle 2 is inside circle 1";
            }
            else if (r2 > r1)
            {
                cout << "circle 1 is inside circle 2";
            }
        }
        if (distance <= (r1 + r2))
        {
            cout << "circle 2 overlaps circle 1";
        }
        else
        {
            cout << "circle 2 does not overlap circle 1";
        }
    }
    else
    {
        cout << "Radii must be positive. ";
    }
}