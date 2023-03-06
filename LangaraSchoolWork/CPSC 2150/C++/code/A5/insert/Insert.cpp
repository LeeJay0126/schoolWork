#include "Insert.h"
#include <iostream>
#include <chrono>

Insert::Insert()
{
    head = nullptr;
}

void Insert::insert(int x)
{

    if (head == nullptr)
    {
        head = new Node();
        head->value = x;
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
    }
    else
    {
        Node *newNode = new Node();
        newNode->value = x;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    if (head != tail)
    {
        sort();
    }
}

void Insert::sort()
{
    Node *temp;
    temp = tail;
    int tailValue = tail->value;
    Node *previous;
    previous = tail->prev;

    while (temp->value >= previous->value)
    {
        Node *t;
        t = previous->prev;
        if (temp->next == nullptr)
        {
            t->next = temp;
            temp->prev = t;
            temp->next = previous;
            previous->prev = temp;
            previous->next = nullptr;
            tail = previous;
        }
        else
        {
            t->next = temp;
            temp->prev = t;
            temp->next = previous;
            previous->prev = temp;
            previous->next = nullptr;
            previous = t;
        }
    }
}