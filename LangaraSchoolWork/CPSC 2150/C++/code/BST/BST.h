// CPSC 2150 Gladys Monagan
// do not submit

#ifndef BST_H
#define BST_H

struct Node
{
   Node *left;
   int val;
   Node *right;
};

bool sameVals(const Node *p, const Node *q);

bool heightBalanced(const Node *tree);

int numNodes(const Node *tree);

int median(const Node *tree);
int height(Node *tree);
int toArray(int arr[], int index, const Node *p);
void sort(int arr[], int size);



#endif
