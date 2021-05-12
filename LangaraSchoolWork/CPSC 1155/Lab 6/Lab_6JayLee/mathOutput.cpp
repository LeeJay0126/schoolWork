//-------------------------------------------------------------
// CPSC 1155 Lab 6 Math, Charactersm Strings, Files
// Question 1 of Lab 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 10
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

    double x, k;
    cout << "Enter x: ";
    cin >> x;

    k = exp(-x) + sqrt(exp(-x)) + exp(-sqrt(x)) + (exp(x)/x);

    cout << fixed << setprecision(6) << k;
}