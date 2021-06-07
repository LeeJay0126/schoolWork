// filename: TestMain2.cpp

#include "SortLib.h"
#include <iostream>
using namespace std;



int main()
{
  SortUtil su;
  
  const int SIZE = 9;
  int list[] = {1, 7, 3, 4, 9, 3, 3, 1, 2};
  su.quickSort(list, SIZE);
  
  for (int i = 0; i < SIZE; i++)
    cout << list[i] << " ";

  return 0;
}  
