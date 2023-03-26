// Author: Gladys Monagan 
// A polynomial term
// Course: CPSC 2150 at Langara College
// Do not post anywhere. This code is copyrighted.

#include <iostream> 
#ifndef TERM_H
#define TERM_H
class Term {
   public:
      // create a term with the given coefficient c and degree d
      // the variable (for output) is initialized to 'x'
      Term(int c, int d);

      // return the term's coefficient
      int coeff() const;

      // return the term's degree
      int degree() const;
      
      // return the variable used for output
      static char variable();

      // set the term's coefficient to c
      void setCoeff(int c);

      // set the term's degree to d
      void setDegree(int d);

      // set the variable used for output to ch
      static void setVariable(char ch);
   private:
      int c;
      int d;
      static char var; // variable used for output
};

// output the term
// CPSC 2150: use this operator to output the Term
std::ostream& operator << (std::ostream&, const Term&);

#endif

// copyright 2023 Gladys Monagan
