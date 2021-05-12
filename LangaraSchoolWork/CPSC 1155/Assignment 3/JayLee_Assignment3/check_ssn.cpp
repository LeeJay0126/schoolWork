//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main(){

    string ssn,firstDash,secondDash;

    cout << "Enter SSN: ";
    cin >> ssn;

    firstDash = ssn[3];
    secondDash = ssn[6];

    if(firstDash == "-" && secondDash == "-"){
        cout << ssn << " is valid";
    }else{
        cout << ssn << " is invalid";
    }

    

}