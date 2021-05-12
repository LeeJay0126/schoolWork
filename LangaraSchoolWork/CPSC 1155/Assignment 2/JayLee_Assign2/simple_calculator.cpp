//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 2
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
#include <string>
using namespace std;

int main(){

    int intFirst;
    int intSecond;
    string op;

    cout << "Enter two integers : ";
    cin >> intFirst >> intSecond;

    cout << "Enter an arithmetic operator (+,-,*,/): ";
    cin >> op;

    if(op == "+"){
        cout << "Result = " <<intFirst << " + " << intSecond << " = " << intFirst + intSecond;
    }else if(op == "-"){
        cout << "Result = " <<intFirst << " - " << intSecond << " = " << intFirst - intSecond;
    }else if (op == "*"){
        cout << "Result = " <<intFirst << " * " << intSecond << " = " << intFirst * intSecond;
    }else if(op == "/"){
        if(intFirst != 0 && intSecond != 0){
             cout << "Result = " <<intFirst << " / " << intSecond << " = " << intFirst / intSecond;
        }else{
            cout << "Can not divide or divide by 0";
        }
    }else{
        cout << "invalid operator";
    }

}