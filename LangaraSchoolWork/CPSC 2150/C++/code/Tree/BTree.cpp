// Student Name:

#include "BTree.h"
#include <iostream>

///////////////////////////////////////////////////////////////////////////////
// part A)
Node *makeBalBST(Node *tree)
{
   if (tree == nullptr)
   {
      return nullptr;
   }
   int size = NumNodes(tree);
   int *arr = new int[size];

   makeArr(arr, 0, tree);

   // sort using bubble sort
   for (int i = 0; i < size; i++)
   {
      for (int j = 0; j < size - 1; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }

   int mid = arr[size / 2];
   arr[size / 2] = -9999;
   Node *newTree = cons(mid);

   insert(newTree, size, arr);

   return newTree;
}

Node *cons(int x)
{
   return new Node{nullptr, x, nullptr};
}

void insert(Node *tree, int size, int arr[])
{
   for (int i = 0; i < size; i++)
   {
      if (!(arr[i] == -9999))
      {
         insert(tree, arr[i]);
      }
   }
}

void insert(Node *tree, int x)
{
   if (x > tree->val)
   {
      Node *next = tree->right;
      Node *newNode = cons(x);
      if (next == nullptr)
      {
         tree->right = newNode;
      }
      else
      {
         if (next->val > x)
         {
            tree->right = newNode;
            newNode->right = next;
         }
         else
         {
            insert(tree->right, x);
         }
      }
   }
   else
   {
      Node *next = tree->left;
      Node *newNode = cons(x);
      if (next == nullptr)
      {
         tree->left = newNode;
      }
      else
      {
         if (next->val > x)
         {
            insert(tree, x);
         }
         else
         {
            tree->left = newNode;
            newNode->left = next;
         }
      }
   }
}

int makeArr(int arr[], int index, Node *tree)
{
   if (tree == nullptr)
   {
      return index;
   }
   arr[index] = tree->val;
   index++;
   index = makeArr(arr, index, tree->left);
   index = makeArr(arr, index, tree->right);

   return index;
}

int NumNodes(Node *tree)
{
   if (tree == nullptr)
   {
      return 0;
   }
   int lh = NumNodes(tree->left);
   int rh = NumNodes(tree->right);

   return lh + rh + 1;
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
   if (tree == nullptr)
   {
      return 0;
   }

   int lh = nodeSum(tree->left);
   int rh = nodeSum(tree->right);

   return lh + rh + tree->val;
}

///////////////////////////////////////////////////////////////////////////////
// part D)
bool isB(const Node *tree)
{
   if (tree == nullptr)
   {
      return true;
   }

   bool lhb = isB(tree->left);
   bool rhb = isB(tree->right);

   if (!(lhb && rhb))
   {
      return false;
   }

   int lh = height(tree->left);
   int rh = height(tree->right);

   if ((lh - rh >= -1 && lh - rh <= 0) || (lh - rh >= 0 && lh - rh <= 1))
   {
      return true;
   }

   return false; // fix
}

int height(Node *tree)
{
   if (tree == nullptr)
   {
      return 0;
   }

   int lh = height(tree->left);
   int rh = height(tree->right);

   if (lh > rh)
   {
      return lh + 1;
   }

   return rh + 1;
}
