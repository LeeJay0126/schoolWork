#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <string>
using namespace std;

class Customers{

  private:
    void quickSort(Customers list[], int first, int last);
    string firstName;
    string lastName;
    string carMake;
    int carYear;
    int quantity = 1;
    string dateRented;


  public:
    void sortByMake(Customers arr[], int size);
    void quickSort(Customers list[], int arraySize);
    int partition(Customers list[], int first, int last);
    void setFirstName(string f){
      firstName = f;
    }
    string getFirstName(){
      return firstName;
    }
    void getLastName(string LastName){
      lastName = LastName;
    }
    string getLastName(){
      return lastName;
    }
    void setCarMake(string CarMaker){
      carMake = CarMaker;
    }
    string getCarMake(){
      return carMake;
    }
    void setCarYear(int CarYears){
      carYear = CarYears;
    }
    int getCarYear(){
      return carYear;
    }
    void setQuantity(int Quantity){
      quantity = Quantity;
    }
    int getQuantity(){
      return quantity;
    }
    void setDate(string Date){
      dateRented = Date;
    }
    string getDate(){
      return dateRented;
    }

    
};

#endif


