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
   std::cout << " inserted" << std::endl;
   list.insert(3);
   std::cout << " inserted" << std::endl;
   list.insert(2);
   std::cout << " inserted" << std::endl;
   list.insert(2);
   std::cout << " inserted" << std::endl;
   list.insert(3);
   std::cout << " inserted" << std::endl;
   // std::cout << list <<std::endl;
   // list.reset();
   list.insert(7);
   std::cout << " inserted" << std::endl;
   list.insert(8);
   std::cout << " inserted" << std::endl;
   list.insert(9);
   std::cout << " inserted" << std::endl;
   list.insert(5);
   std::cout << " inserted" << std::endl;
   list.insert(7);
   std::cout << " inserted" << std::endl;
   list.insert(7);
   list.insert(7);
   // list.insert(7);
   // list.insert(7);
   // list.insert(8);
   // list.insert(8);
   // list.insert(8);
   // list.insert(8);
   // list.insert(8);
   // list.insert(8);
   // list.insert(12);
   std::cout << list <<std::endl;

   list.setTopListOutput(true);
   std::cout << list << std::endl;

   std::cout << "a";

   return 0;
}
