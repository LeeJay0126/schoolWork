#include "Employee.h"
#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

template<typename T>
void readFile(T** head_ref, string filename, string header[]);
template<typename T>
void display(T * n, string header[]);
template<typename T>
void pushData(T ** head_ref, Employee data);


int main(){
    
    
    
    Node<Employee> *head = nullptr;
    string header[6];
    
    cout << "head's address : " << &head << endl;
    
    readFile(&head, "Employee_Data.csv", header);
    display(head,header);
    
    return 0;
    
    
}

template<typename T>
void readFile(T** head_ref, string filename, string header[]){
    
    ifstream input;
    input.open(filename);
    string line;
    int pos;
    
    Employee p;
    int count = 0;
    while(getline(input,line)){
        
        if(count == 0){
            
            pos = line.find(",");
            header[0] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[1] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[2] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[3] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[4] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[5] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            count++;
            
        }else{
            
            pos = line.find(",");
            p.setId(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            p.setLastName(line.substr(0,pos));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            p.setFirstName(line.substr(0,pos));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            p.setGender(line.substr(0,pos));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            p.setDepartment(line.substr(0,pos));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            p.setSalary(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pushData(head_ref,p);
        }
        
        input.close();
        
    }
    
}

template<typename T>
void display(T * n, string header[]){
    
    Employee p;
    
    cout << setw(5) << header[0] << setw(15) << header[1] << setw(15) << header[2] << setw(15) << header[3] << setw(15) << header[4] << setw(15) << header[5] << endl;
    
    while(n != nullptr){
        
        p = n->getElement();
        cout << setw(5) << p.getId() << setw(15) << p.getFirstName() << setw(15) << p.getLastName() << setw(15) << p.getGender() << setw(15) << p.getDepartment() << setw(15) << p.getSalary() << endl;
        n = n->next;
        
    }
    
    cout << endl;
    
}

template<typename T>
void pushData(T ** head_ref, Employee data){
    
    T * new_node = new T(data);
    
    new_node->next = (* head_ref);
    ( * head_ref) = new_node;
    
}