//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main(){

    string stringInput;
    int digitCounter = 0;
    int upCaseCounter = 0;
    int lowCaseCounter = 0;
    int spaceCounter = 0;

    cout << "Enter a string: ";
    getline(cin, stringInput);

    for(int i = 0; i < stringInput.length(); i++){

        char s = stringInput[i];

        if(stringInput.length() < 1){
            cout << "Length of your string must be at least 1 character. " << endl;
        }
        if(s >= 'a' && s <= 'z'){
            lowCaseCounter++;
        }else if(s >= 'A' && s <= 'Z'){
            upCaseCounter++;
        }else if(s == ' '){
            spaceCounter++;
        }else if(s >= '0' && s<='9'){
            digitCounter++;
        }

    }

    cout << "The number of digits is " << digitCounter << endl;
    cout << "The number of uppercase letter is " << upCaseCounter << endl;
    cout << "The number of lowercase letter is " << lowCaseCounter << endl;
    cout << "The number of spaces is " << spaceCounter;

}