//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    double sideA;
    double sideB;
    double sideC;

    cout << "What is the lengths of the triangle? : ";
    cin >> sideA >> sideB >> sideC;

    double cosA;
    double smallNumber;

    smallNumber = 1.4e-300;

    double temp;

    if (sideA < sideB){

        temp = sideA;
        sideA = sideB;
        sideB = temp;

        if(sideA < sideC){
            temp = sideA;
            sideA = sideC;
            sideC = temp;
        }

    }

    cosA = (pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2)) / (2 * sideB * sideC);
    if (sideA >= 0 && sideB >= 0 && sideC >= 0)
    {
        if (abs(cosA - 0) < smallNumber)
        {
            cout << "The triangle with lengths"
                 << " " << sideB << " " << sideC << " " << sideA <<" is a right-side triangle";
        }
        else
        {
            cout << "The triangle with lengths"
                 << " " << sideB << " " << sideC << " " << sideA << " is not a right-side triangle";
        }
    }else{
        cout << "Lengths of a triangle must be positive " << smallNumber;
    }
}
