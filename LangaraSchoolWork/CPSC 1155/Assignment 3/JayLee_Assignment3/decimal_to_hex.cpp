//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main(){
    
    int decimalValue;
    string hexValue;

    cout << "Enter a decimal value : ";
    cin >> decimalValue;

    if(decimalValue >= 0 && decimalValue <= 15){

        switch(decimalValue){

            case 1: hexValue = 1;
            break;
            case 2: hexValue = 2;
            break;
            case 3: hexValue = 3;
            break;
            case 4: hexValue = 4;
            break;
             case 5: hexValue = 5;
            break;
             case 6: hexValue = 6;
            break;
             case 7: hexValue = 7;
            break;
             case 8: hexValue = "8";
            break;
             case 9: hexValue = "9";
            break;
             case 10: hexValue = "A";
            break;
             case 11: hexValue = "B";
            break;
             case 12: hexValue = "C";
            break;
             case 13: hexValue = "D";
            break;
             case 14: hexValue = "E";
            break;
             case 15: hexValue = "F";
            break;
        }
        
        cout << "The corresponding number is: " << hexValue;

    }else {

        cout << decimalValue << " is an invalid input";

    }

}