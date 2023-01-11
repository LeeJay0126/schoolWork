/* 
 * ad hoc testing that does not depend on google test
   values are read from standard input
   Name:
 */ 

#include <iostream>
#include <string>
#include "lfcts.h"

using std::cin, std::cout, std::endl, std::string;

// get values from standard input
// report discrepancies as error
// continue until the user wants to stop
int main() {
   char ch;
   do {
      string str;
      cout << "Enter string to convert: ";
      cin >> str;

      cout << "continue? (y/Y) ";
      cin >> ch;
   } while ((ch =='y') || (ch == 'Y'));
   return 0;
}

// copyright 2023 Gladys Monagan 
