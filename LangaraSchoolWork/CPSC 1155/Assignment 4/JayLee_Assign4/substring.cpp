//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int main(){

    cout << "Input a string : ";
    string string1;
    getline(cin,string1);
    cout << "Input another string: ";
    string string2;
    getline(cin, string2);
    int i;
    int validator = 0;

    if(string2.length() > string2.length()){
        cout << "Your second string input must be shorter than your first string input"<< endl;
    }
    for(i = 0; i <string1.length(); i++){
        if(string1.substr(i,string2.length()) == string2){
            validator = 1;
            cout << "\""<< string2 << "\"" << " is a substring of " << "\"" << string1 << "\"" << " starting at letter " << i+1 << endl;
        }
    }
    if(validator == 0){
        cout << "\""<< string2 << "\"" << " is not a substring of " << "\"" << string1<< "\""<< endl;
    }
}