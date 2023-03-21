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
   Node *temp = cons(t->coeff(), t->degree());

   if (root == nullptr)
   {
      root = temp;
   }
   else
   {
      bool flag = false;
      Node *temp = root;
      while (flag == false)
      {
         if (temp->term->degree() == t->degree())
         {
            int res = temp->term->degree() + t->degree();
            temp->term->setDegree(res);
            flag = true;
         }
         else if (cmp(temp->term->degree(),t->degree()))
         {
            if (temp->left == nullptr)
            {
               temp->left = temp;
               flag = true;
            }
            else
            {
               temp = temp->left;
            }
         }
         else
         {
            if (temp->right == nullptr)
            {
               temp->right = temp;
               flag = true;
            }
            else
            {
               temp = temp->right;
            }
         }
      }
   }
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

   return newPoly;
}

Term Polynomial::degreeSearch(Node* tree, int x){
   
}

// copy constructor
// precondition:
//    p is the Univariate we are copying from
// precondition:
//    p is the Polynomial we are copying from
Polynomial::Polynomial(const Polynomial &p)
{
   cmp = p.cmp;
}

// destructor
Polynomial::~Polynomial()
{
}

// overloaded assignment operator
Polynomial &Polynomial::operator=(const Polynomial &rtSide)
{
   cmp = rtSide.cmp;
}

// postcondition:
//    outputs the polynomial, starting with the highest degree
void Polynomial::printer(Node *tree, std::ostream &out)
{
   if (tree != nullptr)
   {
      printer(tree->right, out);
      if (tree->term->degree() != 0)
      {
         out << tree->term;
      }
      printer(tree->left, out);
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
      in >> degree;
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
