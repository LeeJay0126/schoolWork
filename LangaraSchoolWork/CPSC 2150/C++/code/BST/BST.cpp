// Name:

#include <iostream>
#include "BST.h"

///////////////////////////////////////////////////////////////////////////////
//

bool sameVals(const Node *p, const Node *q)
{
    bool lh;
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if (p->left != nullptr && p->val > q->val)
    {
        lh = sameVals(p->left, q);
    }
    else if (q->left != nullptr && p->val < q->val)
    {
        lh = sameVals(p, q->left);
    }
    else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
    {
        return false;
    }
    else
    {
        lh = sameVals(p->left, q->left);
    }

    if ((p->val != q->val))
    {
        return false;
    }

    bool rh = sameVals(p->right, q->right);

    if (lh && rh)
    {
        return true;
    }
    else
    {
        return false;
    }
}

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