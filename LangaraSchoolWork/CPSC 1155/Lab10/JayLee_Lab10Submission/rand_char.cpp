//-------------------------------------------------------------
// Lab 10 c++ functions
// CPP program for CPSC 1155 Lab 10 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

char randomCharacter(char an, char bn){

    char random;
    
    if(an < bn){
        random = (an + rand()%(bn-an+1));
    }

    return random;
}

int main(){

    srand(time(0));

    string randomPW = "";

    randomPW += randomCharacter('A','Z');
    randomPW += randomCharacter('A','Z');
    randomPW += randomCharacter('a','z');
    randomPW += randomCharacter('a','z');
    randomPW += randomCharacter('0','9');
    randomPW += randomCharacter('0','9');
    cout << randomPW;

    return 0;
}