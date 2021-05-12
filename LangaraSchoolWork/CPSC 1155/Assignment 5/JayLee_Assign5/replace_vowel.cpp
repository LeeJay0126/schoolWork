//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 8
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
bool isVowel(char);
string replaceV(string, char);

int main(){

    string inputString,resultString;
    char inputChar;

    cout << "Enter a string: ";
    getline(cin , inputString);
    cout << "Enter a character: ";
    cin >> inputChar;

    resultString = replaceV(inputString, inputChar);

    cout << "The new string is: " << resultString;

    return 0;
}

bool isVowel(char k){
    switch(k){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'O':
        case 'U':
            return true;
            break;
        default:
            return false;
            break;
    }
}

string replaceV(string input, char change){

    string result = "";
    for(int i = 0; i < input.length(); i++){
        if(isVowel(input[i])){
            result += change;
        }else{
            result+= input[i];
        }
    }
    return result;

}