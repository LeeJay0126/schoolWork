//-------------------------------------------------------------
// Lab 10 c++ functions
// CPP program for CPSC 1155 Lab 10 Question 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

string encodeString(string input){

    string newString;

    for(int i = 0; i < input.length(); i++){
        char character = input[i];
        switch(character){
            case 'o':
            case 'O':
                newString += '0';
                break;
            case 'L':
            case 'l':
                newString += '1';
                break;
            case 'b':
            case 'B':
                newString += '8';
                break;
            default: 
                newString += character;
                break;
        }
    }

    return newString;

}

int main(){

    string input1 = "";

    cout << "Enter your string: ";
    getline(cin, input1);

    input1 = encodeString(input1);

    cout << input1;

    return 0;

}