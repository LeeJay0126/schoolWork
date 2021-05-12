//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 2 Question 5 
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 13
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

/* 
    Pseudocode:
    float feet
    float meters
    read feet
    set meters = feet * 0.305
    display meters
*/

int main(){

    float feet;
    float meters;
    cout << "Enter the value of feet: ";
    cin >> feet;
    meters = feet * 0.305;
    cout << feet << " feet is " << meters << " meters.";

}