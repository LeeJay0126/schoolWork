#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee{
    public:
        
        Employee();
        
        int getId() const;
        int getSalary() const;
        string getFirstName() const;
        string getLastName() const;
        string getGender() const;
        string getDepartment() const;
        
        void setId(int id);
        void setSalary(int salary);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setGender(string gender);
        void setDepartment(string department);
        
        
        
    private:
        int id;
        int salary;
        string firstName;
        string lastName;
        string gender;
        string department;
};
#endif