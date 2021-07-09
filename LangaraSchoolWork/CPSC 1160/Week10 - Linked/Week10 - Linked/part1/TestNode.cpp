#include "Node.h"
#include <iostream>
using namespace std;

void display (Node *);
void pushData (Node **, int element);

int main() {
    srand(time(0));
    Node *head = nullptr ;
    Node *tail = nullptr ;
    
    Node *temp;
    int val;
    for (int x = 0 ; x < 4; x++ ){
        val = rand()%100;
        temp = new Node(val);
        
        if (head == nullptr) {
            head = temp;
            tail = head;
        } else {
            tail->next = temp;
            tail = temp;
        }
            
        cout << val << " " ;
    }
    
    cout << endl;
    
    display(head);
    
    
    cout << "head is pointing at address : " << head << endl;
    cout << "head's address is at : " << &head << endl;
    
    // going to add a new data at the beginning
    pushData(&head, rand()%100); 
    
    
    cout << "After the pushData" << endl;
    cout << "head is pointing at address : " << head << endl;
    cout << "head's address is at : " << &head << endl;
    
    display(head);
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

void pushData(Node ** head_ref, int new_element) {
    cout << "Inside pushData" << endl;
    cout << "head_ref is pointing at address : " << *head_ref << endl;
    cout << "head_ref's address is at : " << &head_ref << endl;
    
    //create a new node with the new element
    Node * new_node = new Node(new_element);
    
    new_node->next = ( * head_ref);
    ( * head_ref) = new_node;
    
    cout << "new_node is pointing at  : " << new_node << endl;
} 