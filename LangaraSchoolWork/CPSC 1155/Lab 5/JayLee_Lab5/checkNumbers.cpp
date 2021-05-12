//-------------------------------------------------------------
// CPSC 1155 Lab 5 Selection Statements
// Question 6 of Lab 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main(){

    int int1;
    int int2;
    
    cout << "Enter two integers: ";
    cin >> int1 >> int2;

    int temp;

    if(int2 > int1){

        temp = int2;
        int2 = int1;
        int1 = temp;

    }


    if(int1 == int2){
        cout << int1 << " is equal to " << int2;
    }else if(int1 == 0 || int2 == 0){
        cout << "Input must be greater than 0";
    }
    else if (int1 % int2 == 0){
        cout << int1 << " is larger than " << int2 << endl;
        cout << int1 << " is divisible by " << int2;
    }else if(int1 % int2 != 0){
        cout << int1 << " is larger than " << int2 << endl;
        cout << int1 << " is not divisible by " << int2;
    }

}