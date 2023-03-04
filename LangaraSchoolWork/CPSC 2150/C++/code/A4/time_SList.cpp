// Name: Jay Seung Yeon Lee
// Student Number: 100357736

#include <iostream>
#include <string>
#include <cmath> // sqrt
#include <cstdlib>
#include <ctime>   // time
#include <iomanip> // setw

#include "SList.h"

void insert(SList list, int x, bool code, int arr[])
{
   if (code)
   {
      for (int i = 0; i < x; i++)
      {
         arr[i] = i;
         list.insert(arr[i]);
      }
   }
   else
   {
      for (int i = x; i > 0; i--)
      {
         arr[i] = i;
         list.insert(arr[i]);
      }
   }
}

void randomInsert(SList list, int x, int arr[])
{
   for (int i = 0; i < x; i++)
   {
      arr[i] = rand();
      list.insert(arr[i]);
   }
}

clock_t calculate(SList list, int x, int arr[])
{
   clock_t t;
   t = clock();

   for (int i = 0; i < 100; i++)
   {
      for (int j = 0; j < x; j++)
      {
         list.search(arr[j]);
      }
   }

   t = clock() - t;
   t = t / x;

   return t;
}

int main()
{
   // initializing lists
   SList ascendingList;
   SList ascendingList2;
   SList ascendingList3;
   SList ascendingList4;

   SList descendingList;
   SList descendingList2;
   SList descendingList3;
   SList descendingList4;

   SList randomList;
   SList randomList2;
   SList randomList3;
   SList randomList4;

   int asc[2000];
   int asc2[2000];
   int asc3[2000];
   int asc4[2000];

   int descendingArray[2000];
   int descendingArray2[2000];
   int descendingArray3[2000];
   int descendingArray4[2000];

   int randomArray[2000];
   int randomArray2[2000];
   int randomArray3[2000];
   int randomArray4[2000];

   insert(ascendingList, 100, true, asc);
   insert(ascendingList2, 500, true, asc2);
   insert(ascendingList3, 1000, true, asc3);
   insert(ascendingList4, 2000, true, asc4);

   std::cout << "a" << std::endl;

   clock_t ascArr = calculate(ascendingList, 1000, asc);
   clock_t ascArr2 = calculate(ascendingList2, 1000, asc2);
   clock_t ascArr3 = calculate(ascendingList3, 1000, asc3);
   clock_t ascArr4 = calculate(ascendingList4, 1000, asc4);

   insert(ascendingList, 100, false, descendingArray);
   insert(ascendingList2, 500, false, descendingArray2);
   insert(ascendingList3, 1000, false, descendingArray3);
   insert(ascendingList4, 2000, false, descendingArray4);

   clock_t dscArr = calculate(descendingList, 1000, descendingArray);
   clock_t dscArr2 = calculate(descendingList2, 1000, descendingArray2);
   clock_t dscArr3 = calculate(descendingList3, 1000, descendingArray3);
   clock_t dscArr4 = calculate(descendingList4, 1000, descendingArray4);

   randomInsert(ascendingList, 100, randomArray);
   randomInsert(ascendingList2, 500, randomArray2);
   randomInsert(ascendingList3, 1000, randomArray3);
   randomInsert(ascendingList4, 2000, randomArray4);

   clock_t randArr = calculate(randomList, 1000, randomArray);
   clock_t randArr2 = calculate(randomList2, 1000, randomArray2);
   clock_t randArr3 = calculate(randomList3, 1000, randomArray3);
   clock_t randArr4 = calculate(randomList4, 1000, randomArray4);

   std::cout << std::setw(15) << "Type of list" << std::setw(10) << "100 times" << std::setw(10) << "500 times" << std::setw(10) << "1000 times" << std::setw(10) << "2000 times" << std::endl;
   std::cout << std::setw(15) << "Ascending List" << std::setw(10) << ascArr << std::setw(10) << ascArr2 << std::setw(10) << ascArr3 << std::setw(10) << ascArr4 << std::endl;
   std::cout << std::setw(15) << "Descending List" << std::setw(10) << dscArr << std::setw(10) << dscArr2 << std::setw(10) << dscArr3 << std::setw(10) << dscArr4 << std::endl;
   std::cout << std::setw(15) << "Random List" << std::setw(10) << randArr << std::setw(10) << randArr2 << std::setw(10) << randArr3 << std::setw(10) << randArr4 << std::endl;

   return 0;
}
