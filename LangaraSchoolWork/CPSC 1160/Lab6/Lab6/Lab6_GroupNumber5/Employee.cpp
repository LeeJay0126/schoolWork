#include "Employee.h"
#include <string>
using namespace std;

int Employee::getId() const{
    return id;
}

int Employee::getSalary() const{
    return salary;
}

string Employee::getFirstName() const{
    return firstName;
}

string Employee::getLastName() const{
    return lastName;
}

string Employee::getGender() const{
    return gender;
}

string Employee::getDepartment() const{
    return department;
}

void Employee::setId(int id){
    this->id = id;
}

void Employee::setSalary(int salary){
    this->salary = salary;
}

void Employee::setFirstName(string firstName){
    this->firstName = firstName;
}

void Employee::setLastName(string lastName){
    this->lastName = lastName;
}

void Employee::setGender(string gender){
    this->gender = gender;
}

void Employee::setDepartment(string department){
    this->department = department;
}