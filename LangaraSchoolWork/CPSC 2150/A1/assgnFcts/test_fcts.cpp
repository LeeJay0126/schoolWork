/* 
   ad hoc testing that does not depend on google test
   Gladys Monagan, CPSC 2150
*/ 
#include <iostream>
#include <string>
#include "fcts.h"

using std::string, std::cout, std::endl;

void test_outputAsHex() {
   cout << "actual    \t";
   outputAsHex(1529);
   cout << "\nexpected\t" << "5F9" << endl;
   cout << "actual    \t";
   outputAsHex(15);
   cout << "\nexpected\t" << "F" << endl;
   cout << "actual    \t";
   outputAsHex(16);
   cout << "\nexpected\t" << "10" << endl;
}

void test_outInOctal() {
   cout << "actual    \t";
   outInOctal(32);
   cout << "\nexpected\t" << "00000000040" << endl;
   cout << "actual    \t";
   outInOctal(1);
   cout << "\nexpected\t" << "00000000001" << endl;
   cout << "actual    \t";
   outInOctal(2147483647);
   cout << "\nexpected\t" << "17777777777" << endl;
}

void test_swapPairsLeftToRight() {
   int A[] = {11, 22, 33, 44, 55, 66};
   int EXPECTED_A[] = {22, 11, 44, 33, 66, 55};
   int n = 6;
   swapPairsLeftToRight(A, n);
   bool errorFound = false;
   for (int i = 0; !errorFound && (i < n); i++) {
      if (A[i] != EXPECTED_A[i]) {
         cout << "ERROR: poor swapping starting at A[" << i << "]\n";
         errorFound = true;
      }
   }
   if (!errorFound)
      cout << "swapped correctly for the one array" << endl;

   int B[] = {11, 22, 33, 44, 55};
   int EXPECTED_B[] = {22, 11, 44, 33, 55};
   n = 5;
   swapPairsLeftToRight(B, n);
   errorFound = false;
   for (int i = 0; !errorFound && (i < n); i++) {
      if (B[i] != EXPECTED_B[i]) {
         cout << "ERROR: poor swapping starting at B[" << i << "]\n";
         errorFound = true;
      }
   }
   if (!errorFound)
      cout << "swapped correctly for the one array" << endl;
   cout << endl;
}

int main() {
   test_outputAsHex();
   test_outInOctal();
   test_swapPairsLeftToRight();
   return 0;
}
