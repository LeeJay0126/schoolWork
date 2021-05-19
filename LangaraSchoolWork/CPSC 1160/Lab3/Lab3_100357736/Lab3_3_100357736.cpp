#include <iostream>
using namespace std;
void printStars(int);

int main(){
    cout << "Enter the number of asterisks you want: ";
    int input;
    cin >> input;

    printStars(input);

    return 0;
}

void printStars(int input){
    if(input > 0){
        cout << "*";
        printStars(input-1);
    }
}