//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 7
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    int number;
    cout << "Enter a number between 0 and 511: ";
    cin >> number;

    int binary[9];

    if(number > 511||number < 0){
        cout << "Enter a number between 0 and 511";
    }else{
       
        for(int i = 8; i >= 0; i--){
            binary[i] = number % 2;
            number /= 2;
        }
    }
    cout << "The binary number is: ";
    for(int i = 0; i < 9; i++){
        cout << binary[i];
    }
    cout << endl;

    cout << "The matrix is: " ;
    for(int j = 0; j < 9; j++){
        if(j % 3 == 0){
            cout << endl;
        }
        if(binary[j] == 0){
            cout << "H";
        }else{
            cout << "T";
        }
    }

}