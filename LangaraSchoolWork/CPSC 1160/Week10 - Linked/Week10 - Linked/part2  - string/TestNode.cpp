// fix the code and make it run


#include "Node.h"
#include <iostream>
using namespace std;

void display (Node *);
void pushData (Node **, ? element);

int main() {
    string words[] = {"Vivianna","Averell","Luke","Cyrillus","Camella","Benn"} ;
    string additionalWords[] = {"Jess","Odessa","Brennan","Pamela"} ;
    
    Node *head = nullptr ;
    Node *tail = nullptr ;
    
    Node *temp;
    int val;
    for (int x = 0 ; x < sizeof(words)/sizeof(string); x++ ){
        temp = new Node(words[x]);
        
        if (head == nullptr) {
            head = temp;
            tail = head;
        } else {
            tail->next = temp;
            tail = temp;
        }
            
    }
    
    cout << endl;
    
    display(head); // there should be 6 names
    
    
    // going to add a new data at the beginning
    for (int x = 0 ; x < sizeof(additionalWords)/sizeof(string); x++ )
        pushData(&head, additionalWords[x]); 
    
    
    display(head); // should give you 10 names
    
    return 0;
}


void display (Node * n) {
    cout << "\nPrinting the data..." << endl;
    while (n != nullptr) {
        cout << n->getElement() << " ";
        n = n->next;
    }
    cout << endl;
} 

void pushData(Node ** head_ref,? new_element) {
   
    //create a new node with the new element
    Node * new_node = ?;
    
    new_node->next = ( * head_ref);
    ( * head_ref) = new_node;
    
} 