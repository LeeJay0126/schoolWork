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
   int i = hash_fct(xPtr, 1999);
   for (int j = i; j < 1999; j++)
   {
      if (T[i] == EMPTY)
      {
         T[i] = xPtr;
         return;
      }
      else
      {
         i = (i + 1) % 1999;
      }
   }
}

bool linearSearch(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   for (int j = i; j < 1999; j++)
   {
      if (T[i] == xPtr)
      {
         return true;
      }
      else if (T[i] == EMPTY)
      {
         return false;
      }
      else
      {
         i = (i + 1) % 1999;
      }
   }
   return false;
}

int linearSearchCount(string xPtr, string *T, int loading)
{
   int i = hash_fct(xPtr, 1999);
   int result = 0;
   for (int j = 0; j < loading; j++)
   {
      if (T[i] == xPtr)
      {
         return result + 1;
      }
      else if (T[i] == EMPTY)
      {
         return result + 1;
      }
      i = (i + 1) % 1999;
      result += 1;
   }

   return result;
}

void clearHash(string *T)
{
   for (int i = 0; i < 1999; i++)
   {
      T[i] = EMPTY;
   }
}

void linearFunction(int loading, string *T)
{
   string temp;
   for (int i = 0; i < loading; i++)
   {
      bool flag = true;
      while (flag == true)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      // cout << "e" << endl;
      insertLinear(temp, T, loading);
   }
}

int main()
{
   cout << "start" << endl;
   string *T;
   int m = 1999;
   T = new string[m];
   clearHash(T);

   // load factors
   const int lightLoad = 400;
   const int medLoad = 1000;
   const int largeLoad = 1600;

   // Linear Probing
   // Load factor 0.2
   cout << "a" << endl;
   linearFunction(lightLoad, T);
   cout << "c" << endl;
   double lightLin = 0;
   bool flag = false;
   string temp;
   for (int i = 0; i < 100; i++)
   {
      while (flag == false)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      lightLin += linearSearchCount(temp, T, lightLoad);
      flag = false;
   }
   lightLin /= 100;

   double lightLinN = 0;
   flag = true;

   for (int i = 0; i < 100; i++)
   {
      while (flag == true)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      lightLinN += linearSearchCount(temp, T, lightLoad);
      flag = true;
   }
   lightLinN /= 100;

   cout << fixed << setprecision(4) << left;
   cout << setw(20) << "0.2 load factor" << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is in T: " << setw(20) << lightLin << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is NOT in T: " << setw(20) << lightLinN << endl;

   // Load factor 0.5
   clearHash(T);
   linearFunction(medLoad, T);
   double medLin = 0;
   flag = false;

   for (int i = 0; i < 100; i++)
   {
      while (flag == false)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      medLin += linearSearchCount(temp, T, medLoad);
      flag = false;
   }
   medLin /= 100;

   double medLinN = 0;
   flag = true;
   for (int i = 0; i < 100; i++)
   {
      while (flag == true)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      medLinN += linearSearchCount(temp, T, medLoad);
      flag = true;
   }
   medLinN /= 100;

   cout << setw(20) << "0.5 load factor" << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is in T" << setw(20) << medLin << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is NOT in T" << setw(20) << medLinN << endl;

   // Load factor 0.8
   double largeLin = 0;
   flag = false;

   for (int i = 0; i < 100; i++)
   {
      clearHash(T);
      linearFunction(largeLoad, T);
      int num = 0;
      for (int i = 0; i < 1000; i++)
      {
         while (flag == false)
         {
            temp = getKey();
            flag = linearSearch(temp, T);
         }
         num += linearSearchCount(temp, T, largeLoad);
         flag = false;
      }
      largeLin += (num / 1000);
   }
   largeLin /= 100;

   double largeLinN = 0;
   flag = true;
   for (int i = 0; i < 100; i++)
   {
      while (flag == true)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      largeLinN += linearSearchCount(temp, T, largeLoad);
      flag = true;
   }
   largeLinN /= 100;

   cout << setw(20) << "0.8 load factor" << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is in T" << setw(20) << largeLin << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is NOT in T" << setw(20) << largeLinN << endl;

   return 0;
}
