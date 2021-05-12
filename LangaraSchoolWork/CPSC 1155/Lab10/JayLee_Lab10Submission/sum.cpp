//-------------------------------------------------------------
// Lab 10 c++ functions
// CPP program for CPSC 1155 Lab 10 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>

using namespace std;

int sum(int i1, int i2){

      int result;
    if(i1 < i2){
      
        for(int i = i1; i <= i2; i++){
            result += i;
        }

    }

    return result;

}

int main(){

    int i1, i2;

    cout << "Enter your first integer: ";
    cin >> i1;
    cout << "Enter your second integer: ";
    cin >> i2;
    
    cout << "The sum is " << sum(i1,i2);

}
