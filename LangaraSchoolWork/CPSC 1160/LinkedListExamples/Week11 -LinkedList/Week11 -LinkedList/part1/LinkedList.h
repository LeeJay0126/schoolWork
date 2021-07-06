#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void addFirst(int e);
        int getSize() const;
        void clear();
        int get(int index) const;
        
        
        int getFirst() const;
        int removeFirst();
    
        void add(int index, Node) ;
        // for you to implement
        /*
        bool contains(int element) const; // returns true if it contains the eleement
        void addLast(int element ); // adds the element to the tail
        int getLast() const; // returns the last element in the list
        int removeLast(); // removes the last element and returns it's value
        bool isEmpty();
        int set(int index, int element); // sets the elemenet at specified index and returns the value being replaced
        */
    private:
        Node * head;
        Node * tail;
        int size;
        
};

#endif