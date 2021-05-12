//-------------------------------------------------------------
// Assignment 1 Sequential Programming
// Question 5 of Assignment 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 22
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

    int contributionAmount;
    int years;
    double futureValue;
    double cinterest;
    int principalInvestment;
    double total;

    cout << "Enter the monthly contribution amount: ";
    cin >> contributionAmount;
    cout << "Enter the number of years: ";
    cin >> years;

    principalInvestment = 5000;
    futureValue = contributionAmount*(pow(1+0.09/12,(12*years))-1)/(0.09/12);
    cinterest = (principalInvestment * pow((1.0 + 0.09/12.0),(12.0 * years)));
    total = cinterest + futureValue;


    cout << "After " << years << " years, the portfolio vaule is $" << fixed << setprecision(2) << total << "   " << cinterest << "   " << futureValue << "    " << care;

}