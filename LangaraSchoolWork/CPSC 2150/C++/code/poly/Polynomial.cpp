// Name: 

// Represents a univariate polynomial using a binary search tree
// Course: CPSC 2150

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <functional>   // std::function

#include "Term.h"
#include "Polynomial.h"

// create the zero polynomial 
// CPSC 2150
// initializing the comparison function between term degrees done for you
Polynomial::Polynomial(std::function<bool(int, int)> fct) : cmp(fct) {

}


bool Polynomial::isZeroPolynomial() const { 


}

// postcondition: 
//    a Polynomial with one term c x^d is created
//    c becomes the coefficient of the only term in the polynomial
//    d becomes the degree of the only term in the polynomial
Polynomial::Polynomial(int c, int d, std::function<bool(int, int)> fct) {
   cmp = fct; // a different way of initializing the instance variable cmp


}

// precondition:
//   the term pointed to by t has been allocated 
//   t != nullptr
// postcondition:
// 
void Polynomial::insert(Term* t) {


}

// postcondition: 
//    returns the highest degree of the polynomial
//    in the special case of the zero polynomial, return -1 
int Polynomial::degree() const {


}


// postcondition: 
//    returns the coefficient of term that has degree n
int Polynomial::coefficient(int n) const {


}

// postcondition: 
//    returns the number of terms in the tree
//    in the special case of the zero polynomial return 1
int Polynomial::numberOfTerms() const {


}

// postcondition: 
//    returns the value of evaluating the polynomial at x
double Polynomial::evaluate(double x) const {



}

// precondition:
//    a and b are the two polynomials to sum up,
// postcondition: 
//    create a new polynomial which is the sum of two given polynomials
//    only the non-zero terms will be stored in the sum polynomial 
const Polynomial Polynomial::operator + (const Polynomial& b) {



}


// copy constructor
// precondition:
//    p is the Univariate we are copying from
// precondition:
//    p is the Polynomial we are copying from
Polynomial::Polynomial(const Polynomial& p) {
   cmp = p.cmp;


}

// destructor
Polynomial::~Polynomial() {


}

// overloaded assignment operator
Polynomial& Polynomial::operator = (const Polynomial& rtSide) {


}






// postcondition:     
//    outputs the polynomial, starting with the highest degree
std::ostream& operator << (std::ostream& out, const Polynomial& p) {



   return out;
}

// postcondition: 
//    if non numeric input is given, the istream enters a fail state
//    only non-zero terms will be inserted into the polynomial
std::istream& operator >> (std::istream& in, Polynomial& poly) {
   // int n;
   // input the number of non-zero terms n of the polynomial: ";
   // in >> n;
   // get the degree and coefficient of every term
   // for (int i = 0; i < n; i++) {

   // }


   return in;
}

// BONUS
// postcondition:
//    returns a new polynomial with the differentiated polynomial
const Polynomial Polynomial::differentiate() const {
   // dummy return value for NOW
   return Polynomial(cmp);
}


// return the variable used for output
// CPSC 2150: nothing to do
char Polynomial::variable() {
   return Term::variable();
}

// set the variable used for output to ch
// CPSC 2150: nothing to do
void Polynomial::setVariable(char ch) {
   Term::setVariable(ch);
}
