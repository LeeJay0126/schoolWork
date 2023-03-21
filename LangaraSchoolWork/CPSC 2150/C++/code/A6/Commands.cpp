// Author: Gladys Monagan 
// Process commands.
// Course: CPSC 2150 at Langara College
// Do not post anywhere. This code is copyrighted.

#include "Commands.h"
#include <sstream>    // std::stringstream
#include <map>        // std::map
#include <string>     // std::string
#include <iostream>   // std::cout std::cin
#include <fstream>    // std::ifstream std::ofstream
#include <limits>     // std::numeric_limits<std::streamsize>::max()

using std::istream, std::ostream, std::string, std::pair;

// output the commands available
void printCommandMenu(ostream& out) {
   out << "\n";
   out << "      ------------- choose a command --------------------------\n";
   out << "(i) - input the polynomials a and b\n";
   out << "(s) - sum up the polynomials a and b the polynomial a + b\n";
   out << "(p) - print the polynomials a and b and a + b\n";
   out << "(n) - number of terms in the polynomials a and b and a+b\n";
   out << "(e) - evaluate a, b and a + b at a specific x value\n";
   out << "(c) - coefficient of a term when the term's degree is supplied\n";
   out << "(r) - reset or restart the process with two new polynomials\n";
   out << "(m) - mention or comment, the subsequent line is ignored\n";
   out << "(v) - variable for output is set to a new character\n";
   out << "(d) - differentiate the polynomials a and b\n";
   out << "(q) - quit the program altogether\n";
   out << "      ---------------------------------------------------------\n"; 
}

// make an associative array of the character (that will be obtained from input)
// and its associated command
void buildCommands(std::map<char, Commands>& commands) {
   commands.insert(pair('i', INPUT));
   commands.insert(pair('s', SUM));
   commands.insert(pair('p', PRINT));
   commands.insert(pair('n', NUMBER_OF_TERMS));
   commands.insert(pair('e', EVALUATE));
   commands.insert(pair('c', GET_COEFF));
   commands.insert(pair('r', RESET));
   commands.insert(pair('m', MENTION));
   commands.insert(pair('v', VARIABLE));
   commands.insert(pair('d', DIFFERENTIATE));
   commands.insert(pair('q', QUIT));
}

// read from the input stream a string
// using the first letter of that string,
// retrieve the corresponding pair value which is of the enum type Commands
// if echo is true, the command string read is echoed out
// postcondition:
//    returns a command from Commands (including INVALID)
Commands getCommand(std::map<char, Commands>& commands, 
                    istream& in, bool echo, ostream& out) {
   out << "\ncommand: ";
   string commandStr;
   in >> commandStr;
   std::stringstream ss(commandStr);
   char ch;
   ss >> ch;
   if (echo) out << commandStr << "\n";  // echo what was read
   Commands cmd = INVALID;
   if (commands.find(ch) != commands.end()) cmd = commands[ch];
   return cmd;
}

// return true if the first letter of the string read matches 'y' or 'Y'
// if echo, the answer read is echoed out
bool yesAnswer(istream &in, bool echo, ostream& out) {
   string answerStr;
   in >> answerStr;
   if (echo) out << answerStr << "\n";
   return (answerStr[0] == 'Y' || answerStr[0] == 'y');
}

// reset the input stream (possibly out of its fail state) and clear the buffer
// postcondition:
//    in is ready to read again
void clearClean(istream &in) {
   in.clear();
   in.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

// consume the end-of-line of the input stream
// read a line
// output the line if echo is true
void getLineOutputLine(istream& in, bool echo, ostream& out) {
   string line;
   std::getline(in, line); // consume the end-of-line
   std::getline(in, line);
   if (echo) out << line << "\n";
}

// copyright 2023 Gladys Monagan
