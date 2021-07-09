#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

class Node {

    public: 
        Node *next;
        
        Node() {
            next = nullptr;
        }
        
        Node(? element) {
            this->element = element;
            next = nullptr;
        }
        
        string getElement() const {
            return element;
        }
    
    private:
        ? element;
};

#endif
