#include <iostream>
#include <string>
#include "CarInfo.h"
#include "Customers.h"

const int SIZE = 10;

int main(){

    CarInfo car;

    Cars array[SIZE];
    car.initialize(SIZE, array);

    for(int i = 0; i < SIZE; i++){
        cout << array[i].make << array[i].year << array[i].available;
    }


}

