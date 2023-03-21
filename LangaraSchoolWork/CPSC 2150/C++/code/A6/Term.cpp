// Author: Gladys Monagan 
// A polynomial term
// Course: CPSC 2150 at Langara College
// Do not post anywhere. This code is copyrighted.

#include "Term.h"
#include <iostream> // std::ostream

// initialize the static variable var to 'x'
char Term::var = 'x';

Term::Term(int coefficient, int degree): c(coefficient), d(degree) {
}

int Term::coeff() const {
   return this->c;
}

void Term::setCoeff(int c) {
   this->c = c;
}

int Term::degree() const {
   return this->d;
}

void Term::setDegree(int d) {
   this->d = d;
}

char Term::variable() {
   return var;
}

void Term::setVariable(char ch) {
   var = ch;
}

std::ostream& operator << (std::ostream& out, const Term& t) {
   int c = t.coeff();
   int d = t.degree();
   if (c > 0) {
      out << " + ";
   }
   else if (c < 0) {
      out << " - ";
      c *= -1;
   }
   if (c != 1 || d == 0) {
      out << c;
   }
   if (d == 1) {
      out << t.variable();
   }
   else if (d != 0) {
      out << t.variable() << "^" << d;
   }
   return out;
}

// copyright 2023 Gladys Monagan
