//-------------------------------------------------------------
// Assignment 1 Sequential Programming
// Question 2 of Assignment 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 22
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(){

    int inputNumber;
    int number1;
    int number2;
    int number3;
    int sumOfNumbers;

    cout << "Enter a number between 0 and 1000: ";
    cin >> inputNumber;
    number1 = inputNumber % 10;
    inputNumber /= 10;
    number2 = inputNumber % 10;
    inputNumber /= 10;
    number3 = inputNumber % 10;
    inputNumber /= 10;
    sumOfNumbers = number1 * number2 * number3;
    cout << "The sum of the digits is " << sumOfNumbers;


}