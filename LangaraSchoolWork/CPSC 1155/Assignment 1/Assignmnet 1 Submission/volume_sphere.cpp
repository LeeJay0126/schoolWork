//-------------------------------------------------------------
// Assignment 1 Sequential Programming
// Question 1 of Assignment 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 22
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main(){

    double radius;
    double volume;

    cout << "Enter radius of sphere: ";
    cin >> radius;
    volume = 1.3333 * M_PI * pow(radius,3);
    cout << "The volume of the sphere is : " << fixed << setprecision(2) << volume;

}