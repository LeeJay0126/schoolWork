//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){

    char letterInput, letter;
    int correspondingNumber;

    cout << "Enter a letter: ";
    cin >> letter;

    letterInput = toupper(letter);

    switch(letterInput){
        case 'A':
        case 'B':
        case 'C':
            cout << "The corresponding number is: 2";
            break;
        case 'D':
        case 'E':
        case 'F':
            cout << "The corresponding number is: 3";
            break;
        case 'G':
        case 'H':
        case 'I':
            cout << "The corresponding number is: 4";
            break;
        case 'J':
        case 'K':
        case 'L':
            cout << "The corresponding number is: 5";
            break;
        case 'M':
        case 'N':
        case 'O':
            cout << "The corresponding number is: 6";
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            cout << "The corresponding number is: 7";
            break;
        case 'T':
        case 'U':
        case 'V':
            cout << "The corresponding number is: 8";
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            cout << "The corresponding number is: 9";
            break;
        default:
            cout << letter << " is an invalid input";
    }


}