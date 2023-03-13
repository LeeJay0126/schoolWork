// CPSC 2150 by Gladys Monagan
// Copyright 2021
// Do not post anywhere

// having the option NDEBUG NOT defined means NO debugging occurs
// uncomment the next line if you DO want debugging
#define NDEBUG

#include "gtest/gtest.h"
#include "BTree.h"
#include "BTree_utils.h"
#include <string>
using std::string;
using std::cout;
using monagan::makeLeaf, monagan::insertRight, monagan::insertLeft;
using monagan::makeEmptyBinTree, monagan::destroyTree;
using monagan::toString;

TEST(makeBalBSTSuite, EmptyTree) {
   Node* tree = nullptr;
   #ifndef NDEBUG
   cout << toString(tree, "   input = ") << "\n";
   #endif
   EXPECT_EQ(makeBalBST(tree), nullptr) << toString(tree, " tree = ");
}

TEST(makeBalBSTSuite, 1NodeTree) {
   Node* tree = makeLeaf(7);
   #ifndef NDEBUG
   cout << toString(tree, "   input = ") << "\n";
   #endif
   EXPECT_TRUE(makeBalBST(tree)) << toString(tree, " tree = ");
   destroyTree(tree);
}

TEST(makeBalBSTSuite, 3NodesTreeRight) {
   Node* tree = makeLeaf(3);
   tree = insertRight(tree, 7);
   tree = insertRight(tree, 5);
   Node* expected_tree = makeLeaf(5);
   expected_tree = insertLeft(expected_tree, 3);
   expected_tree = insertRight(expected_tree, 7);
   #ifndef NDEBUG
   cout << toString(tree, "   tree = ") << "\n";
   cout << toString(expected_tree, "   expected_tree = ") << "\n";
   #endif
   Node* bst = makeBalBST(tree);
   EXPECT_EQ(toString(bst), toString(expected_tree));
   destroyTree(tree);
}

TEST(makeBalBSTSuite, 3NodesTreeLeft) {
   Node* tree = makeLeaf(9);
   tree = insertLeft(tree, 7);
   tree = insertLeft(tree, 8);
   Node* expected_tree = makeLeaf(8);
   expected_tree = insertLeft(expected_tree, 7);
   expected_tree = insertRight(expected_tree, 9);
   #ifndef NDEBUG
   cout << toString(tree, "   tree = ") << "\n";
   cout << toString(expected_tree, "   expected_tree = ") << "\n";
   #endif
   Node* bst = makeBalBST(tree);
   EXPECT_EQ(toString(bst), toString(expected_tree));
   destroyTree(tree);
}

TEST(makeBalBSTSuite, 3NodesTreeReverseBST) {
   Node* tree = makeLeaf(4);
   tree = insertLeft(tree, 6);
   tree = insertRight(tree, 8);
   Node* expected_tree = makeLeaf(6);
   expected_tree = insertLeft(expected_tree, 4);
   expected_tree = insertRight(expected_tree, 8);
   #ifndef NDEBUG
   cout << toString(tree, "   tree = ") << "\n";
   cout << toString(expected_tree, "   expected_tree = ") << "\n";
   #endif
   Node* bst = makeBalBST(tree);
   EXPECT_EQ(toString(bst), toString(expected_tree));
   destroyTree(tree);
}

TEST(sumTestSuite, EmptyTree) {
   Node* tree = makeLeaf(7);
   EXPECT_EQ(7, nodeSum(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(sumTestSuite, FourNodeTree3R) {
   Node* tree = makeLeaf(-3);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   EXPECT_EQ(9, nodeSum(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree3L) {
   Node* tree = makeLeaf(5);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 5);
   tree = insertLeft(tree, 5);
   EXPECT_EQ(20, nodeSum(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(sumTestSuite, SixNodeTree2R1RL1RLL1RLR) {
   Node* tree = makeLeaf(1);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 3);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 5);
   tree->right->left = insertRight(tree->right->left, 6);
   EXPECT_EQ(21, nodeSum(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(sumTestSuite, EightNodeTreeFull1R) {
   Node* tree = makeLeaf(-10);
   tree = insertLeft(tree, -9);
   tree->left = insertRight(tree->left, -8);
   tree = insertLeft(tree, -7);
   tree = insertRight(tree, -6);
   tree = insertRight(tree, -5);
   tree = insertRight(tree, -4);
   tree->right = insertLeft(tree->right, -1);
   EXPECT_EQ(-50, nodeSum(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isBEmptyTestSuite, EmptyTree) {
   EXPECT_TRUE(isB(makeEmptyBinTree()));
}

TEST(isB1NodeTestSuite, OneNodeTree) {
   Node* tree = makeLeaf(7);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB2NodesTestSuite, TwoNodeTree1L) {
   Node* tree = makeLeaf(7);
   tree = insertLeft(tree, 5);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB2NodesTestSuite, TwoNodeTree1) {
   Node* tree = makeLeaf(3);
   tree = insertRight(tree, 8);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB3NodesTestSuite, ThreeNodeTree2RFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 5);
   tree = insertRight(tree, 7);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB3NodesTestSuite, ThreeNodeTree2LFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB3NodesTestSuite, ThreeNodeTree1L1) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 2);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree3LFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertLeft(tree, -7);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree3RFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree2L1) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 2);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree1L2R) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 2);
   tree = insertRight(tree, 5);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree2L1LRFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -6);
   tree->left = insertRight(tree->left, -5);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree2R1RLFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 3);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB4NodesTestSuite, FourNodeTree1R1RL1RLRFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 4);
   tree->right->left = insertLeft(tree->right->left, 7);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB5NodesTestSuite, FiveNodeTree1L2R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB6NodesTestSuite, SixNodeTree1L1LR2R1RL) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree->left = insertRight(tree->left, -1);
   tree = insertRight(tree, 4);
   tree = insertRight(tree, 6);
   tree->right = insertLeft(tree->right, 2);
   EXPECT_TRUE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}


TEST(isB6NodesTestSuite, SixNodeTree2R1RL1RLL1RLRFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 2);
   tree->right->left = insertRight(tree->right->left, 7);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB5NodesTestSuite, FiveNodeTree2R1RL1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertRight(tree, 8);
   tree = insertRight(tree, 9);
   tree->right = insertLeft(tree->right, 4);
   tree->right = insertLeft(tree->right, 2);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB9NodesTestSuite, NineNodeTree2L2R1RL1RLR1RLLFail) {
   Node* tree = makeLeaf(0);
   tree = insertLeft(tree, -3);
   tree = insertLeft(tree, -5);
   tree = insertRight(tree, 6);
   tree = insertRight(tree, 8);
   tree->right = insertLeft(tree->right, 3);
   tree->right = insertLeft(tree->right, 2);
   tree->right = insertLeft(tree->right, 1);
   tree->right->left = insertRight(tree->right->left, 4);
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

TEST(isB10NodesTestSuite, TenNodeTree2L2R1RL1RLR1RLLFail) {
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
   EXPECT_FALSE(isB(tree)) << toString(tree) << "\n";
   destroyTree(tree);
}

