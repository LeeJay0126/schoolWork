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
   int random = 3 + rand() % 15;
   string res;
   char randChar;

   for (int i = 0; i < random; i++)
   {
      randChar = 'A' + rand() % 26;
      res += randChar;
   }

   // + h + i + j + k + l + m
   return res;
}

// copyright 2023 Gladys Monagan
