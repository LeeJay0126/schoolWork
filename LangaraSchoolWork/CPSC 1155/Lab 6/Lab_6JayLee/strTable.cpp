//-------------------------------------------------------------
// CPSC 1155 Lab 6 Math, Charactersm Strings, Files
// Question 3 of Lab 6
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

    string firstname;
    string lastname;
    int grade;
    cout << "What is your first name? :";
    getline(cin, firstname);
    cout << "What is your last name? :";
    getline(cin, lastname);
    cout << "What is your grade? :";
    cin >> grade;
    if(grade <= 100){
        cout <<"|"<< left << setw(12)<<"firstname"<<"|"<<left<<setw(12)<<"lastname"<<"|"<<left<<setw(12)<<"grade"<<"|"<<endl;
        cout <<"|"<< left << setw(12)<<firstname<<"|"<<left<<setw(12)<<lastname<<"|"<<left<<setw(12)<<grade<<"|"<<endl;
    }
    else{
        cout << "grade must be equal to 100 or less";
    }


}