/* 
 Program to use (test) graph algorithms.
 Commands supported 
 -> input the file name that contains the graph
 -> output the graph
 -> output the number of vertices in the graph
 -> determine if the graph is connected
 -> find a cycle
 -> list all the connected components of the graph
 -> copy the graph and manipulate the copy (the twin)
 -> calculate the path length from a vertex to another vertex

 usage: doGraph -batch < cmds.txt > output.txt
 runs the program non-interactively obtaining data from cmds.txt
 and putting the output into output.txt

 usage: doGraph
 renders an interactive session with commands

 Author: Gladys Monagan
 DO NOT POST THIS ANYWHERE.
 This code is copyrighted.
 Use it exclusively for CPSC 2150 at Langara College in Vancouver
*/
#include <fstream>
#include <string>
#include <iostream>
#include <map>       // std::map
#include "Commands.h"
#include "Graph.h"

using std::string;

// process the commands
// we need to pass commands because they are needed in makeTwinNCommand
bool process(std::istream& in, Commands cmd, std::map<char, Commands>& commands,
             Graph& graph, bool echo, std::ostream& out=std::cout);

// read from "in" the file name of the undirected simple graph
// if the file CAN be opened, read the graph from that file
// precondition:
//    the graph input file has an integer n for the number of vertices such
//    that every vertex v is 0 <= v < n
//    following the number of vertices n,  
//    there are pairs of integers corresponding to edges (i, j) 
//    such that 0 <= i < n and 0 <= i < n
//    the edges are undirected 
// postcondition: 
//    the graph with the data if reading was successful
//    the input stream "in" is cleared if an error was encountered
//    return true if the graph was read successfully, false otherwise
bool inputGraph(std::istream& in, Graph& graph, 
                bool echo, std::ostream& out=std::cout) {
   bool success = true;
   string fileName;
   out << "enter the file name that has the graph: ";
   in >> fileName;
   if (echo) out << fileName << "\n";
   std::ifstream fin;
   fin.open(fileName);
   if (!in.good() || (!fin.good()) ) {
      out << "ERROR in reading/opening the graph file \"" << fileName << "\"\n";
      clearClean(in);
      success = false;
   }
   else {
      fin >> graph;
      fin.close();
   }
   return success;
}

// make a copy of graph using the copy constructor
// test that some properties are the same and call a few commands on it
// the destructor is implicitly called once 'other' goes out of scope
// to get out of the "twin mode", a normal RESET is needed
void makeTwinNCommand(std::istream& in, Graph& graph, 
                      std::map<char, Commands>& commands,
                      bool echo, std::ostream& out=std::cout) {
   Graph other = graph;
   if ( (other.hasCycle() != graph.hasCycle()) || 
        (other.isConnected() != graph.isConnected()) ){
      out << "ERROR: twin is not identical to graph\n";
      return;
   }
   bool done = false;
   do {
      out << "\nfor twin graph ";
      Commands cmd = getCommand(commands, in, echo, out);
      done = process(in, cmd, commands, graph, echo, out);
   } while (!done);
}

// calculate the path length between two vertices which are obtained using "in"
void pathLength(std::istream& in, Graph& graph,
               bool echo, std::ostream& out=std::cout) {
   out << "enter the starting vertex and the destination vertex: ";
   int vStart, vDest;
   in >> vStart >> vDest;
   if (!in.good()) {
      out << "ERROR the starting vertex and destination vertex must be numeric\n";
      clearClean(in);
      return;
   }
   if (echo) {
      out << "\n     source vertex = " << vStart;
      out << "\ndestination vertex = " << vDest << "\n";
   }
   out << "path length from vertex " << vStart << " to vertex " << vDest << " is ";
   out << graph.pathLength(vStart, vDest);
   out << "\n";
}

// call the various functions to do what is needed
bool process(std::istream& in, Commands cmd, std::map<char, Commands>& commands,
             Graph& graph, bool echo, std::ostream& out) { 
   bool doneProcessing = false;
   switch (cmd) {
      case INPUT:
         if (!inputGraph(in, graph, echo, out)) 
            out << "enter the graph file name again!\n";
         break;
      case PRINT:
         out << graph;
         break;
      case NUMBER:
         out << "the graph has " << graph.numberOfVertices() << " vertices\n";
         break;
      case CONNECTED:
         out << "the graph is ";
         if (!graph.isConnected()) out << "NOT ";
         out << "connected\n";
         break;
      case FIND_CYCLE:
         if (graph.hasCycle()) 
            out << "the graph has at least one cycle\n";
         else
            out << "no cycles\n";
         break;
      case LIST_COMPONENTS:
         graph.listComponents(out);
         break;
      case PATH:
         pathLength(in, graph, echo, out);
         break;
      case TWIN:
         makeTwinNCommand(in, graph, commands, echo, out);
         break;
      case MENTION:
         getLineOutputLine(in, echo, out);
         break;
      case RESET:
      case QUIT:
         doneProcessing = true;
         break;
      case INVALID:
         out << "invalid command, please input again!\n";
         break;
      default:
         std::cerr << "**** ERROR in the switch of process ***\n";
         break;
   }
   return doneProcessing;
}

// determine if the "-batch" option was entered meaning that the
// session is NOT interactive and the input will be echoed
// return true if the string matches -batch, false otherwise
bool echoOption(string option) {
   return option == "-batch";
} 

// if the session is interactive, echo the input
// right now input is from std::cin and output from std::out
int main(int argc, char* argv[]) {
   bool echo = false;
   if (argc > 1) {
      echo = echoOption(argv[1]);
   }
   std::map<char, Commands> commands;
   buildCommands(commands);

   std::istream& in = std::cin;
   std::ostream& out = std::cout;
   Commands cmd;
   do {
      if (!echo) printCommandMenu(out);
      bool done = false;
      Graph graph; 
      do {
         cmd = getCommand(commands, in, echo, out);
         done = process(in, cmd, commands, graph, echo, out);
      } while (!done); 
   } while (cmd != QUIT); 
   return 0;
}

// copyright 2023 Gladys Monagan
