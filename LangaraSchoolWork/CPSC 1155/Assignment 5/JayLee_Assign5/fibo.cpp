//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 7
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
long long fibonacci(int);

int main(){
    int num;
    cout << "Enter a number : ";
    cin >> num;
    
    long long max = fibonacci(num);
    cout << endl;
    cout << "The maximum input is : 53";

}

long long fibonacci(int n){
    long long fibon = 0;
    long long temp = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            fibon += 1;
            cout << "The series is: 0 ";
        }else if(i == 1){
            cout << fibon << " ";
        }else{
            fibon += temp;
            temp = fibon - temp;
            cout << fibon << " ";
        }
    }
    return temp;
}
