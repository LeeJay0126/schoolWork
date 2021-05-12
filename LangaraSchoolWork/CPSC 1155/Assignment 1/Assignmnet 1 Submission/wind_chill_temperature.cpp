//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 3 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 21
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

    double tempFahr;
    double speedMiles;
    double windChill;

    cout << "Enter the temperature in Fahrenheit (must be between - 58F and 41F): ";
    cin >> tempFahr;
    cout << "Enter the wind speed miles per hour (must be greater than or equal to 2): ";
    cin >> speedMiles;
    windChill = (35.74 + (0.6215*tempFahr)-(35.75*pow(speedMiles,0.16))+(0.4275*tempFahr*pow(speedMiles,0.16)));
    cout << "The wind chill index is :" << windChill; 

}