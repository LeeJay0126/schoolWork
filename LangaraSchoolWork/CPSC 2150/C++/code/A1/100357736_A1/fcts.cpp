// Name: Jay Seung Yeon Lee
// CPSC 2150 Assignment #1
// document the functions

#include "fcts.h"
#include <iostream>
#include <string>
#include <climits> // CHAR_BIT

using std::string, std::cerr, std::ostream;

//---------------------------------------------------------------------------//
// Function that verifies if an array is in strictly descending order
//
// precondition:
//    0 <= n <= declared size of A
// postcondition
//    A[0] > A[1] > ... > A[n-1]
bool isStrictlyDescending(const int A[], int n)
{
   if (n == 0 || n == 1)
   {
      return true;
   }

   if (n == 2 && A[n - 1] > A[n - 2])
   {
      return true;
   }

   if (A[n - 1] >= A[n - 2])
   {
      return false;
   }

   isStrictlyDescending(A, n - 1);
}

//---------------------------------------------------------------------------//
// function that swap pairs from left to right
// precondition: n > 0
//
void swapPairsLeftToRight(int A[], int n)
{

   if (n >= 2)
   {
      if (n % 2 == 1)
      {
         swapPairsLeftToRight(A, n - 1);
      }
      else
      {
         int temp;
         temp = A[n - 1];
         A[n - 1] = A[n - 2];
         A[n - 2] = temp;
         swapPairsLeftToRight(A, n - 2);
      }
   }
}

//------------------------------------------------------------------------------
//
//
// helper function for returning the right hexadecimal for the given input
char toHexDecimal(int number)
{

   int n = number;

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
      n = n + 48;
   }

   return n;
}
//------------------------------------------------------------------------------
//
//
// helper function for returning the right hexadecimal for the given input

void helperHex(unsigned int n, ostream &out)
{
   if (n != 0)
   {
      int remainder = n % 16;
      int nextInt = n / 16;
      char newChar;
      newChar = toHexDecimal(remainder);
      outputAsHex(nextInt, out);

      out << newChar;
   }
}
//------------------------------------------------------------------------------
//
//
// Function that takes unsigned int n and ostream &out to convert decimal number
// to a hexadecimal
void outputAsHex(unsigned int n, ostream &out)
{
   // if (n == 0)
   // {
   //    out << 0;
   // }
   // else
   // {
   helperHex(n, out);
   // }
}

//------------------------------------------------------------------------------
//
// function that takes decimal number and returns it in octal
void outInOctal(unsigned int n, ostream &out)
{
   if (!(n == 0))
   {
      int octal = n & 7;
      outInOctal(octal << 3, out);

      out << octal;
   }
}

//------------------------------------------------------------------------------
//
// helper function that counts the number of patterns in a string
int patternCounter(const string pattern, const string str, int counter, int strCount, int index, int validCount)
{
   if (index == pattern.length())
   {
      return counter;
   }
   if (pattern[index] == str[strCount])
   {
      if (strCount + 1 == str.length())
      {
         patternCounter(pattern, str, counter + 1, 0, index + 1, 0);
      }
      else
      {
         patternCounter(pattern, str, counter, strCount + 1, index + 1, validCount + 1);
      }
   }
   else
   {
      patternCounter(pattern, str, counter, 0, index + 1, 0);
   }

   return 0;
}

bool insideInOrder(const string &pattern, int m, const string &str)
{
   int valid = patternCounter(pattern, str, 0, 0, 0, 0);
   cerr << valid;
   if (valid >= m)
   {
      return true;
   }
   else
   {
      return false;
   }
}

//------------------------------------------------------------------------------
//
//
bool insideInOrderI(const string &pattern, int m, const string &str)
{
   // cerr << "________ insideInOrder not implemented _________________________\n";
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
