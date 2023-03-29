// Name: Jay Lee
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

#include "hash_function.h"

// Referred from CPSC 2150 Class Notes
const string EMPTY = "";

double theoreticalValues(double loading, bool lin, bool search)
{
   double expected;
   if (lin == true)
   {
      if (search == true)
      {
         expected = 0.5 * (1 + (1 / (1 - loading)));
      }
      else
      {
         expected = 0.5 * (1 + (1 / pow(1 - loading, 2)));
      }
   }
   else
   {
      if (search == true)
      {
         expected = 1 - log(1 - loading) - (loading / 2);
      }
      else
      {
         expected = 1 / (1 - loading) - loading - log(1 - loading);
      }
   }
   return expected;
}

double differenceCalc(double x, double y)
{
   double res = x - y;
   if (res < 0)
   {
      res -= 2 * res;
   }

   return res;
}

void insertLinear(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   for (int j = 0; j < 1999; j++)
   {
      if (T[i] == EMPTY)
      {
         T[i] = xPtr;
         return;
      }
      else
      {
         i = ((i + 1) % 1999);
      }
   }
}

void insertQuad(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   for (int j = 1; j <= 1999; j++)
   {
      if (T[i] == EMPTY)
      {
         T[i] = xPtr;
         return;
      }
      else
      {
         i = (i + (j ^ 2)) % 1999;
      }
   }
}

bool linearSearch(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   for (int j = 0; j < 1999; j++)
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

bool quadSearch(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   for (int j = 1; j <= 1999; j++)
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
         i = (i + (j ^ 2)) % 1999;
      }
   }
   return false;
}

int linearSearchCount(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   int result = 0;
   for (int j = 0; j < 1999; j++)
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

int quadSearchCount(string xPtr, string *T)
{
   int i = hash_fct(xPtr, 1999);
   int result = 0;
   for (int j = 1; j <= 1999; j++)
   {
      if (T[i] == xPtr)
      {
         return result + 1;
      }
      else if (T[i] == EMPTY)
      {
         return result + 1;
      }
      i = (i + (j ^ 2)) % 1999;
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
   bool flag;
   for (int i = 0; i < loading; i++)
   {
      flag = true;
      while (flag == true)
      {
         temp = getKey();
         flag = linearSearch(temp, T);
      }
      insertLinear(temp, T);
   }
}

void quadFunction(int loading, string *T)
{
   string temp;
   bool flag;
   for (int i = 0; i < loading; i++)
   {
      flag = true;
      while (flag == true)
      {
         temp = getKey();
         flag = quadSearch(temp, T);
      }
      insertQuad(temp, T);
   }
}

double linearCalculator(string *T, int loading, bool w)
{
   double res = 0;
   bool flag;
   string temp;

   if (w)
   {
      flag = false;
      for (int i = 0; i < 100; i++)
      {
         clearHash(T);
         linearFunction(loading, T);
         while (flag == false)
         {
            temp = getKey();
            flag = linearSearch(temp, T);
         }
         res += linearSearchCount(temp, T);
         flag = false;
      }
      return res / 100;
   }
   else
   {
      flag = true;
      for (int i = 0; i < 100; i++)
      {
         clearHash(T);
         linearFunction(loading, T);
         while (flag == true)
         {
            temp = getKey();
            flag = linearSearch(temp, T);
         }
         res += linearSearchCount(temp, T);
         flag = true;
      }
      return res / 100;
   }
}

double quadCalculator(string *T, int loading, bool w)
{
   double res = 0;
   bool flag;
   string temp;

   if (w)
   {
      flag = false;
      for (int i = 0; i < 100; i++)
      {
         clearHash(T);
         quadFunction(loading, T);
         while (flag == false)
         {
            temp = getKey();
            flag = quadSearch(temp, T);
         }
         res += quadSearchCount(temp, T);
         flag = false;
      }
      return res / 100;
   }
   else
   {
      flag = true;
      for (int i = 0; i < 100; i++)
      {
         clearHash(T);
         quadFunction(loading, T);
         while (flag == true)
         {
            temp = getKey();
            flag = quadSearch(temp, T);
         }
         res += quadSearchCount(temp, T);
         flag = true;
      }
      return res / 100;
   }
}

int main()
{
   // cout << "start" << endl;
   string *T;
   int m = 1999;
   T = new string[m];
   clearHash(T);

   // load factors
   const int lightLoad = 400;
   const int medLoad = 1000;
   const int largeLoad = 1600;

   // Expected Values
   double lightLinE = theoreticalValues(0.2, true, true);
   double lightLinEN = theoreticalValues(0.2, true, false);
   double lightQuadE = theoreticalValues(0.2, false, true);
   double lightQuadEN = theoreticalValues(0.2, false, false);
   double medLinE = theoreticalValues(0.5, true, true);
   double medLinEN = theoreticalValues(0.5, true, false);
   double medQuadE = theoreticalValues(0.5, false, true);
   double medQuadEN = theoreticalValues(0.5, false, false);
   double lLinE = theoreticalValues(0.8, true, true);
   double lLinEN = theoreticalValues(0.8, true, false);
   double lQE = theoreticalValues(0.8, false, true);
   double lQEN = theoreticalValues(0.8, false, false);

   // Linear Probing
   // Load factor 0.2
   // cout << "c" << endl;
   double lightLin = 0;
   lightLin = linearCalculator(T, lightLoad, true);

   double lightLinN = 0;
   lightLinN = linearCalculator(T, lightLoad, false);

   cout << fixed << setprecision(4) << left;
   cout << setw(20) << "0.2 load factor" << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is in T " << setw(20) << lightLin
        << setw(20) << "Expected Value " << setw(20) << lightLinE << setw(20) << "Difference" << setw(10) << differenceCalc(lightLin, lightLinE) << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is NOT in T " << setw(20) << lightLinN
        << setw(20) << "Expected Value " << setw(20) << lightLinEN << setw(20) << "Difference" << setw(10) << differenceCalc(lightLinN, lightLinEN) << endl;

   double lightQuad = 0;
   lightQuad = quadCalculator(T, lightLoad, true);
   double lightQuadN = 0;
   lightQuadN = quadCalculator(T, lightLoad, false);
   cout << setw(20) << "Quadratic" << setw(20) << "When x is in T " << setw(20) << lightQuad
        << setw(20) << "Expected Value " << setw(20) << lightQuadE << setw(20) << "Difference" << setw(10) << differenceCalc(lightQuad, lightQuadE) << endl;
   cout << setw(20) << "Quadratic" << setw(20) << "When x is NOT in T " << setw(20) << lightQuadN
        << setw(20) << "Expected Value " << setw(20) << lightQuadEN << setw(20) << "Difference" << setw(10) << differenceCalc(lightQuad, lightQuadE) << endl;

   // Load factor 0.5
   double medLin = 0;
   medLin = linearCalculator(T, medLoad, true);

   double medLinN = 0;
   medLinN = linearCalculator(T, medLoad, false);

   cout << setw(20) << "0.5 load factor" << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is in T" << setw(20) << medLin
        << setw(20) << "Expected Value " << setw(20) << medLinE << setw(20) << "Difference" << setw(10) << differenceCalc(medLin, medLinE) << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is NOT in T" << setw(20) << medLinN
        << setw(20) << "Expected Value " << setw(20) << medLinEN << setw(20) << "Difference" << setw(10) << differenceCalc(medLinN, medLinEN) << endl;

   double medQuad = 0;
   medQuad = quadCalculator(T, medLoad, true);
   double medQuadN = 0;
   medQuadN = quadCalculator(T, medLoad, false);
   cout << setw(20) << "Quadratic" << setw(20) << "When x is in T " << setw(20) << medQuad
        << setw(20) << "Expected Value " << setw(20) << medQuadE << setw(20) << "Difference" << setw(10) << differenceCalc(medQuad, medQuadE) << endl;
   cout << setw(20) << "Quadratic" << setw(20) << "When x is NOT in T " << setw(20) << medQuadN
        << setw(20) << "Expected Value " << setw(20) << medQuadEN << setw(20) << "Difference" << setw(10) << differenceCalc(medQuadN, medQuadEN) << endl;

   // Load factor 0.8
   double largeLin = 0;
   largeLin = linearCalculator(T, largeLoad, true);

   double largeLinN = 0;
   largeLinN = linearCalculator(T, largeLoad, false);

   cout << setw(20) << "0.8 load factor" << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is in T" << setw(20) << largeLin
        << setw(20) << "Expected Value " << setw(20) << lLinE << setw(20) << "Difference" << setw(10) << differenceCalc(largeLin, lLinE) << endl;
   cout << setw(20) << "Linear" << setw(20) << "When x is NOT in T" << setw(20) << largeLinN
        << setw(20) << "Expected Value " << setw(20) << lLinEN << setw(20) << "Difference" << setw(10) << differenceCalc(largeLinN, lLinEN) << endl;

   double largeQuad = 0;
   largeQuad = quadCalculator(T, largeLoad, true);
   double largeQuadN = 0;
   largeQuadN = quadCalculator(T, largeLoad, false);
   cout << setw(20) << "Quadratic" << setw(20) << "When x is in T " << setw(20) << largeQuad
        << setw(20) << "Expected Value " << setw(20) << lQE << setw(20) << "Difference" << setw(10) << differenceCalc(largeQuad, lQE) << endl;
   cout << setw(20) << "Quadratic" << setw(20) << "When x is NOT in T " << setw(20) << largeQuadN
        << setw(20) << "Expected Value " << setw(20) << lQEN << setw(20) << "Difference" << setw(10) << differenceCalc(largeQuadN, lQEN) << endl;

   return 0;
}
