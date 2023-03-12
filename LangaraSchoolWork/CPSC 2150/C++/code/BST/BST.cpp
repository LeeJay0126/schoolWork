// Name:

#include <iostream>
#include "BST.h"

///////////////////////////////////////////////////////////////////////////////
bool sameVals(const Node *p, const Node *q)
{
    int numP = numNodes(p);
    int numQ = numNodes(q);

    if(numP != numQ){
        return false;
    }

    int * arrayP = new int 

}


// bool sameVals(const Node *p, const Node *q)
// {
//     if (p == nullptr && q == nullptr)
//     {
//         return true;
//     }
//     if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) || (p->val != q->val))
//     {
//         return false;
//     }

//     bool lh = sameVals(p->left, q->left);
//     bool rh = sameVals(p->right, q->right);

//     if (lh && rh)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

///////////////////////////////////////////////////////////////////////////////
bool heightBalanced(const Node *tree)
{
    if (tree == nullptr)
    {
        return true;
    }

    int lh = numNodes(tree->left);
    int rh = numNodes(tree->right);

    if ((lh - rh) <= 1 || (rh - lh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int numNodes(const Node *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }

    int lefth = numNodes(tree->left);
    int righth = numNodes(tree->right);

    if (lefth > righth)
    {
        return lefth + 1;
    }
    else
    {
        return righth + 1;
    }
}

int median(const Node *tree)
{
    int num = numNodes(tree);
    Node *temp;
    temp->val = tree->val;
    temp->left = tree->left;
    temp->right = tree->right;

    int res = store(temp, num / 2);

    return res;
}

int store(Node *tree, int num)
{

    if (tree == nullptr)
    {
        return 0;
    }

    int lh = store(tree->left, num);
    int rh = store(tree->right, num);

    if (num == lh + rh)
    {
        return tree->val;
    }

    return lh + rh + 1;
}