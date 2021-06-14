#include <iostream>
#include <string>
#include "CarInfo.h"
#include "Customers.h"
#include <iomanip>
#include "Util.h"
using namespace std;

void displayCars(CarInfo arr[]);
void options(CarInfo arr[], Util util);
void rent(CarInfo arr[], Util util);

const int SIZE = 10;

void displayCars(CarInfo arr);
void options();

int main(){

    CarInfo car;
    Customers customer;
    Util util;
    
    CarInfo array[SIZE];
    util.initialize(SIZE, array);
    util.quickSort(array,SIZE);
    //initializer function works. confirmed
    
    options(array, util);
    
    
    


}

void displayCars(CarInfo arr[]){
    for(int i = 0; i < SIZE; i++){
        cout << left << setw(15) << arr[i].getMake() << setw(10) << arr[i].getYear() << setw(10) << arr[i].getQuantity() << endl;
    }
}

void options(CarInfo arr[], Util util){
    
    int input = 0;
    
    
    while(!(input == 4)){
        cout << "Enter 1 to view available cars, 2 to rent cars, 3 to view all the cars that are rented and 4 to exit " << endl;
        cin >> input;
        if(input == 1){
            displayCars(arr);
        }else if(input == 2){
            rent(arr, util);
        }
        // }else if(input == 3){
            
        // }
    }
}
    
void rent(CarInfo arr[],Util util){
    
    int rentInput = 0;
    string carMake;
    int yearMade;
    int rentNumber;
    string fName;
    string lName;
    string dateRented;
    
    while(!(rentInput == 4)){
                
        cout << "Enter the car make you want to rent: ";
        cin >> carMake;
        cout << "Enter the year of the car : ";
        cin >> yearMade;
        cout << "Enter the quanity of the car you want to rent: ";
        cin >> rentNumber;
        cout << "Enter your first name: ";
        cin >> fName;
        cout << "Enter your last name: ";
        cin >> lName;
        cout << "Enter today's date you are renting the car: ";
        cin >> dateRented;
        
        util.rentCars(arr, carMake, yearMade, rentNumber, SIZE);
        util.getDateRented(fName, lName, carMake, dateRented, yearMade, rentNumber);
        
        cout << "Enter 4 to exit, any other integer to continue rent the car";
        cin >> rentInput;
    }
    
}