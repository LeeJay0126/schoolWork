#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int SIZE =  10 ;

struct Employee {
    int id;
    string firstname;
    string lastname;
}; 

void readData(Employee []) ;
void display(const Employee[]);

int main()
{
    Employee emp[SIZE] ;
    readData(emp);
    display(emp);
    
    return 0;
}


void readData(Employee e[]) 
{
    ifstream input;
    string line;
    int pos;
    int index = 0 ;
    
    // Open a file
    input.open("MOCK_DATA.csv");
    while (getline(input,line)) {  // read per line
        cout << line << endl; // not required, this is for demo purpose only
        pos = line.find(",") ; 
        
        e[index].id = stoi (line.substr(0,pos));
        line.erase(0,pos+1) ; // remove the id including the , after the id
  
        pos = line.find(",") ; 
        e[index].firstname = line.substr(0,pos);
        
        e[index].lastname = line.substr(pos+1);
       
        index++ ;
        
    }

    input.close();
}

void display(const Employee e[]) {
    for (int i=0 ; i < SIZE ; i++) {
        cout << e[i].id << " : " << e[i].lastname << ", " << e[i].firstname << endl; 
    }
}