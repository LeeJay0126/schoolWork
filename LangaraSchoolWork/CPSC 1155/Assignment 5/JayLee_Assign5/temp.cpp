//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

double celsius(double x){

    double farh;

    farh = ((x - 32) * 5/9);

    return farh;
}

double fahrenheit(double y){

    double cel;

    cel = ((y * 9/5)+32);

    return cel;

}

int main(){

    double f = 120.0;

    cout << left << setw(16) << "Celsius" << left << setw(16) << "Fahrenheit" << "||" << left << setw(16) << "Fahrenheit" << left << setw(16) << "Celsius" << endl;


    for(double i = 40.0; i >= 31.0; i--){

        cout << left << setw(16) << fixed << setprecision(1) << i << left << setw(16) <<  fixed << setprecision(1) << fahrenheit(i) << "||" << left << setw(16) <<  fixed << setprecision(1) << f << left << setw(16) <<  fixed << setprecision(2) << celsius(f) << endl;

        f -= 10.0;

    }

    return 0;
}