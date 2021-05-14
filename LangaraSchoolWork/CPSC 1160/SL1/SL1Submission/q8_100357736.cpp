#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void getData(employee emp, int arraySize);

struct employee{
    int id;
    string name;
    string role;
    int age;
}emp1, emp2, emp3, emp4, emp5;

int main(){
    
    getData(emp1, 4);
    getData(emp2,4);
    getData(emp3,4);
    getData(emp4,4);
    getData(emp5,4);
    
    cout << left << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Role" << setw(10) << "age" << endl;
    cout << left << setw(10) << emp1.id << setw(10) << emp1.name << setw(10) << emp1.role << setw(10) <<  emp1.age << endl;
    cout << left << setw(10) << emp2.id << setw(10) << emp2.name << setw(10) << emp2.role << setw(10) <<  emp2.age << endl;
    cout << left << setw(10) << emp3.id << setw(10) << emp3.name << setw(10) << emp3.role << setw(10) <<  emp3.age << endl;
    cout << left << setw(10) << emp4.id << setw(10) << emp4.name << setw(10) << emp4.role << setw(10) <<  emp4.age << endl;
    cout << left << setw(10) << emp5.id << setw(10) << emp5.name << setw(10) << emp5.role << setw(10) <<  emp5.age << endl;
    
}

void getData(employee emp, int arraySize){
    
    employee emp = string [arraySize];
    
    cout << "What is your employee's name? : ";
    getline(cin, emp.name, '\n');
    cout << "What is your employee's age? : ";
    cin >> emp.age;
    cout << "What is your employee's role? : ";
    cin >> emp.role;
    cout << "What is your employee's ID? : ";
    cin >> emp.id;
}