//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 2
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{

    int array[10];

    cout << "Enter 10 numbers: ";

    for (int i = 0; i < 10; i++)
    {
        cin >> array[i];
    }

    int array2[10];
    int count = 0;
    for(int j = 0; j < 10; j++){
        count = 0;
        for(int k = 0; k < 10; k++){
            if(array[j] == array2[k]){
                count++;
            }
        }
        if(count == 0){
            array2[j] = array[j];
        }else{
            array2[j] = 0;
        }
    }

    cout << "Distinct numbers are: ";

    for(int Q = 0; Q < 10; Q++){
        if(!(array2[Q] == 0)){
            cout << array2[Q] << "  ";
        }
    }
    
    
}
