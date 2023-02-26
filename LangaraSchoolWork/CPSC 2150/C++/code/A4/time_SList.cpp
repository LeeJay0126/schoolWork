// Name: Jay Seung Yeon Lee
// Student Number: 100357736

#include <iostream>
#include <string>
#include <cmath> // sqrt
#include <cstdlib>
#include <ctime>   // time
#include <iomanip> // setw

#include "SList.h"

int main()
{

   SList list;
   list.insert(5);
   std::cout << list;
   list.insert(7);
   std::cout << list;
   list.reset();
   std::cout << list;
   std::cout << "a";

   return 0;
}
