/* 
Author: Gladys Monagan 
DO NOT POST THIS ANYWHERE.
This code is copyrighted.
Use it exclusively for CPSC 2150 at Langara College in Vancouver
*/

#include "Commands.h"
#include <sstream>    // std::stringstream
#include <map>        // std::map
#include <iostream>   // std::cin std::cout 
#include <string>     // std::string
#include <fstream>    // std::ifstream std::ofstream

using std::istream, std::ostream, std::string;
using std::pair;

// output the commands available
void printCommandMenu(ostream& out) {
   out << "\n";
   out << "      ------------- choose a command --------------------------\n";
   out << "(i) - input the file name that contains the graph \n";
   out << "(p) - print the graph\n";
   out << "(n) - number of vertices in the graph\n";
   out << "(c) - determines whether the graph is connected or not\n";
   out << "(f) - find a cycle\n";
   out << "(l) - list the connected components (one set of vertices per line)\n";
   out << "(a) - apath length: calculate a path length between two vertices\n";
   out << "(t) - twin the graph by making a copy\n";
   out << "(r) - reset (or restart) meaning done with this graph\n";
   out << "(m) - mention or comment, the subsequent line is ignored\n";
   out << "(q) - quit the program altogether\n";
   out << "      ---------------------------------------------------------\n"; 
}

// make an associative array of the character (that will be obtained from input)
// and its associated command
void buildCommands(std::map<char, Commands>& commands) {
   commands.insert(pair('i', INPUT));
   commands.insert(pair('p', PRINT));
   commands.insert(pair('n', NUMBER));
   commands.insert(pair('c', CONNECTED));
   commands.insert(pair('f', FIND_CYCLE));
   commands.insert(pair('l', LIST_COMPONENTS));
   commands.insert(pair('a', PATH));
   commands.insert(pair('t', TWIN));
   commands.insert(pair('r', RESET));
   commands.insert(pair('m', MENTION));
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
   static const int MAX_CHARACTERS_IN_BUFFER = 250;
   in.clear();
   in.ignore(MAX_CHARACTERS_IN_BUFFER, '\n');
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
