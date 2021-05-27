#include <iostream>
using namespace std;

int numberOfPins(int rows);

int main(){
    cout << "How many rows of bowling pins will there be? : ";
    int rows;
    cin >> rows;
    
    cout << "You will need to set up " << numberOfPins(rows) << " bowling pins. ";
    
}

int numberOfPins(int rows){
    if(rows > 0){
        return rows+numberOfPins(rows - 1);
    }
}