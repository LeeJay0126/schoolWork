// CPSC 2150 Bonus Assignment

#include "hash_function.h"
#include <ctime>
#include <string>

using namespace std;

// the hashing function takes a key k and the size of the table m
int hash_fct(const std::string &k, int m)
{
   int s = 0;
   for (size_t i = 0; i < k.length(); i++)
   {
      s = (2167 * s + k[i]) % m; // prevent overflow
   }
   return s;
}

string getKey()
{
   char a = 65 + rand() % 26;
   char b = 65 + rand() % 26;
   char c = 65 + rand() % 26;
   char d = 65 + rand() % 26;
   char e = 65 + rand() % 26;
   char f = 65 + rand() % 26;
   char g = 65 + rand() % 26;

   return "" + a + b + c + d + e + f + g;
}

// copyright 2023 Gladys Monagan
