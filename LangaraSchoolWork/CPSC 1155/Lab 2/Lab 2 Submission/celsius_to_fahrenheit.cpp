//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 2 Question 6 
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 13
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(){

    float celsius;
    float fahrenheit;
    cout << "What is the Celsius Value?: ";
    cin >> celsius;
    fahrenheit = (9 * celsius / 5) + 32;
    cout << celsius << " celsius is " << fahrenheit << " in fahrenheit.";

}