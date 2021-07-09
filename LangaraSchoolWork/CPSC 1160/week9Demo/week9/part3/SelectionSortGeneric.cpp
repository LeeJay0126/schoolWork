#include "SelectionSortGeneric.h"

template<typename T>
void SortGeneric<T>::sort(T list[], int listSize) 
{
  for (int i = 0; i < listSize; i++) 
  {
    // Find the minimum in the list[i..listSize-1]
    T currentMin = list[i];
    int currentMinIndex = i;

    for (int j = i + 1; j < listSize; j++) 
    {
      if (currentMin > list[j]) 
      {
        currentMin = list[j];
        currentMinIndex = j;
      }
    }

    // Swap list[i] with list[currentMinIndex] if necessary;
    if (currentMinIndex != i) 
    {
      list[currentMinIndex] = list[i];
      list[i] = currentMin;
    }
  }
}

