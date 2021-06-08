#ifndef AS4_H
#define AS4_H

#include "MyStruct.h"

class CarInfo {
    
    public: 
        
        void quickSort(Cars list[], int arraySize);
        int partition(Cars list[], int first, int last);
        void rentCars(Cars list[], string make, int year, int rentNumber, int size);
        void initialize(int size, Cars arr[]);
        
        
    private:
        // this function is only used by quickSort(int list[], int arraySize)
        
        
        void quickSort(Cars list[], int first, int last);
} ;

#endif