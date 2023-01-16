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
   if ((n - 1) == 0 & A[n] > A[n - 1])
   {
      return true;
   };
   if ((n - 1) == 0 & A[n] < A[n - 1])
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
string toHexDecimal(int number, string resultString)
{

   if(number == 0){
      return resultString;
   }

   int remainder = number % 16;
   int nextInt = number / 16;

   char n = remainder;

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
      n = char(remainder);
   }

   toHexDecimal(nextInt, resultString + n);
}

void outputAsHex(unsigned int n, ostream &out)
{
      string newHex = toHexDecimal(n, "");

      out << newHex;

}

//------------------------------------------------------------------------------
//
//
void outInOctal(unsigned int n, ostream &out)
{
   if (!(n == 0))
   {
      int octal = n & 7;
      char octalChar = char(octal);
      out << octalChar;

      outInOctal(octal << 3, out);
   }
}

//------------------------------------------------------------------------------
//
//
int patternCounter(const string pattern, const string str, int counter, int index)
{
   if (index >= pattern.length())
   {
      return counter;
   }
   if (pattern[index] == str[0] && pattern.length() - index - 1 >= 3)
   {
      if (pattern[index + 1] == str[1] && pattern[index + 2] == str[2])
      {
         patternCounter(pattern, str, counter + 1, index + 3);
      }
   }
   else
   {
      patternCounter(pattern, str, counter, index + 1);
   }
}

bool insideInOrder(const string &pattern, int m, const string &str)
{
   int valid = patternCounter(pattern, str, 0, 0);
   if (valid >= m)
   {
      return true;
   }
   return false;
}

//------------------------------------------------------------------------------
//
//
bool insideInOrderI(const string &pattern, int m, const string &str)
{
   cerr << "________ insideInOrder not implemented _________________________\n";
   int count = 0;
   for (int i = 0; i < pattern.length(); i++)
   {
      if (pattern[i] == str[0] && pattern[i + 1] == str[1] && pattern[i + 2] == str[2])
      {
         count += 1;
         i += 2;
      }
      else
      {
         i += 1;
      }
   }

   if (count >= m)
   {
      return true;
   }

   return false;
}
