#ifndef AS4_H
#define AS4_H
#include <iostream>
#include <string>

using namespace std;


class CarInfo {
    
    public: 

        CarInfo(int year, int quantity, string make);
        CarInfo();
        void setMake(string make);
        void setYear(int year);
        void setQuantity(int quantity);
        string getMake();
        int getYear();
        int getQuantity();
        
    private:
        // this function is only used by quickSort(int list[], int arraySize)
        
        int quantity;
        int year;
        string make;

} ;

#endif