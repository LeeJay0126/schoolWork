// Name:

// Represents a univariate polynomial using a binary search tree
// Course: CPSC 2150

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <functional> // std::function
#include <string>

#include "Term.h"
#include "Polynomial.h"

// create the zero polynomial
// CPSC 2150
// initializing the comparison function between term degrees done for you
Polynomial::Polynomial(std::function<bool(int, int)> fct) : cmp(fct)
{
   root = nullptr;
}

Polynomial::Node *Polynomial::cons(int c, int d)
{
   Term *newTerm = new Term(c, d);
   return new Node{nullptr, newTerm, nullptr};
}

bool Polynomial::isZeroPolynomial() const
{
   return (root == nullptr);
}

// postcondition:
//    a Polynomial with one term c x^d is created
//    c becomes the coefficient of the only term in the polynomial
//    d becomes the degree of the only term in the polynomial
Polynomial::Polynomial(int c, int d, std::function<bool(int, int)> fct)
{
   cmp = fct; // a different way of initializing the instance variable cmp
   root = cons(c, d);
}

// precondition:
//   the term pointed to by t has been allocated
//   t != nullptr
// postcondition:
//
void Polynomial::insert(Term *t)
{
   Node *newNode = cons(t->coeff(), t->degree());

   if (root == nullptr)
   {
      root = newNode;
   }
   else
   {
      bool flag = false;
      Node *temp = root;

      while (flag == false)
      {
         if (temp->term->degree() == t->degree())
         {
            // int res = temp->term->degree() + t->degree();
            int coef = temp->term->coeff() + t->coeff();
            // temp->term->setDegree(res);
            temp->term->setCoeff(coef);
            flag = true;
         }
         else if (cmp(t->degree(), temp->term->degree()))
         {
            if (temp->left == nullptr)
            {
               temp->left = newNode;
               flag = true;
            }
            else
            {
               Node *next = temp->left;
               if (cmp(t->degree(), next->term->degree()))
               {
                  temp = temp->left;
               }
               else
               {
                  temp->left = newNode;
                  newNode->left = next;
                  flag = true;
               }
            }
         }
         else
         {
            if (temp->right == nullptr)
            {
               temp->right = newNode;
               flag = true;
            }
            else
            {
               Node *next = temp->left;
               if (cmp(t->degree(), next->term->degree()))
               {
                  temp = temp->right;
               }
               else
               {
                  temp->right = newNode;
                  newNode->right = next;
                  flag = true;
               }
            }
         }
      }
   }

   // std::cout << temp->term->degree() << std::endl;
   // std::cout << temp->term->coeff() << std::endl;
}

// postcondition:
//    returns the highest degree of the polynomial
//    in the special case of the zero polynomial, return -1
int Polynomial::degree() const
{
   Node *temp = root;
   if (root == nullptr)
   {
      return -1;
   }

   while (temp->right != nullptr)
   {
      temp = temp->right;
   }
   return temp->term->degree();
}

// postcondition:
//    returns the coefficient of term that has degree n
int Polynomial::coefficient(int n) const
{
   if (root == nullptr)
   {
      return -1;
   }

   Node *temp = root;

   while (temp->term->degree() != n && temp != nullptr)
   {
      if (temp->term->degree() > n)
      {
         temp = temp->left;
      }
      else if (temp->term->degree() < n)
      {
         temp = temp->right;
      }
   }

   if (temp == nullptr)
   {
      return -1;
   }

   return temp->term->coeff();
}

// postcondition:
//    returns the number of terms in the tree
//    in the special case of the zero polynomial return 1
int Polynomial::numberOfTerms() const
{
   if (root == nullptr)
   {
      return -1;
   }
   Node *temp = root;
   int term = termNum(temp);

   return term;
}

int Polynomial::termNum(Node *tree) const
{
   if (tree == nullptr)
   {
      return 0;
   }
   int lh = termNum(tree->left);
   int rh = termNum(tree->right);

   if (tree->term->degree() == 0)
   {
      return lh + rh;
   }

   return lh + rh + 1;
}

// postcondition:
//    returns the value of evaluating the polynomial at x
double Polynomial::evaluate(double x) const
{
   return treeSum(x, root);
}

double Polynomial::treeSum(double x, Node *tree) const
{
   if (tree == nullptr)
   {
      return 0;
   }

   double lh = treeSum(x, tree->left);
   double rh = treeSum(x, tree->right);

   double coeff = tree->term->coeff();
   double degree = tree->term->degree();
   double ans = coeff * pow(x, degree);

   return lh + rh + ans;
}

// precondition:
//    a and b are the two polynomials to sum up,
// postcondition:
//    create a new polynomial which is the sum of two given polynomials
//    only the non-zero terms will be stored in the sum polynomial
const Polynomial Polynomial::operator+(const Polynomial &b)
{
   Polynomial newPoly(cmp);

   Node *temp = root;
   addHelper(b.root, temp, newPoly);
   addHelper(temp, b.root, newPoly);

   return newPoly;
}

// calling degreesearch and inserting to new Polynomial object while traversing through the nodes
// using recursion
void Polynomial::addHelper(Node *otherRoot, Node *tree, Polynomial &res)
{
   if (tree != nullptr)
   {
      Term *foundTerm = degreeSearchA(otherRoot, tree->term->degree());
      Node *temp = cons(foundTerm->coeff() + tree->term->coeff(), foundTerm->degree());
      res.insert(temp->term);
      addHelper(otherRoot, tree->right, res);
      addHelper(otherRoot, tree->left, res);
   }
}

void Polynomial::addHelper2(Node *otherRoot, Node *tree, Polynomial &res)
{
   if (tree != nullptr)
   {
      Term *foundTerm = degreeSearchB(otherRoot, tree->term->degree());
      if (foundTerm != nullptr)
      {
         Node *temp = cons(foundTerm->coeff() + tree->term->coeff(), foundTerm->degree());
         res.insert(temp->term);
         addHelper2(otherRoot, tree->right, res);
         addHelper2(otherRoot, tree->left, res);
      }
   }
}

Term *Polynomial::degreeSearchB(Node *tree, int x)
{
   while (tree != nullptr)
   {
      if (tree->term->degree() == x)
      {
         return nullptr;
      }
      else if (cmp(tree->term->degree(), x))
      {
         tree = tree->left;
      }
      else
      {
         tree = tree->right;
      }
   }

   return tree->term;
}

// Searching for a node with the same degree
// Used to get all the matching values from poly a from poly b
Term *Polynomial::degreeSearchA(Node *tree, int x)
{
   while (tree != nullptr)
   {
      if (tree->term->degree() == x)
      {
         return tree->term;
      }
      else if (cmp(tree->term->degree(), x))
      {
         tree = tree->left;
      }
      else
      {
         tree = tree->right;
      }
   }

   Node *temp = cons(0, 0);
   return temp->term;
}

// copy constructor
// precondition:
//    p is the Univariate we are copying from
// precondition:
//    p is the Polynomial we are copying from
Polynomial::Polynomial(const Polynomial &p)
{
   cmp = p.cmp;
   copyHelper(p.root);
}

void Polynomial::copyHelper(Node *otherRoot)
{
   if (otherRoot != nullptr)
   {
      if (otherRoot != 0)
      {
         insert(otherRoot->term);
      }
      copyHelper(otherRoot->right);
      copyHelper(otherRoot->left);
   }
}

// destructor
Polynomial::~Polynomial()
{
   destructHelper(root);
}

void Polynomial::destructHelper(Node *root)
{
   if (root != nullptr)
   {
      destructHelper(root->left);
      destructHelper(root->right);
      delete root->term;
      delete root;
   }
}

// overloaded assignment operator
Polynomial &Polynomial::operator=(const Polynomial &rtSide)
{
   cmp = rtSide.cmp;
   root = rtSide.root;

   return *this;
}

// postcondition:
//    outputs the polynomial, starting with the highest degree
void Polynomial::printer(Node *tree, std::ostream &out)
{
   // Term ter2 = Term(tree->left->term->coeff(), tree->left->term->degree());
   // std::cout << ter2 << std::endl;
   if (tree->left != nullptr)
   {
      printer(tree->left, out);
   }
   if (tree->term->coeff() != 0)
   {
      Term ter = Term(tree->term->coeff(), tree->term->degree());
      out << ter;
   }
   if (tree->right != nullptr)
   {
      printer(tree->right, out);
   }
}

std::ostream &operator<<(std::ostream &out, const Polynomial &p)
{
   if (p.root == nullptr)
   {
      return out;
   }
   Polynomial::Node *temp = p.root;
   p.printer(temp, out);

   return out;
}

// postcondition:
//    if non numeric input is given, the istream enters a fail state
//    only non-zero terms will be inserted into the polynomial
std::istream &operator>>(std::istream &in, Polynomial &poly)
{
   int n;
   // input the number of non-zero terms n of the polynomial: ";
   in >> n;
   // get the degree and coefficient of every term
   int degree = 0;
   int coeff = 0;
   for (int i = 0; i < n; i++)
   {
      in >> coeff;
      // std::cout << coeff << std::endl;
      in >> degree;
      // std::cout << degree << std::endl;
      poly.insert(new Term(coeff, degree));
   }

   return in;
}

// BONUS
// postcondition:
//    returns a new polynomial with the differentiated polynomial
const Polynomial Polynomial::differentiate() const
{
   // dummy return value for NOW
   return Polynomial(cmp);
}

// return the variable used for output
// CPSC 2150: nothing to do
char Polynomial::variable()
{
   return Term::variable();
}

// set the variable used for output to ch
// CPSC 2150: nothing to do
void Polynomial::setVariable(char ch)
{
   Term::setVariable(ch);
}
