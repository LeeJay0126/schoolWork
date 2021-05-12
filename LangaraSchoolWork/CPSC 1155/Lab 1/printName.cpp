//-------------------------------------------------------------
// Lab 1: Working with an online tool
// printName.cpp: This program asks for your name and greets you!
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 07
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Declare a variable for your name 
	string name;
	// Ask for the input 
	cout << "Please enter your name: ";
	cin >> name;
	// A greeting is printed
	 cout << "Hello " << name << endl;
	return 0;
} // End main