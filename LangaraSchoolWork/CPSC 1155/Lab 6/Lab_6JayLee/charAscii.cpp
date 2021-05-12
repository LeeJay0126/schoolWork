//-------------------------------------------------------------
// CPSC 1155 Lab 6 Math, Charactersm Strings, Files
// Question 2 of Lab 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 10
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
using namespace std;

int main(){

    cout << "Enter an ASCII code (between 0 and 255): ";
    int ASCIICode;
    cin >> ASCIICode ;
    if(ASCIICode >= 0 && ASCIICode < 256){
        cout << "The character is " << char(ASCIICode) << endl;
    }else {
        cout << "Invalid entry" << endl;
    }

    cout << "Enter a letter (A to Z or a to z) :";
    char letter;
    cin >> letter;
    int letterInt = int(letter);
    if(letterInt >= 65 && letterInt <= 90){
        cout << "Letter is uppercase";
    }else if(letterInt >= 97 && letterInt <= 122){
        cout << "Letter is lowercase";
    }else{
        cout << "Invalid entry";
    }




}