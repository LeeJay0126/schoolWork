//-------------------------------------------------------------
// Lab 3: Elementary Programming
// Question 5 for CPSC 1155 Lab 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 20
//-------------------------------------------------------------


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

    double distance;
    double milesPerGallon;
    double pricePerGallon;
    double costOfDriving;
    cout << "Enter the driving distance: ";
    cin >> distance;
    cout << "Enter miles per gallon: ";
    cin >> milesPerGallon;
    cout << "Enter price per gallon: ";
    cin >> pricePerGallon;
    costOfDriving = (distance / milesPerGallon) * pricePerGallon;
    cout << "The cost of driving is $" << fixed << setprecision(2) << costOfDriving;

}