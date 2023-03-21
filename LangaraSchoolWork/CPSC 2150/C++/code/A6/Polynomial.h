// Name:
//
// Represents a univariate polynomial with a binary search tree
// using the degree of a term as the search key
// Course: CPSC 2150, Gladys Monagan
// Do not post anywhere.
// Submit the assignment using Brightspace

#ifndef UNIVARIATE_H
#define UNIVARIATE_H

#include <iostream>   // std::ostream
#include <functional> // std::function
#include "Term.h"     // Polynomial is a friend of Term

class Polynomial
{
public:
   // about the comparison function cmpFct set with the constructors
   //   if d is the degree of a term to insert into the tree
   //   and g is the degree of a current node's term of the tree being traversed
   //   and d != g,
   //   cmpFct(d, g) == true means insert the term into the LEFT subtree
   //   cmpFct(d, g) == false means insert the term into the RIGHT subtree
   // use this same logic/function for traversing the tree including
   // getting the polynomial's degree and the coefficient of a term

   // create the zero polynomial
   // and initialize the comparison function between term degrees
   Polynomial(std::function<bool(int, int)> cmpFct);
   // determine if the polynomial is the zero polynomial
   bool isZeroPolynomial() const;
   // create a monomial with one term c x^d
   // and initialize the comparison function between term degrees
   // c becomes the coefficient of the only term in the polynomial
   // d becomes the degree of the only term in the polynomial
   Polynomial(int c, int d, std::function<bool(int, int)> cmpFct);
   // insert an already created term into the polynomial
   // use the comparison function cmpFct to insert the term
   // see note above
   // precondition:
   //    t != nullptr
   // postcondition:
   //    there are no two terms with the same degree
   //    no term has 0 as coefficient except for the zero polynomial
   void insert(Term *t);
   // return the highest degree of the polynomial
   // in the special case of the zero polynomial return -1
   int degree() const;
   // return the coefficient of term that has degree n
   int coefficient(int n) const;
   // return the number of terms in the polynomial:
   // for the zero polynomial return 1
   int numberOfTerms() const;
   // evaluate the polynomial with the given value of x
   double evaluate(double x) const;
   // add (sum) two polynomials and return a new polynomial which is their sum
   const Polynomial operator+(const Polynomial &b);
   // copy constructor
   Polynomial(const Polynomial &);
   // destructor
   ~Polynomial();
   // overloaded assignment operator
   Polynomial &operator=(const Polynomial &);
   // return the variable used for output
   static char variable();
   // set the variable used for output to ch
   static void setVariable(char ch);
   // output the polynomial nicely using the variable set (with x as default)
   friend std::ostream &operator<<(std::ostream &, const Polynomial &);
   // first read the number of terms n (as an int)
   // followed by the pairs of coefficient and degree (as ints)
   // for each of the n terms
   friend std::istream &operator>>(std::istream &, Polynomial &);
   // BONUS
   // differentiate this polynomial and return a new polynomial
   const Polynomial differentiate() const;

private:
   // a Binary Search Tree Node
   // Each Node stores the pointer to a term and links to its children.
   // Terms are stored in the tree in the order depending on cmp order.
   //
   // Note:
   //     No duplicate terms i.e. terms with the same degree will be in the tree

   // You can make the Node a class of its own if you prefer but the
   // Node must have a pointer to a term two pointers to a left and to a right child
   // adjust the Makefile if you make Node a class and make a note that
   // you are doing so in the README.txt
   struct Node
   {
      Node *left;
      Term *term;
      Node *right;
   };

   // the BST is always sorted
   // there are no duplicate terms meaning no two terms have the same degree
   // see note above as to how cmp is used
   std::function<bool(int, int)> cmp;

   // the BST, the polynomial
   Node *root;

   // custom function
   // function that returns a new node
   Node *cons(int c, int d);
   // function that counts all the nodes(terms) in the tree
   int termNum(Node *tree) const;
   double treeSum(double x, Node *tree) const;
   static void printer(Node *tree, std::ostream &out);
   Term *degreeSearch(Node *tree, int x);
   void addHelper(Node *otherRoot, Node *tree, Polynomial &res);
   void copyHelper(Node *otherRoot);
   void destructHelper(Node *root);
};
#endif

// copyright 2023 Gladys Monagan
