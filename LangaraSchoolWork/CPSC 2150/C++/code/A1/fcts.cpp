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
// helper function for returning the right hexadecimal for the given input
char toHexDecimal(int n)
{

   char result = n;

   switch (n)
   {
   case 10:
      n = 'A';
      break;
   case 11:
      n = 'B';
      break;
   case 12:
      n = 'C';
      break;
   case 13:
      n = 'D';
      break;
   case 14:
      n = 'E';
      break;
   case 15:
      n = 'F';
      break;
   case 16:
      n = 'G';
      break;
   default:
      n = n;
   }

   return n;
}

void outputAsHex(unsigned int n, ostream &out)
{
   if (!(n >= 16))
   {
      int remainder = n % 16;
      int nextInt = n / 16;
      char newHex = toHexDecimal(remainder);

      out << newHex;

      outputAsHex(nextInt, out);
   }
}

//------------------------------------------------------------------------------
//
//
void outInOctal(unsigned int n, ostream &out)
{
   
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
