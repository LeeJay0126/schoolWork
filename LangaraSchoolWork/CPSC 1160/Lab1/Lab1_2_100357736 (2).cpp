#include <iostream>
using namespace std;

int main(){
    
    int valid = 0;
    int input = 0;

    while(valid == 0){
        cout << "Enter an even number or 999 to stop : ";
        cin >> input;
        if(input == 999){
            cout << "You have entered 999. Program will now exit. ";
            valid = 1;
        }else if(input % 2 == 0){
            cout << "Good job!" << endl;
        }else{
            cout << "Error! Please enter an ever number: " << endl;
        }
    }
}