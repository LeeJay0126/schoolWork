//-------------------------------------------------------------
// Assignment 1 Sequential Programming
// Question 3 of Assignment 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 22
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{

    int largePump;
    int smallPump;
    int poolcap;
    double hours;
    double smallPumpvalue;
    double largePumpvalue;

    cout << "Enter the number of large pumps: ";
    cin >> largePump;
    cout << "Enter the number of small pumps: ";
    cin >> smallPump;
    poolcap = 1;
    largePumpvalue = largePump * 0.1;
    smallPumpvalue = smallPump * 0.05;
    hours = poolcap / (largePumpvalue + smallPumpvalue);
    
    cout << "It will take " << hours << " hours to fill up the pool with "
         << largePump << " large pumps and " << smallPump << " small pumps.";

}