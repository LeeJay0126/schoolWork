// Program to use (test) univariate polynomials with a user interface. 
// Commands supported 
// -> input two polynomials
// -> calculate their sum
// -> get the coefficients of the terms
// -> get the degree of the polynomial
// -> evaluate the polynomial given a specific value for x
// -> get the number of terms in the polynomial
// -> change the variable used in outputting the polynomial
// -> possibly differentiate
// usage: polyMath -batch < inFile.txt > outFile.txt
// runs the program non-interactively obtaining data from inFile.txt
// and putting the output into outFile.txt
//
// usage: polyMath
// renders a command driver interactive session

// Author: Gladys Monagan
// DO NOT POST THIS ANYWHERE.
// This code is copyrighted.
// Use it exclusively for CPSC 2150 as an assignment at Langara College

#include "Polynomial.h"
#include "Commands.h"
#include <functional> // std::greater
#include <map>        // std::map
#include <iostream>   // std::istream, std::ostream, std::cout;
#include <string>     // std::string

using std::istream, std::ostream, std::cout, std::string;

// output a polynomial with its label
// precondition:
//    the operator << has been overloaded for Polynomial
void printPoly(const string& label, const Polynomial& p, ostream& out=cout) {
   out << label << " = " << p << "\n";
}

// output the polynomial's degree with its label
void printDegree(const string& label, const Polynomial& p, ostream& out=cout) {
   out << "degree of " << label << " = " << p.degree() << "\n";
}

// output the polynomials
// precondition:
//    aPoly, bPoly are bona fide polynomials 
//    (including the zero polynomial)
void printPolys(const Polynomial& aPoly,const Polynomial& bPoly,ostream& out=cout){
   printPoly("a", aPoly, out);
   printPoly("b", bPoly, out);
   printDegree("a", aPoly);
   printDegree("b", bPoly);
}

// this is a BONUS in the assignment
// differentiate and print the differentiated polynomials
// precondition:
//    the copy constructor has been implemented properly
//    the destructor has been implemented properly
void differentiate(const Polynomial& aPoly,const Polynomial& bPoly,ostream& out=cout) {
   Polynomial aDPoly = aPoly.differentiate();
   Polynomial bDPoly = bPoly.differentiate();
   printPoly("da/dx", aDPoly, out);
   printPoly("db/dx", bDPoly, out);
}

// print the coefficient and an explanation
void printCoeffDegree(string label, int coeff, int degree, ostream& out=cout) {
   out << "in " << label << ", " << coeff;
   out << " is the coefficient of the term of degree " << degree << "\n";
}

// print the polynomials aPoly, bPoly and their sumPoly 
// precondition:
//    aPoly, bPoly and sumPoly are bona fide polynomials 
//    (including the zero polynomial)
//    the operator << has been overloaded for Polynomial
void printPolys(const Polynomial& aPoly, const Polynomial& bPoly, 
                const Polynomial& sumPoly, ostream& out=cout) {
   printPoly("a", aPoly, out);
   printPoly("b", bPoly, out);
   printPoly("a+b", sumPoly, out);
   printDegree("a", aPoly, out);
   printDegree("b", bPoly, out);
   printDegree("a+b", sumPoly, out);
}

// output the number of terms of the aPoly, bPoly and sumPoly if validSum
// validSum means that sumPoly is a valid polynomial
// precondition:
//    aPoly, bPoly, sumPoly are bona fide polynomials 
//    (including the zero polynomial)
//    the operator << has been overloaded for Polynomial
void numberOfTerms(const Polynomial& aPoly, const Polynomial& bPoly, 
                   const Polynomial& sumPoly, bool validSum, ostream& out=cout){
   out << aPoly.numberOfTerms() << " term(s) in a = " << aPoly << "\n";
   out << bPoly.numberOfTerms() << " term(s) in b = " << bPoly << "\n";
   if (validSum) {
      out << sumPoly.numberOfTerms();
      out << " term(s) in sum = " << sumPoly<<"\n";
   }
}

// read in the info on the first polynomial (polynomial aPoly)
// if successful, read in the info on the second polynomial (polynomial bPoly)
// expected for each polynomial is
// -> the number of terms
// -> pairs of numbers for to the coefficient of the term and the degree
// precondition:
//    aPoly, bPoly, sumPoly are the zero polynomials
//    the operator >> has been implemented properly for Polynomial
//    the operator << has been implemented properly for Polynomial
//    reading into a polynomial consists of
//        an integer n for the number of terms
//        coefficient degree pairs n times    
// postcondition: 
//    aPoly, bPoly are bona fide polynomials 
//    the input stream in is cleared in case of having entered the fail state
bool inputPolynomials(std::istream& in, Polynomial& aPoly, 
                      Polynomial& bPoly, ostream& out=cout) {
   bool successfulRead = true;
   out << "for polynomial a, enter # of terms,";
   out << " then \"coefficient degree\" pairs:\n";
   if (!(in >> aPoly)) {
      out << "ERROR in reading polynomial a\n";
      successfulRead = false;
   }
   clearClean(in);
   if (successfulRead) {
      out << "for polynomial b, enter # of terms,";
      out << " then \"coefficient degree\" pairs:\n";
      if (!(in >> bPoly)) {
         out << "ERROR in reading polynomial b\n";
         successfulRead = false;
      }
   }
   clearClean(in);
   return successfulRead;
}

// read in the degree of the term whose coefficients will be printed
// for aPoly, bPoly and sumPoly (if validSum is true)
// if validSum is true, that means that sumPoly is valid
// if echo is true, the degree read is echoed out
// postcondition:
//    the input stream is cleared in case of having entered the fail state
void getCoeffs(istream &in, const Polynomial& aPoly, const Polynomial& bPoly, 
               const Polynomial& sumPoly, bool validSum, bool echo,
               ostream& out=cout) {
   do {
      int degree;
      out << "enter the degree of a term whose coefficient is needed ";
      in >> degree;
      if (echo) out << degree << "\n";
      printCoeffDegree("a", aPoly.coefficient(degree), degree);
      printCoeffDegree("b", bPoly.coefficient(degree), degree);
      if (validSum) printCoeffDegree("a+b", sumPoly.coefficient(degree), degree);
      out << "continue getting coefficients? (y/n): ";
   } while (yesAnswer(in, echo, out));
   clearClean(in);
}

// read a new variable and change it so that output uses that variable
// for aPoly, bPoly and sumPoly (if validSum is true)
// if validSum is true, that means that sumPoly is valid
// if echo is true, the variable read is echoed out
// postcondition:
//    the input stream is cleared in case of having entered the fail state
void changeVariable(istream &in, Polynomial& aPoly, Polynomial& bPoly, 
               Polynomial& sumPoly, bool validSum, bool echo,
               ostream& out=cout) {
   char var;
   out << "enter the character that will be used as variable ";
   in >> var;
   if (echo) out << var << "\n";
   clearClean(in);
   aPoly.setVariable(var);
   bPoly.setVariable(var);
   printPoly("a", aPoly, out);
   printPoly("b", bPoly, out);
   if (validSum) {
      sumPoly.setVariable(var);
      printPoly("a+b", sumPoly, out);
   }
}

// read x to use in evaluating the polynomials
// evaluate aPoly, bPoly and sumPoly (if validSum is true) at the given x 
// and output the results
// if validSum is true, that means that sumPoly is valid
// if echo is true, the degree read is echoed out
// postcondition:
//    the input stream is cleared in case of having entered the fail state
void evalPolys(istream &in, const Polynomial& aPoly, const Polynomial& bPoly, 
               const Polynomial& sumPoly, bool validSum, bool echo,
               ostream& out=cout) {
   do {
      double x;
      out << "enter the value of x: ";
      in >> x;
      if (echo) out << x << "\n";
      out << "when x = " << x << "\n";
      out << "a = " << aPoly << " = " << aPoly.evaluate(x) << "\n";
      out << "b = " << bPoly << " = " << bPoly.evaluate(x) << "\n";
      if (validSum) out << "a+b = " << sumPoly << " = " << sumPoly.evaluate(x) << "\n";
      out << "evaluate for another value of x? (y/n) : ";
   } while (yesAnswer(in, echo, out));
   clearClean(in);
}

// process the command 
//   read in aPoly and bPoly 
//   compute the polynomial which is the sum of aPoly and bPoly
//   print aPoly, bPoly and sumPoly
//   evaluate aPoly, bPoly and sumPoly asking the user for the value of x
//   get the coefficients of terms in aPoly, bPoly and sumPoly 
//   get the number of terms in aPoly, bPoly and sumPoly
//   print if an error was made
//   read a comment (or document) and print it if echo is true
// precondition:
//    the copy constructor has been implemented properly
//    the overloaded assignment operator has been implemented properly
//    the destructor has been implemented properly
//    the operator >> has been implemented properly for Polynomial
//    the operator << has been implemented properly for Polynomial
// postcondition:
//   return true when the command is RESET or QUIT, return false otherwise
//   validSum is set to true if the command SUM is executed
// 
bool process(istream& in, Commands command, Polynomial& aPoly, 
             Polynomial& bPoly, Polynomial& sumPoly, bool& validSum,
             bool echo, ostream& out=cout) {
   bool doneProcessing = false;
   switch (command) {
      case INPUT:
         if (inputPolynomials(in, aPoly, bPoly, out)) 
            printPolys(aPoly, bPoly, out);
         break;
      case SUM:
         validSum = true;
         sumPoly = aPoly + bPoly;
         printPolys(aPoly, bPoly, sumPoly, out);
         break;
      case PRINT:
         validSum ? printPolys(aPoly, bPoly, sumPoly, out) : 
                    printPolys(aPoly,bPoly, out);
         break;
      case EVALUATE:
         // ask for the values of x and evaluate the polynomials
         evalPolys(in, aPoly, bPoly, sumPoly, validSum, echo, out);
         break;
      case GET_COEFF:
         // ask for the degree of the term whose coefficient will be returned
         getCoeffs(in, aPoly, bPoly, sumPoly, validSum, echo, out);
         break;
      case NUMBER_OF_TERMS:
         // output the number of terms of each polynomial
         numberOfTerms(aPoly, bPoly, sumPoly, validSum, out);
         break;
      case RESET:
         // will be used to restart the process eliminating the polynomials
         doneProcessing = true;
         break;
      case MENTION:
         // read and write a line (do nothing else)
         getLineOutputLine(in, echo, out);
         break;
      case VARIABLE:
         changeVariable(in, aPoly, bPoly, sumPoly, validSum, echo, out);
         break;
      case DIFFERENTIATE:
         differentiate(aPoly, bPoly, out);
         break;
      case QUIT:
         // the task is done
         doneProcessing = true;
         break;
      case INVALID:
         out << "invalid command, please input again!\n";
         break;
      default:
         std::cerr << "**** ERROR in the switch of process ***\n";
         std::cerr << "contact author\n";
         break;
   } // switch
   return doneProcessing;
}

// determine if the "-batch" option was entered meaning that the
// session is NOT interactive and the input will be echoed
// return true if the string matches -batch, false otherwise
bool echoOption(string option) {
   return option == "-batch";
} 

// the tree is built "in descending order"
// used for the search key of the tree which is the degree of a term
// Functor is a plain bad name as to what code is being hidden here but
// the name was chosen for didactic purposes
struct Functor {
   bool operator() (int a, int b) const {
      return a > b;
   }
};

// if the session is interactive, echo the input
// for each pair of polynomials read, process the command and 
// finish once the command is quit
// right now input is from std::cin and output from std::out
int main(int argc, char* argv[]) {
   bool echo = false;
   // find if -batch is an option using the line argument
   if (argc > 1) {
      echo = echoOption(argv[1]);
   }
   std::map<char, Commands> commands;
   buildCommands(commands);

   istream& in = std::cin;
   ostream& out = std::cout;
   Commands cmd;
   do {
      if (!echo) printCommandMenu(out);

      // process two polynomials (and their sum) 
      bool doneWithPolys = false;
      // we want the polynomial in descending order on degree of a term
      // use a lambda function 
      Polynomial aPoly([](int a, int b) -> bool {return a > b;});
      // we want the polynomial in descending order on degree of a term
      // with a default STL function
      Polynomial bPoly((std::greater<int>()));
      // we want the polynomial in descending order on degree of a term
      // with a functor or function object
      Functor descending;
      Polynomial sumPoly(descending);

      bool validSum = false; // set to true when the command is SUM
      do {
         cmd = getCommand(commands, in, echo, out);
         doneWithPolys = process(in, cmd, aPoly, bPoly,sumPoly, validSum,echo,out);
      } while (!doneWithPolys); 
      // will call destructors
   } while (cmd != QUIT); 
   return 0;
}

// copyright 2023 Gladys Monagan

