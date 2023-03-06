#ifndef MERGE_H
#define MERGE_H

#include <iostream>

class Merge
{
public:
    // constructor
    Merge();

    // class note for merge list
    void insert(bool first, int x);

    void reset();

    void resetResult();

    // ~Merge();

    double repeatingMerge(int x);

private:
    struct Node
    {
        int value;
        Node *next;
    };

    Node *merge(Node *p, Node *q);

    Node *mergeL(Node *p, Node *q);

    Node *firstList;
    Node *secondList;
    Node *result;
};

#endif