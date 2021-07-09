#ifndef NODE_H
#define NODE_H


class Node {

    public: 
        Node *next;
        
        Node() {
            next = nullptr;
        }
        
        Node(int element) {
            this->element = element;
            next = nullptr;
        }
        
        int getElement() const {
            return element;
        }
    
    private:
        int element;
};

#endif
