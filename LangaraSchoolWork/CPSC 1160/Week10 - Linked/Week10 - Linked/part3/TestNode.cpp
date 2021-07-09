#include "Node.h"
#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;

void display (Node *, string[]);
void pushData (Node **, Person data);
void readFile(Node**,string filename , string header[]) ;

int main() {
    
    Node *head = nullptr ;
    string header[2];
    
    cout << "head's address : " << &head << endl;
    
    readFile(&head,"car_data.csv", header);
    display(head,header);
    
    cout << "head's address after push: " << &head << endl;
   
    return 0;
}

void readFile(Node** head_ref,string filename, string header[])  {
    ifstream input;
    input.open(filename);
    string line;
    int pos;
    
    
    // get header
    getline(input,line);
    pos = line.find(",");
    header[0] = line.substr(0,pos);
    header[1] = line.substr(pos+1);
    
    // get data
    Person p;
    while(getline(input,line)) {
        pos = line.find(",");    
        p.name = line.substr(0,pos);
        p.car = line.substr(pos+1);
        pushData(head_ref,p);
    }
    
    // this is just for demo
    cout << " -- " << (**head_ref).getElement().name << endl;
    cout << " -- " << (*head_ref)->getElement().name << endl;
    
    input.close();
    
}

void display (Node * n, string header[]) {
    cout << "\nPrinting the data..." << endl;
    Person p;
    
    cout << setw(20) << header[0] << setw(15) << header[1] << endl;
    while (n != nullptr) {
        p = n->getElement();
        cout << setw(20) << p.name << setw(15) << p.car << endl;;
        n = n->next;
    }
    cout << endl;
} 

void pushData(Node ** head_ref, Person data) {
  
    //create a new node with the new element
    Node * new_node = new Node(data);
    
    new_node->next = ( * head_ref);
    ( * head_ref) = new_node;
    
} 