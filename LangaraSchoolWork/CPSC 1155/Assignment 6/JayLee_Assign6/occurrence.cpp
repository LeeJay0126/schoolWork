//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int randomNumber();

using namespace std;

int main(){
    srand(time(0));
    int array[100];

    for(int i = 0; i < 100; i++){
        array[i] = randomNumber();
    }

    int count = 0;
    for(int j = 1; j <= 10; j++){
        count = 0;
        for(int k = 0; k < 100; k++){
            if(j == array[k]){
                count++;
            }
        }
        if(count > 1){
            cout << j << "  occurs " << count << " times" << endl;
        }else{
            cout << j << "  occurs " << count << " time" << endl;
        }
        
    }

    return 0;

}

int randomNumber(){
    int result = 0;
    result = (int)(1+(rand()%10));
    return result;
}