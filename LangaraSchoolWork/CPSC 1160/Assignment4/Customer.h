#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

struct Customer 
{
    string firstName;
    string lastName;
    string carMake;
    int carYear;
    int quantity = 1;
    string dateRented;
} ; 


#endif
