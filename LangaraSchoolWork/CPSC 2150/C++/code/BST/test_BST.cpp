// CPSC 2150 by Gladys Monagan
// Do not post anywhere

#include <iostream>
#include "BST.h"
#include "BST_utils.h"
#include <string>

int main() {
   using monagan::makeLeaf, monagan::insertRight,  monagan::insertLeft;
   using monagan::toString, std::cout, std::endl;

   Node* tree1 = makeLeaf(4);
   tree1 = insertLeft(tree1, 3);
   tree1 = insertRight(tree1, 5);

   Node* tree2 = makeLeaf(5);
   tree2 = insertLeft(tree2, 4);
   tree2 = insertLeft(tree2, 3);

   if (sameVals(tree1, tree2)) {
      cout << "true as expected " << endl;
   }
   else {
      cout << "sameVals should have returned true: these are the same" << endl;
      cout << toString(tree1) << endl;
      cout << toString(tree2) << endl;
   }
   return 0;
}

// copyright 2022 Gladys Monagan


