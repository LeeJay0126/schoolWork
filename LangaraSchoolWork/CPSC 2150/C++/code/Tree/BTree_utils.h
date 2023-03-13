// CPSC 2150 by Gladys Monagan
// Copyright 2021
// Do not post anywhere

#ifndef BTree_UTILS_H
#define BTree_UTILS_H
#include "BTree.h"
#include <string>
namespace monagan {
   Node* makeLeaf(int x);
   Node* makeEmptyBinTree();
   std::string toString(const Node* tree, std::string label = std::string(""));
   Node* insertRight(Node* tree, int x);
   Node* insertLeft(Node* tree, int x);
   void destroyTree(Node* &tree);
} 
#endif
