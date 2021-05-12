//-------------------------------------------------------------
// Lab 10 c++ functions
// CPP program for CPSC 1155 Lab 10 Question 2
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double windChill(double speed, double temperature){

    double temp;
    if((temperature > -58 && temperature < 41) && speed > 2){
        temp = (35.74 + (0.6215*temperature) - (35.75*pow(speed,0.16)) + (0.4275*temperature*pow(speed,0.16)));
    }

    return temp;

}

int main(){

    double temperature, speed;

    cout << "Enter the outside temperature (must be over -58F and below 41F): ";
    cin >> temperature;
    cout << "Enter the speed of the wind (must not be below 2mph): ";
    cin >> speed;

    cout << "Wind-chill temperature is " << fixed << setprecision(2)<< windChill(speed,temperature);

}