#ifndef AS4_H
#define AS4_H

#include "MyStruct.h"

class SortCars {
    
    public: 
        
        char quickSort(Cars list[], int arraySize);
        int partition(Cars list[], int first, int last);
        void rentCars(Cars list[], string make, int year, int rentNumber);
        void initialize(Cars list[], int size);
        
    private:
        // this function is only used by quickSort(int list[], int arraySize)
        
        
        void quickSort(Cars list[], int first, int last);
} ;

#endif