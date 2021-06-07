#include "SortLib.h"
#include <iostream>
#include "MyStruct.h"
#include <string>

void SortUtil::quickSort(int list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void SortUtil::quickSort(int list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

void SortUtil::quickSort(MyData list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void SortUtil::quickSort(MyData list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

// Partition the array list[first..last] 
int SortUtil::partition(int list[], int first, int last)
{
  int pivot = list[first]; // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low] <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high] > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      int temp = list[high];
      list[high] = list[low];
      list[low] = temp;
    }
  }

  while (high > first && list[high] >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high])
  {
    list[first] = list[high];
    list[high] = pivot;
    return high;
  }
  else
  {
    return first;
  }
}

int SortUtil::partition(MyData list[], int first, int last)
{
  string pivot = list[first].codeName; // Choose the first element as the pivot
  int intPivot = list[first].id;
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].codeName <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].codeName > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      string temp = list[high].codeName;
      list[high].codeName = list[low].codeName;
      list[low].codeName = temp;
      
      int intTemp = list[high].id;
      list[high].id = list[low].id;
      list[low].id = intTemp;
    }
  }

  while (high > first && list[high].codeName >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].codeName)
  {
    list[first].codeName = list[high].codeName;
    list[high].codeName = pivot;
    
    list[first].id = list[high].id;
    list[high].id = intPivot;
    
    return high;
  }
  else
  {
    return first;
  }
}

