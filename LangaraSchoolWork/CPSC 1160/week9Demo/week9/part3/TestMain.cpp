#include <iostream>
#include <string>
#include "SelectionSortGeneric.h"
#include "SelectionSortGeneric.cpp"
using namespace std;

template<typename T>
void printArray(const T list[], int listSize);

int main()
{
  SortGeneric <int>sg;
  
  int list1[] = {3, 5, 1, 0, 2, 8, 7};
  sg.sort(list1, 7);
  printArray(list1, 7);

  SortGeneric<double> *sg2 = new SortGeneric<double>();
  double list2[] = {3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7};
  sg2->sort(list2, 7);
  printArray(list2, 7);

  SortGeneric<string> *sg3 = new SortGeneric<string>();
  string list3[] = {"Atlanta", "Denver", "Chicago", "Dallas"};
  (*sg3).sort(list3, 4);
  printArray(list3, 4);

  delete sg2;
  delete sg3;
  return 0;
}

template<typename T>
void printArray(const T list[], int listSize)
{
  for (int i = 0; i < listSize; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}