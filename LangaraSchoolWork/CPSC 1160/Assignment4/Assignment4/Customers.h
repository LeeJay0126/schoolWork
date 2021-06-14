#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <string>
#include <iostream>
using namespace std;


class Customers{

  private:

    string firstName;
    string lastName;
    string carMake;
    int carYear;
    int quantity = 1;
    string dateRented;


  public:
    void setFirstName(string f);
    string getFirstName();
    void getLastName(string LastName);
    string getLastName();
    void setCarMake(string CarMaker);
    string getCarMake();
    void setCarYear(int CarYears);
    int getCarYear();
    void setQuantity(int Quantity);
    int getQuantity();
    void setDate(string Date);
    string getDate();
    
    Customers(string firstname,string lastname,string carMake, int carYear, int quantity, string dateRented);
    Customers();

    
};

#endif


