#ifndef INSERT_H
#define INSERT_H

#include <iostream>

class Insert
{
public:
    // constructor
    Insert();

    // class note for merge list
    void insert(int x);

    void sort();

private:
    struct Node
    {
        int value;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *tail;
};

#endif