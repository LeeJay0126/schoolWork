// Name: Jay Seung Yeon Lee
// CPSC 2150 Assignment #1
// document the functions

#include "fcts.h"
#include <iostream>
#include <string>
#include <climits> // CHAR_BIT

using std::string, std::cerr, std::ostream;

//---------------------------------------------------------------------------//
//
//
// precondition:
//    0 <= n <= declared size of A
// postcondition
//    A[0] > A[1] > ... > A[n-1]
bool isStrictlyDescending(const int A[], int n)
{
   if (n - 1 == 0 & A[n] > A[n - 1])
   {
      return true;
   };
   if (n - 1 == 0 & A[n] < A[n - 1])
   {
      return false;
   }
   if (A[n - 2] > A[n - 1])
   {
      return false;
   };

   return isStrictlyDescending(A, n - 1);
}

//---------------------------------------------------------------------------//
//
// precondition: n > 0
void swapPairsLeftToRight(int A[], int n)
{
   if (!(n <= 0))
   {
      int temp;
      temp = A[n - 1];
      A[n - 1] = A[n - 2];
      A[n - 2] = temp;

      swapPairsLeftToRight(A, n - 2);
   }
}

//------------------------------------------------------------------------------
//
//
void outputAsHex(unsigned int n, ostream &out)
{
   cerr << "+++++++++++++ outputAsHex not implemented ++++++++++++++++++++++\n";
}

//------------------------------------------------------------------------------
//
//
void outInOctal(unsigned int n, ostream &out)
{
   cerr << "000000 outInOctal not implemented 000000000000000000000000000000\n";
}

//------------------------------------------------------------------------------
//
//
bool insideInOrder(const string &pattern, int m, const string &str)
{
   cerr << "-------- insideInOrder not implemented -------------------------\n";
}

//------------------------------------------------------------------------------
//
//
bool insideInOrderI(const string &pattern, int m, const string &str)
{
   cerr << "________ insideInOrder not implemented _________________________\n";
}
