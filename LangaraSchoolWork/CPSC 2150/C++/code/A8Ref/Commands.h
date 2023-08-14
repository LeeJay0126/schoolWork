/* 
Author: Gladys Monagan 
DO NOT POST THIS ANYWHERE.
This code is copyrighted.
Use it exclusively for CPSC 2150 at Langara College in Vancouver
*/
 
#ifndef COMMANDS_H
#define COMMANDS_H

#include <map>        // std::map
#include <iostream>   // std::cout
#include <fstream>    // std::ifstream std::ofstream

// the commands allowed when interacting with the user
enum Commands {
   INPUT,
   PRINT,
   NUMBER,
   CONNECTED,
   FIND_CYCLE,
   LIST_COMPONENTS,
   TWIN,
   PATH,
   RESET,
   MENTION,
   QUIT,
   INVALID
};

// output to out the commands available
void printCommandMenu(std::ostream& out = std::cout);

// make an associative array of the character (that will be obtained from input)
// and its associated command
// postcondition:
//   commands is filled
void buildCommands(std::map<char, Commands>& commands);

// read from input stream in a single word and check if the first
// command to match it to a corresponding value from the enum type Commands
// if echo == true, the command read is echoed out
// postcondition:
//    returns a command from Commands (including INVALID)
Commands getCommand(std::map<char, Commands>& commands, 
   std::istream& in, bool echo, std::ostream& out = std::cout);

// read from input stream in a single word and check if the first
// letter corresponds to 'y' or 'Y' (implying a yes)
// return true if the string read starts with 'y' or 'Y', false otherwise
// if echo == true, the answer read is echoed out
bool yesAnswer(std::istream &in, bool echo = false, std::ostream& out = std::cout);

// reset the input stream (possibly out of its fail state) and clear the buffer
// postcondition:
//    fin is ready to read again
void clearClean(std::istream &fin);

// consume the end-of-line of the previous input stream in
// read a line using in and output it to out if echo == true
void getLineOutputLine(std::istream& in, bool echo, std::ostream& out = std::cout);

#endif

// copyright 2023 Gladys Monagan

