#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void patterPrinter(int);

int main(){

    int integer = 3;

    patterPrinter(3);

}

void patterPrinter(int column){

    for(int i = 0; i < column; i++){
        for(int j = 0; j <= i; j++){
            if(i == j){
                cout << j+1;
            }else{
                cout << "*" ;
            }
        }
        cout << endl;
    }

    for(int i = column-2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(i == j){
                cout << j+1;
            }else{
                cout << "*" ;
            }
        }
        cout << endl;
    }

}