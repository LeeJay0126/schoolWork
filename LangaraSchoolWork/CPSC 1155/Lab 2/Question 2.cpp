//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 2 Question 2 
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 13
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(){

    double miles;
    cin >> miles;
    const double KILOMETERS_PER_MILE = 1.609;
    double kilometers;
    kilometers = miles * KILOMETERS_PER_MILE;
    cout << kilometers << " kilometers are in miles"  << endl;
    return 0;

}