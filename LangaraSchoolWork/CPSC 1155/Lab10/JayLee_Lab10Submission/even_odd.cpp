//-------------------------------------------------------------
// Lab 10 c++ functions
// CPP program for CPSC 1155 Lab 10 Question 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
using namespace std;

bool evenOrOdd(int number){

    if(number % 2 == 0){
        return true;
    }else{
        return false;
    }

}

int main(){

    int number = 0;

    cout << "Enter an integer: ";
    cin >> number;

    if(evenOrOdd(number)){
        cout << number << " is even.";
    }else{
        cout << number << " is odd.";
    }

}

