//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 3 Question 8
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

    int firstComplex;
    int secondComplex;

    int firstFirst;
    double firstSecond;
    int secondFirst;
    int secondSecond;
    double I;

    cout << "Enter the first complex number (real number followed by imaginary number): ";
    cin >> firstComplex;
    cout << "Enter the second complex number (real number followed by imaginary number): ";
    cin >> secondComplex;

    firstSecond = firstComplex % 10;
    firstComplex /= 10;
    firstFirst = firstComplex % 10;

    secondSecond = secondComplex % 10;
    secondComplex /= 10;
    secondFirst = secondComplex % 10;

    double firstSum;
    double secondSum;
    double thirdSum;
    double fourthSum;

    firstSum = firstFirst * secondFirst;
    secondSum = firstFirst * secondSecond;
    thirdSum = firstSecond * secondFirst;
    fourthSum = firstSecond * secondSecond;

    int total1;
    int total2;

    total1 = firstSum - fourthSum;
    total2 = secondSum + thirdSum;

    cout << "The product of " << noshowpos << firstFirst << showpos << firstSecond << "i"
         << " and " << noshowpos << secondFirst << showpos << secondSecond << "i"
         << " is " << showpos << total1 << showpos << total2 << "i";
}