//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.14159265

using namespace std;

int main(){

    double length;

    cout << "Enter the length from the center to a vertex: ";
    cin >> length;
    
    double side = (2*length)*sin(PI/5);
    double Area = (5*pow(side,2))/(4*tan(PI/5));
    if(length > 0){
        cout << "The area of the pentago is " << fixed << setprecision(2) << Area;
    }else{
        cout << "Length from the center to a vertex must be greater than 0. ";
    }
   

}