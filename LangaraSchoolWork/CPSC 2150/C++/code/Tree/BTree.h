// CPSC 2150
// Gladys Monagan, do not post anywhere

#ifndef BTREE_H
#define BTREE_H

struct Node {
   Node* left;
   int val;
   Node* right;
};

// part A)
Node* makeBalBST(Node* tree);

// part C)
int nodeSum(const Node* tree);

// part D)
bool isB(const Node* tree);



#endif
