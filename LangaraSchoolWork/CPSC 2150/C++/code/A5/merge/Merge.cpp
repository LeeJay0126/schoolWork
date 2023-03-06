#include "Merge.h"
#include <iostream>
#include <chrono>

Merge::Merge()
{
    firstList = nullptr;
    secondList = nullptr;
    result = nullptr;
}

void Merge::reset()
{
    if (firstList != nullptr)
    {
        if (firstList->next == nullptr)
        {
            delete firstList;
            firstList = nullptr;
        }
        else
        {
            Node *temp;
            temp = firstList;
            while (firstList != nullptr)
            {
                std::cout << "a" << std::endl;
                temp = firstList->next;
                delete firstList;
                firstList = temp;
            }
            firstList = nullptr;
        }
    }
    if (secondList != nullptr)
    {
        if (secondList->next == nullptr)
        {
            delete secondList;
            secondList = nullptr;
        }
        else
        {
            Node *temp;
            temp = secondList;
            while (secondList != nullptr)
            {
                temp = secondList->next;
                delete secondList;
                secondList = temp;
            }
            secondList = nullptr;
        }
    }
    if (result != nullptr)
    {
        if (result->next == nullptr)
        {
            delete result;
            result = nullptr;
        }
        else
        {
            Node *temp;
            temp = result;
            while (result != nullptr)
            {
                temp = result->next;
                delete result;
                result = temp;
            }
            result = nullptr;
        }
    }
}

void Merge::resetResult()
{
    if (result != nullptr)
    {
        Node *temp;
        temp = result;
        while (result != nullptr)
        {
            temp = result->next;
            delete result;
            result = temp;
        }
        result = nullptr;
    }
}

void Merge::insert(bool first, int x)
{
    Node *node;

    Node *temp = new Node();
    temp->value = x;
    temp->next = nullptr;

    if (first)
    {
        node = firstList;
        if (node == nullptr)
        {
            firstList = temp;
        }
        else
        {
            while (node->next != nullptr)
            {
                node = node->next;
            }
            node->next = temp;
        }
    }
    else
    {
        node = secondList;
        if (node == nullptr)
        {
            secondList = temp;
        }
        else
        {
            while (node->next != nullptr)
            {
                node = node->next;
            }
            node->next = temp;
        }
    }

    std::cout << x << std::endl;
}

Merge::Node *Merge::merge(Node *p, Node *q)
{
    // std::cout << p->value << std::endl;

    if (p == nullptr)
    {
        return q;
    }
    if (q == nullptr)
    {
        return p;
    }
    if (p->value <= q->value)
    {
        p->next = merge(p->next, q);
        return p;
    }
    else
    {
        q->next = merge(p, q->next);
        return q;
    }
}

double Merge::repeatingMerge(int x)
{
    Node *first;
    Node *second;
    double time = 0;
    Node *temp;

    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < x; i++)
    {
        first = firstList;
        second = secondList;
        temp = merge(first, second);
        std::cout << "b" << std::endl;
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = (end - start) / x;

    time = diff.count();

    return time;
}