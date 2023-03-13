// Student Name:

#include "BTree.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// part A)
Node *makeBalBST(Node *tree)
{
   int size = treeSize(tree);
   int *arr = new int(size);

   arr = storeArray(arr, tree);

   int temp = 0;
   for (int i = 0; i < size - 1; i++)
   {
      for (int j = 0; j < size - i - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = arr[j];
         }
      }
   }

   int coreNode = arr[size / 2];

   Node *newTree = makeLeaf(arr[coreNode]);

   
}

Node *makeLeaf(int x)
{
   return new Node{nullptr, x, nullptr};
}
Node *makeEmptyBinTree()
{
   return nullptr;
}
Node *insertRight(Node *p, int x)
{
   if (p == nullptr)
      p = makeLeaf(x);
   else
      p->right = insertRight(p->right, x);
   return p;
}
Node *insertLeft(Node *p, int x)
{
   if (p == nullptr)
      p = makeLeaf(x);
   else
      p->left = insertLeft(p->left, x);
   return p;
}

void push(int arr[], int x)
{
   int i = 0;
   while (arr[i] != NULL)
   {
      i += 1;
   }
   arr[i] = x;
}

int treeSize(Node *tree)
{
   if (tree == nullptr)
   {
      return 0;
   }
   int lh = treeSize(tree->left);
   int rh = treeSize(tree->right);

   return lh + rh + 1;
}

int *storeArray(int arr[], Node *tree)
{
   if (tree == nullptr)
   {
      return;
   }
   storeArray(arr, tree->left);
   push(arr, tree->val);
   storeArray(arr, tree->right);

   return arr;
}

///////////////////////////////////////////////////////////////////////////////
// part B) the complexity of makeBalBST when the tree has n nodes
// in big O notation the complexity is
// because
//
//
// was a new tree made?
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// part C)
int nodeSum(const Node *tree)
{
   std::cerr << "******* not implemented\n";
   return -9999; // fix
}

///////////////////////////////////////////////////////////////////////////////
// part D)
bool isB(const Node *tree)
{
   std::cerr << "******* not implemented\n";
   return false; // fix
}
