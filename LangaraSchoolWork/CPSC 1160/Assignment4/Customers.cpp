#include <iostream>
#include "Customers.h"
#include <string>
#include <fstream>
using namespace std;

void Customers::quickSort(Customers list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void Customers::quickSort(Customers list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

int Customers::partition(Customers list[], int first, int last)
{
  string pivot = list[first].carMake; // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].carMake <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].carMake > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      string temp = list[high].carMake;
      list[high].carMake = list[low].carMake;
      list[low].carMake = temp;

      int tempYear = list[high].carYear;
      list[high].carYear = list[low].carYear;
      list[low].carYear = tempYear;

      int tempQuantity = list[high].quantity;
      list[high].quantity = list[low].quantity;
      list[low].quantity = quantity;

      string dateRented = list[high].dateRented;
      list[high].dateRented = list[low].dateRented;
      list[low].dateRented = dateRented;
      
      string firstName = list[high].firstName;
      list[high].firstName = list[low].firstName;
      list[low].firstName = firstName;

      string lastName = list[high].lastName;
      list[high].lastName = list[low].lastName;
      list[low].lastName = lastName;

      string dateRented = list[high].dateRented;
      list[high].dateRented = list[low].dateRented;
      list[low].dateRented = dateRented;


    }
  }

  while (high > first && list[high].carMake >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].carMake)
  {
    list[first].carMake = list[high].carMake;
    list[high].carMake = pivot;
    return high;
  }
  else
  {
    return first;
  }
}
