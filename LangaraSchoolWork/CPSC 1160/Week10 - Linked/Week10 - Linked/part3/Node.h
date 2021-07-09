#ifndef NODE_H
#define NODE_H
#include <string>
#include "Person.h"
using namespace std;

class Node {

    public: 
        Node *next;
        
        Node() {
            next = nullptr;
        }
        
        Node(Person p) {
            this->p = p;
            next = nullptr;
        }
        
        Person getElement() const {
            return p;
        }
    
    private:
        Person p;
        
};

#endif
