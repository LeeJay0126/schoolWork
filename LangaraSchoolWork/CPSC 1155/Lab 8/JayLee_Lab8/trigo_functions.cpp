//-------------------------------------------------------------
// Lab 8 Loops
// CPP program for CPSC 1155 Lab 8 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){

    int degree;
    double sine, cosine;

    cout << left << setw(10) << "Degree "<<  left << setw(10) << "Sin" <<  left << setw(10) << "Cos" <<endl;
    for(int i=0;i<=360;i+=10){
        degree = i;
        sine = sin((degree*M_PI)/180);
        cosine = cos((degree*M_PI)/180);

        cout << left << setw(10) << degree <<  left << setw(10)<< fixed << setprecision(4) << sine <<  left << setw(10)<< fixed << setprecision(4) << cosine<<endl;
        
    }


}