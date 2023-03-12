// CPSC 2150 Gladys Monagan
// Do not post anywhere

#include <iostream>
#include "BTree.h"
#include "BTree_utils.h"
#include <string>
using std::string;


int main() {
   using monagan::makeEmptyBinTree, monagan::makeLeaf, monagan::insertRight;
   using monagan::insertLeft, monagan::toString;
   using std::cout;

   Node* emptyTree = makeEmptyBinTree();

   Node* tree1 = makeLeaf(7);
   tree1 = insertLeft(tree1, 1);
   tree1 = insertLeft(tree1, 2);
   tree1 = insertLeft(tree1, 3);
   tree1 = insertRight(tree1, 4);
   tree1 = insertRight(tree1, 5);
   tree1 = insertRight(tree1, 6);

   Node* tree2 = makeLeaf(-2);
   tree2 = insertLeft(tree2, -4);
   tree2 = insertRight(tree2, -9);
   tree2 = insertRight(tree2, 5);
   tree2->right = insertLeft(tree2->right, -1);

   if (nodeSum(emptyTree) == 0) {
      cout << "nodeSum is 0 as expected";
   }
   else {
      cout << "for an empty tree, nodeSum erroneously returns ";
      cout << nodeSum(emptyTree);
   }
   cout << "\n\n";
   if (nodeSum(tree1) == 28) {
      cout << "nodeSum(tree1) is 28 as expected";
   }
   else {
      cout << "nodeSum(tree1) erroneously returns ";
      cout << nodeSum(tree1);
   }
   cout << "\n\n";
   if (nodeSum(tree2) == -11) {
      cout << "nodeSum(tree2) is -11 as expected";
   }
   else {
      cout << "nodeSum(tree2) erroneously returns ";
      cout << nodeSum(tree2);
   }
   cout << "\n\n";

   if (isB(emptyTree)){
      cout << "true as expected for emptyTree\n";
      cout << toString(emptyTree);
   }
   else {
      cout << "ERROR: false was returned\n";
      cout << toString(emptyTree);
   }
   cout << "\n\n";

   if (isB(tree1)){
      cout << "ERROR: should be false for tree1 but true was returned\n";
      cout << toString(tree1);
   }
   else {
      cout << "false as expected for tree1\n";
      cout << toString(tree1);
   }
   cout << "\n\n";

   if (isB(tree2)){
      cout << "true as expected for tree2\n";
      cout << toString(tree2);
   }
   else {
      cout << "ERROR: should be true for tree2 but false was returned\n";
      cout << toString(tree2);
   }
   cout << "\n\n";

   return 0;
}

