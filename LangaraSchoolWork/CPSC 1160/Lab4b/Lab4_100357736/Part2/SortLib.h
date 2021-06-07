// filename: SortLib.h

#ifndef SORTLIB_H
#define SORTLIB_H

class SortUtil {
    
    public: 
        void quickSort(int list[], int arraySize);
        int partition(int list[], int first, int last);
        
    private:
        // this function is only used by quickSort(int list[], int arraySize)
        void quickSort(int list[], int first, int last);
} ;


#endif
