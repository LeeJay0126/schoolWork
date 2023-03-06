#include "Insert.h"
#include <iostream>
#include <chrono>

Insert::Insert()
{
    head = nullptr;
}

void Insert::insert(int x)
{
    // std::cout << x << std::endl;
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

    // test
    Node *test;
    test = head;
    while (test != nullptr)
    {
        std::cout << test->value;
        test = test->next;
    }
    std::cout << std::endl;

    if (temp->value <= head->value)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {

        while (temp->value > previous->value)
        {
            Node *t;
            if(previous == head){
                break;
            }
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
}