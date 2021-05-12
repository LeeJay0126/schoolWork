//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

void isPrime(int i){

    int counter;
    int prime = 0;
    for(int j = 1; j <= i; j++){
        counter = 0;
        for(int k = 1; k <= j; k++){
            if(j%k == 0){
                counter++;
            }
        }
        if(counter==2){
            if(prime % 10 == 0){
                cout << endl;
            }
            cout << left << setw(5) << j ;
            prime++;

        }
    }

}

int main(){
    isPrime(1000);
    return 0;
}