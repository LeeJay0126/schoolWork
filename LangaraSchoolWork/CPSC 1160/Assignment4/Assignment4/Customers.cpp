#include <iostream>
#include "Customers.h"
#include <string>
#include <fstream>
using namespace std;

 void Customers::setFirstName(string f){
      firstName = f;
  }
  string Customers::getFirstName(){
    return firstName;
  }
  void Customers::getLastName(string LastName){
    lastName = LastName;
  }
  string Customers::getLastName(){
    return lastName;
  }
  void Customers::setCarMake(string CarMaker){
    carMake = CarMaker;
  }
  string Customers::getCarMake(){
    return carMake;
  }
  void Customers::setCarYear(int CarYears){
    carYear = CarYears;
  }
  int Customers::getCarYear(){
    return carYear;
  }
  void Customers::setQuantity(int Quantity){
    quantity = Quantity;
  }
  int Customers::getQuantity(){
    return quantity;
  }
  void Customers::setDate(string Date){
    dateRented = dateRented;
  }
  string Customers::getDate(){
    return dateRented;
  }




// void rentCar(string firstName, string lastName, string carMake, string dateRented, int carYear, int quantity){
    
//     ofstream input;
//     string line;
    
//     line = firstName +"," + lastName + "," + carMake + "," + carYear + "," + quantity + "," + dateRented;
    
//     input.open("customers.csv");
    
//     input << line;
    
//     ofstream.close();
    
    
    
// }

// int countForArray(){
  
//   ifstream input;
//   string line;
//   int count;
  
//   input.open("customers.csv");
  
//   while(getline(input,line)){
    
//     count++;
    
//   }
  
//   return count;
// }

// void 