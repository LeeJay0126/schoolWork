#include <iostream>
#include <string>
#include "Food.h"
#include "util.h"
#include <iomanip>

using namespace std;

int main(){
    
    int count = 0;
    
    Util util;
    
    Food * foods_100357736 = new Food[count];
    foods_100357736 = util.initialize(foods_100357736, &count);

    int lowest = util.lowestCal(foods_100357736, count);
    int numberOfLow = util.numberOfLowestCal(foods_100357736,count,lowest);
    Food * lowestCalArr = new Food[numberOfLow];
    string meal;
    int maxCal;
    
    int input = 0;
    while(!(input == 4)){
        cout << "Enter your options: 1 for display all, 2 for displaying low, 3 for meal plan and 4 to exit: ";
        cin >> input;
        switch(input){
            case 1:
               util.displayAll(foods_100357736, count);
                break;
            case 2:
                util.displayLow(lowestCalArr, numberOfLow);
                break;
            case 3:
                cout << "Enter Your meal ";
                cin >> meal;
                cout << "Enter max calory: "; 
                cin >> maxCal;
                break;
            case 4:
                cout << "You either chose to exit or entered invalid input" << endl;
                break;
        }
    }
    
}