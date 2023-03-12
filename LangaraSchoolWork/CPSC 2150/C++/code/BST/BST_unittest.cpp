// CPSC 2150 by Gladys Monagan
// Copyright 2022
// Do not post anywhere

#include "gtest/gtest.h"
#include "BST.h"
#include "BST_utils.h"
#include <string>
using std::cout;
using std::string;

using monagan::makeLeaf, monagan::insertRight, monagan::insertLeft;
using monagan::toString, monagan::twoToString, monagan::destroyTree;

/*
tests for sameVals
./BST_unittest --gtest_filter="sameValsTestSuite.*"

tests for diff
./BST_unittest --gtest_filter="diffTestSuite.*"


tests for heightBalanced
./BST_unittest --gtest_filter="heightBalancedTestSuite.*"
*/

// uncomment the next line if you DO want debugging
#define NDEBUG

TEST(sameValsTestSuite, SpecialEmptyTrees) {
   EXPECT_TRUE(sameVals(nullptr, nullptr));
}

TEST(sameValsTestSuite, IdenticalTrees1) {
   Node* p = makeLeaf(7);
   Node *q = makeLeaf(7);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 1NodeTreeFail) {
   Node* p = makeLeaf(4);
   Node *q = makeLeaf(7);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 2IdentialNodesTree) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 7);
   Node *q = makeLeaf(5);
   q = insertRight(q, 7);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, SameValsDiffStruct2) {
   Node* p = makeLeaf(6);
   p = insertRight(p, 8);
   Node *q = makeLeaf(8);
   q = insertLeft(q, 6);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructsFail) {
   Node* p = makeLeaf(4);
   p = insertRight(p, 7);
   Node *q = makeLeaf(4);
   q = insertRight(q, 5);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructs2Fail) {
   Node* p = makeLeaf(4);
   p = insertLeft(p, 2);
   Node *q = makeLeaf(4);
   q = insertLeft(q, 1);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 3NodesTreeRR) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 20);
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 3NodesTreeLL) {
   Node* p = makeLeaf(9);
   p = insertLeft(p, 7);
   p = insertLeft(p, 5);
   Node* q = makeLeaf(9);
   q = insertLeft(q, 7);
   q = insertLeft(q, 5);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct3NodesTree1) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 20);
   Node* q = makeLeaf(20);
   q = insertLeft(q, 15);
   q = insertLeft(q, 10);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct3NodesTree2) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 20);
   Node* q = makeLeaf(15);
   q = insertLeft(q, 10);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct3NodesTree3) {
   Node* p = makeLeaf(20);
   p = insertLeft(p, 15);
   p = insertLeft(p, 10);
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}


TEST(sameValsTestSuite, DiffStruct3NodesTree4) {
   Node* p = makeLeaf(15);
   p = insertLeft(p, 10);
   p = insertRight(p, 20);
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructs3Fail) {
   Node* p = makeLeaf(10);
   p = insertRight(p, 15);
   p = insertRight(p, 30); // value not found in q
   Node* q = makeLeaf(10);
   q = insertRight(q, 15);
   q = insertRight(q, 20);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 3NodesTree2Fail) {
   Node* p = makeLeaf(15);
   p = insertRight(p, 20);
   p = insertLeft(p, 5); // value not found in q
   Node* q = makeLeaf(15);
   q = insertRight(q, 20);
   q = insertLeft(q, 10);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTree) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 5); 
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTreeSwap) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 5); 
   // swapping p and q
   EXPECT_TRUE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTreeFail) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 3); 
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, 4NodesTreeSwapFail) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 10);
   p = insertRight(p, 15); 
   p = insertRight(p, 20); 
   Node* q = makeLeaf(20);
   q = insertLeft(q, 10);
   q->left = insertRight(q->left, 15); 
   q = insertLeft(q, 3); 
   // swapping p and q
   EXPECT_FALSE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, qMoreNodespOneFail) {
   Node* p = makeLeaf(2);
   Node* q = makeLeaf(15);
   q = insertLeft(q, 10);
   q = insertRight(q, 20);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, pMoreNodespOneFail) {
   Node* p = makeLeaf(2);
   Node* q = makeLeaf(15);
   q = insertLeft(q, 10);
   q = insertRight(q, 20);
   // swapping p and q
   EXPECT_FALSE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, qMoreNodes) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 7);
   p = insertRight(p, 9); 
   Node* q = makeLeaf(5);
   q = insertRight(q, 7);
   q = insertRight(q, 9); 
   q->right = insertLeft(q->right, 8); // value not found in q
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, pMoreNodesFail) {
   Node* p = makeLeaf(5);
   p = insertRight(p, 7);
   p = insertRight(p, 9); 
   Node* q = makeLeaf(5);
   q = insertRight(q, 7);
   q = insertRight(q, 9); 
   q->right = insertLeft(q->right, 8); // value not found in q
   // swapping p and q
   EXPECT_FALSE(sameVals(q, p)) << twoToString(q, p);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, pMoreNodesqEmptyFail) {
   Node* p = makeLeaf(2);
   Node* q = nullptr;
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, qMoreNodespEmptyFail) {
   Node* p = nullptr;
   Node* q = makeLeaf(2);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, IdenticalTrees6NodesTree1) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 7);
   q = insertLeft(q, 2);
   q->left = insertRight(q->left, 18);
   q->left->left = insertRight(q->left->left, 4);
   q->left->left->right = insertRight(q->left->left->right, 6);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, IdenticalTrees6NodesTree2) {
   Node* p = makeLeaf(-10);
   p = insertRight(p, -7);
   p = insertRight(p, -2);
   p->right = insertLeft(p->right, -9);
   p->right->right = insertLeft(p->right->right, -4);
   p->right->right->left = insertLeft(p->right->right->left, -6);
   Node* q = makeLeaf(-10);
   q = insertRight(q, -7);
   q = insertRight(q, -2);
   q->right = insertLeft(q->right, -9);
   q->right->right = insertLeft(q->right->right, -4);
   q->right->right->left = insertLeft(q->right->right->left, -6);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, Structs6NodesTree1Fail) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 7);
   q = insertLeft(q, 2);
   q->left = insertRight(q->left, 18);
   q->left->left = insertRight(q->left->left, 4);
   q->left->left->right = insertRight(q->left->left->right, 5); // here
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, SameStructs6NodesTree2Fail) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 5); // here
   Node* q = makeLeaf(29);
   q = insertLeft(q, 7);
   q = insertLeft(q, 2);
   q->left = insertRight(q->left, 18);
   q->left->left = insertRight(q->left->left, 4);
   q->left->left->right = insertRight(q->left->left->right, 6);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, SameStructs6NodesTree3Fail) {
   Node* p = makeLeaf(-10);
   p = insertRight(p, -8); // here
   p = insertRight(p, -2);
   p->right = insertLeft(p->right, -9);
   p->right->right = insertLeft(p->right->right, -4);
   p->right->right->left = insertLeft(p->right->right->left, -6);
   Node* q = makeLeaf(-10);
   q = insertRight(q, -7);
   q = insertRight(q, -2);
   q->right = insertLeft(q->right, -9);
   q->right->right = insertLeft(q->right->right, -4);
   q->right->right->left = insertLeft(q->right->right->left, -6);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffValsSameStructs6NodesTree4Fail) {
   Node* p = makeLeaf(-10);
   p = insertRight(p, -7); 
   p = insertRight(p, -2);
   p->right = insertLeft(p->right, -9);
   p->right->right = insertLeft(p->right->right, -4);
   p->right->right->left = insertLeft(p->right->right->left, -6);
   Node* q = makeLeaf(-10);
   q = insertRight(q, -7);
   q = insertRight(q, -2);
   q->right = insertLeft(q->right, -9);
   q->right->right = insertLeft(q->right->right, -5); // here
   q->right->right->left = insertLeft(q->right->right->left, -6);
   EXPECT_FALSE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}

TEST(sameValsTestSuite, DiffStruct6NodesTree2) {
   Node* p = makeLeaf(29);
   p = insertLeft(p, 7);
   p = insertLeft(p, 2);
   p->left = insertRight(p->left, 18);
   p->left->left = insertRight(p->left->left, 4);
   p->left->left->right = insertRight(p->left->left->right, 6);
   Node* q = makeLeaf(29);
   q = insertLeft(q, 18);
   q = insertLeft(q, 7);
   q = insertLeft(q, 6);
   q = insertLeft(q, 4);
   q = insertLeft(q, 2);
   EXPECT_TRUE(sameVals(p, q)) << twoToString(p, q);
   destroyTree(p);
   destroyTree(q);
}


TEST(heightBalancedTestSuite, 7NodesTree3L3RFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -2);
   tree = insertLeft(tree, -4);
   tree = insertLeft(tree, -6);
   tree = insertRight(tree, 1);
   tree = insertRight(tree, 3);
   tree = insertRight(tree, 5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 5NodesTree1L2R1RL) {
   Node* tree = makeLeaf(13);
   tree = insertLeft(tree, 11);
   tree = insertRight(tree, 15);
   tree = insertRight(tree, 17);
   tree->right = insertLeft(tree->right, 14);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, EmptyTree) {
   Node* tree = nullptr;
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 1NodeFullTree) {
   Node* tree = makeLeaf(7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 2NodesTree1L) {
   Node* tree = makeLeaf(7);
   tree = insertLeft(tree, 5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 2NodesTree1R) {
   Node* tree = makeLeaf(3);
   tree = insertRight(tree, 8);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 3NodesTree2RFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 3NodesTree2LFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 3NodesFullTree1L1R) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree3LFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree3RFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree2L1) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree1L2R) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree2L1LRFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -5);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree2R1RLFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 4NodesTree1R1RL1RLRFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 4);
   tree->right->left = insertLeft(tree->right->left, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, Root05NodesTree1L2R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -2);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 5NodesTree2L2R) {
   Node* tree = makeLeaf(6);
   tree = insertLeft(tree, 4);
   tree = insertLeft(tree, 2);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 6NodesTree1L1LR2R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 6NodesTree2L1LR1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree3L1LR1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 6NodesTree3LR1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
}

TEST(heightBalancedTestSuite, 6NodesTree2R1RL1RLL1RLRFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 5NodesTree2R1RL1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTreeFull) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -6);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesNotTreeFull) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -8);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->left->left = insertRight(tree->left->left, -6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesIsNotTreeFull) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -8);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->left->left = insertRight(tree->left->left, -7);
   tree->left->left->right = insertRight(tree->left->left->right, -6);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree2L2L1RL1RLR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree2LR1LRL1R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -3);
   tree->left->right = insertLeft(tree->left->right, -4);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 7NodesTree3L2R1RLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesIsNotTreeAFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -3);
   tree = insertLeft(tree, -8);
   tree->left->left = insertRight(tree->left->left, -6);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 3);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree1L1RL1L3R1LR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree2L1RL1LLR1RLR1R1LR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -3);
   tree->left->right = insertLeft(tree->left->right, -4);
   tree->left->right = insertRight(tree->left->right, -2);
   tree = insertRight(tree, 4);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree1L1RL2L2R1LR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 8NodesTree2L2R1RL1RLR) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 4);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesTree2L2R1RL1RLR1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right = insertLeft(tree->right, 1);
   tree->right->left = insertRight(tree->right->left, 4);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, 9NodesTree4L4RFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -2);
   tree = insertLeft(tree, -4);
   tree = insertLeft(tree, -6);
   tree = insertLeft(tree, -8);
   tree = insertRight(tree, 1);
   tree = insertRight(tree, 3);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, TenNodesTree2L2R1RL1RLR1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree->left = insertRight(tree->left, -2);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right = insertLeft(tree->right, 1);
   tree->right->left = insertRight(tree->right->left, 4);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, FifteenNodesNO) {
   Node* tree = makeLeaf(50);
   tree = insertLeft(tree, 40);
   tree = insertLeft(tree, 30);
   tree = insertLeft(tree, 20);
   tree = insertLeft(tree, 10);
   tree->left = insertRight(tree->left, 45);
   tree->left = insertRight(tree->left, 48);
   tree = insertRight(tree, 60);
   tree = insertRight(tree, 70);
   tree = insertRight(tree, 80);
   tree->right->right = insertLeft(tree->right->right, 69);
   tree->right = insertLeft(tree->right, 55);
   tree->right->left = insertLeft(tree->right->left, 53);
   tree->right->left = insertLeft(tree->right->left, 51);
   tree->right->left = insertRight(tree->right->left, 57);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_FALSE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(heightBalancedTestSuite, SixteenNodesNo) {
   Node* tree = makeLeaf(50);
   tree = insertLeft(tree, 40);
   tree = insertLeft(tree, 30);
   tree = insertLeft(tree, 20);
   tree = insertLeft(tree, 10);
   tree->left->left = insertRight(tree->left->left, 35);
   tree->left = insertRight(tree->left, 45);
   tree->left = insertRight(tree->left, 48);
   tree = insertRight(tree, 60);
   tree = insertRight(tree, 70);
   tree = insertRight(tree, 80);
   tree->right->right = insertLeft(tree->right->right, 69);
   tree->right = insertLeft(tree->right, 55);
   tree->right->left = insertLeft(tree->right->left, 53);
   tree->right->left = insertLeft(tree->right->left, 51);
   tree->right->left = insertRight(tree->right->left, 57);
   #ifndef NDEBUG
   cout << toString(tree, "input = ") << "\n";
   #endif
   EXPECT_TRUE(heightBalanced(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}


// copyright 2022 Gladys Monagan
