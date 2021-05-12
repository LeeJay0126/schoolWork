//-------------------------------------------------------------
// Lab 3: Elementary Programming
// Question 4 for CPSC 1155 Lab 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 20
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{

    cout << "Size of integer is: " << sizeof(short) << " bytes" << endl;
    cout << "SHRT_MIN is: " << SHRT_MIN << endl;
    cout << "SHRT_MAX is: " << SHRT_MAX << endl;

    cout << "Size of integer is: " << sizeof(int) << " bytes" << endl;
    cout << "INT_MIN is: " << INT_MIN << endl;
    cout << "INT_MAX is: " << INT_MAX << endl;

    cout << "Size of integer is: " << sizeof(long) << " bytes" << endl;

    cout << "LONG_MIN is: " << LONG_MIN << endl;
    cout << "LONG_MAX is: " << LONG_MAX << endl;

    cout << "Size of integer is: " << sizeof(long long) << " bytes" << endl;
    cout << "LLONG_MIN is: " << LLONG_MIN << endl;
    cout << "LLONG_MAX is: " << LLONG_MAX << endl;

    cout << "Size of integer is: " << sizeof(float) << " bytes" << endl;
    cout << "FLT_MIN is: " << FLT_MIN << endl;
    cout << "FLT_MAX is: " << FLT_MAX << endl;

    cout << "Size of integer is: " << sizeof(double) << " bytes" << endl;
    cout << "DBL_MIN is: " << DBL_MIN << endl;
    cout << "DBL_MAX is: " << DBL_MAX << endl;

    cout << "Size of integer is: " << sizeof(long double) << " bytes" << endl;
    cout << "LDBL_MIN is: " << LDBL_MIN << endl;
    cout << "LDBL_MAX is: " << LDBL_MAX << endl;
}