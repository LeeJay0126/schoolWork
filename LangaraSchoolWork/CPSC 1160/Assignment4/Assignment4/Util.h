#ifndef UTIL_H
#define UTIL_H

#include "CarInfo.h"
#include "Customers.h"
#include <iostream>
#include <string>
using namespace std;

class Util{
private:
    void quickSort(Customers list[], int first, int last);
    string firstName;
    string lastName;
    string carMake;
    int carYear;
    int quantity = 1;
    string dateRented;
    void quickSort(CarInfo list[], int first, int last);
    
public:
    void quickSort(CarInfo list[], int arraySize);
    int partition(CarInfo list[], int first, int last);
    void rentCars(CarInfo list[], string make, int year, int rentNumber, int size);
    void initialize(int size, CarInfo arr[]);    
    void sortByMake(Customers arr[], int size);
    void quickSort(Customers list[], int arraySize);
    int partition(Customers list[], int first, int last);
    string getDateRented(string firstName, string lastName, string carMake, string dateRented, int carYear, int quantity);
    
};
    #endif