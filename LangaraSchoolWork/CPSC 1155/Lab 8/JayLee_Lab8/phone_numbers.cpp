//-------------------------------------------------------------
// Lab 8 Loops
// CPP program for CPSC 1155 Lab 8 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main(){

    cout << "Enter 10 digit integer number: ";
    string phoneNumber;
    cin >> phoneNumber;
    string result;
    result = "(" + phoneNumber.substr(0,3) + ")" + phoneNumber.substr(3,3) + "-" + phoneNumber.substr(6, 4);
    cout << result;

}