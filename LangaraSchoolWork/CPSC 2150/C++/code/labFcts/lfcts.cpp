// Name: 
// CPSC 2150  Lab I
// document the functions
// the iterative version has been done 

#include <string>
#include <iostream>
#include "lfcts.h"

using std::string, std::cerr;

// convert a character to a number by subtracting the ASCII value
// of '0' from the character
// precondition:
//   ch is a digit '0' up to and including '9'
// postcondition:
//   return a value 0 up to and including 9
// CPSC 2150: note how the code to number is placed before it is called
// in toIntegerI
int number(char ch) {
   return ch - '0';
}

// iterative version is so much more natural than the recursive version
int toIntegerI(const string& str) {
   int n = str.length();  // assigning an unsigned int size_t to an int
   if (n < 1) {
      return 0;
   }
   int val = number(str[n-1]);
   int factor = 10;
   for (int i = n - 2; i >= 0; i--) {
      val = val + factor * number(str[i]);
      factor *= 10;
   }
   return val;
}

//---------------------------------------------------------------------------//
int toInteger(const string& str) {
   cerr << "+++++++++++++ toInteger not implemented +++++++++++++++++\n";
}

// copyright 2023 Gladys Monagan 
