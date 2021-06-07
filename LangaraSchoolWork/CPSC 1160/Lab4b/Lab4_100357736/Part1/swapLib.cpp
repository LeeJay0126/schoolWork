#include "swapLib.h"
#include <string>
using namespace std;

void SwapUtil::swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void SwapUtil::swap(string *a, string *b){

    string temp = *a;
    *a = *b;
    *b = temp;
    
}

void SwapUtil::swap(double *a, double *b){

    double temp = *a;
    *a = *b;
    *b = temp;
    
}