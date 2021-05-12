//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

double sumSeries(double i)
{
    double m;
    for (int j = i; i > 0; i--)
    {
        m += (i / (i+1));
    }
    return m;
}

int main()
{
    cout << left << setw(8) << "i" << left << setw(8) << "m(i)" << endl;
    for (double i = 1; i <= 20; i++)
    {
        cout << left << setw(8) << fixed << setprecision(0) << i << left << setw(8) << fixed << setprecision(4) << sumSeries(i) << endl;
    }
    return 0;
}