// CPSC 2150 Bonus Assignment

#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

#include <string>
using namespace std;

// struct Hash
// {
//     int key;
//     std::string name;
// };

// the hashing function takes a key and the size of the table
// returns the hashed position into the table
int hash_fct(const std::string &key, int tableSize);
string getKey();

#endif

// copyright 2023 Gladys Monagan