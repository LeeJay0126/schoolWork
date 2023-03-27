// Name: Jay Lee
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

#include "hash_function.h"

// Referred from CPSC 2150 Class Notes
const string EMPTY = "";
void insertLinear(string xPtr, string *T, int m)
{
   int i = hash_fct(xPtr, m);
   for (int j = 0; j < m; j++)
   {
      if (T[i] == EMPTY)
      {
         T[i] = xPtr;
         return;
      }
      else
      {
         i = (i + 1) % m;
      }
   }
}

bool linearSearch(string xPtr, string *T, int m)
{
   int i = hash_fct(xPtr, m);
   for (int j = i; j < m; j++)
   {
      if (T[i] == xPtr)
      {
         return true;
      }
      else if (T[i] == EMPTY)
      {
         return false;
      }
      i = (i + 1) % m;
   }
}

void clearHash(string *T, int m)
{
   for (int i = 0; i < m; i++)
   {
      T[i] = EMPTY;
   }
}

void linearFunction(int loading, string *T)
{
   for (int i = 0; i < loading; i++)
   {
      bool flag = true;
      string temp;
      while (flag == true)
      {
         temp = getKey();
         flag = linearSearch(temp, T, loading);
      }
      insertLinear(temp, T, loading);
   }
}

int main()
{

   string *T;
   int m = 1999;
   T = new string[m];
   clearHash(T, 1999);

   // load factors
   const int lightLoad = 400;
   const int medLoad = 1000;
   const int largeLoad = 1600;

   // Linear Probing
   // Load factor 0.2
   auto start = std::chrono::steady_clock::now();
   for (int i = 0; i < 100; i++)
   {
      linearFunction(lightLoad, T);
      clearHash(T, lightLoad);
   }
   auto end = std::chrono::steady_clock::now();
   std::chrono::duration<double> diff = (end - start) / 100;
   auto lightLin = diff.count();
   cout << fixed << setprecision(4) << left;
   cout << setw(20) << "Linear" << setw(20) << "0.2 load factor" << setw(20) << lightLin << endl;

   // Load factor 0.5
   start = std::chrono::steady_clock::now();
   for (int i = 0; i < 100; i++)
   {
      linearFunction(medLoad, T);
      clearHash(T, medLoad);
   }
   end = std::chrono::steady_clock::now();
   std::chrono::duration<double> diff = (end - start) / 100;
   auto medLin = diff.count();
   cout << setw(20) << "Linear" << setw(20) << "0.5 load factor" << setw(20) << medLin << endl;

   // Load factor 0.8
   start = std::chrono::steady_clock::now();
   for (int i = 0; i < 100; i++)
   {
      linearFunction(largeLoad, T);
      clearHash(T, largeLoad);
   }
   end = std::chrono::steady_clock::now();
   std::chrono::duration<double> diff = (end - start) / 100;
   auto largeLin = diff.count();
   cout << setw(20) << "Linear" << setw(20) << "0.5 load factor" << setw(20) << largeLin << endl;

   return 0;
}
