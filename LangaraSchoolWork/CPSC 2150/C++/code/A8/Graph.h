// Name:

//
// CPSC 2150 specifications by Gladys Monagan
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

class Graph
{
public:
   // build an empty graph with no vertices and no edges
   // the only way to add edges or vertices to the graph is with
   // the >> operator which deletes the current graph
   // and reads from an input stream data to build a new one
   Graph();

   // read the number of vertices n
   // read pairs of integers corresponding to an edge in the graph
   // read until "in" fails (i.e. no more data or the data is not an integer)
   // reset "in" and clear the buffer of "in"
   // about the input expected
   //    => all the vertices vi will have values 0 <= vi < numberOfVertices()
   //    => if any of the vertices of the edge (i, j) are not
   //       0 <= i < numberOfVertices() and that 0 <= j < numberOfVertices(),
   //       the edge is not added to the graph
   //    => every undirected edge may only be entered into the list ONCE
   //       if an undirected edge is read twice, it is ignored and not added
   //       to the graph
   // precondition:
   //    "in" is an open stream not in a fail state
   // postcondition:
   //    the data read from a file forms the graph, allocating memory dynamically
   //    and setting the number of vertices internally so that the function
   //    numberOfVertices() returns the number of vertices in the graph
   //    the input stream "in" is not in a fail state
   friend std::istream &operator>>(std::istream &in, Graph &graph);

   // output the graph in a convenient format
   // a possibility is to output a vertex and then its neighbours
   // precondition:
   //    "out" is an open stream not in a fail state
   friend std::ostream &operator<<(std::ostream &out, const Graph &);

   // return the number of vertices in the graph
   int numberOfVertices() const;

   // return true if the graph is connected, false otherwise
   // *****************************************************************
   // CPSC 2150
   // do a breadth first search to determine if the graph is connected
   // *****************************************************************
   bool isConnected() const;

   // return true if the graph has at least one cycle, false otherwise
   bool hasCycle() const;

   // list all the connected components using the output stream "out"
   // each connected component has its vertices in the same line
   // e.g. the output could look like this
   //    0
   //    1 2 4 5 3
   //    6 8 7
   // meaning that there is one connected component with only one vertex 0
   // there is another connected component with the vertices 1 2 4 5 3
   // there is another connected component with the vertices 6 8 7
   // precondition:
   //    "out" is an open stream not in a fail state
   void listComponents(std::ostream &out) const;

   // determine the path length from the vertex 'from' to the vertex 'to'
   // return -1 if 'from' or 'to' are not valid
   //    e.g. not in the range 0 <= from,to < numberOfVertices()
   // return -1 also if there is no path
   int pathLength(int from, int to) const;

   // overloaded assignment operator
   Graph &operator=(const Graph &);

   // copy constructor
   Graph(const Graph &);

   // destructor
   ~Graph();

private:
   // *****************************************************************
   // CPSC 2150
   // use a list of neighbours' graph representation
   // use an array of linked lists
   // you may use the code given in class: simply put as reference "class notes"

   struct Node
   {
      int vertext;
      Node *next;
   };

   bool *marker;

   Node **vertextList;

   int vertices;

   // postcondition:
   //    "in" is not in the fail state and the buffer is cleared
   static void clearClean(std::istream &);
   void recursiveConnect(bool *marker, int s) const;
   bool cycleHelper(int k, bool visited[], int parent) const;
   int getNum(Node *p) const;
   // int boolCount(bool arr[], int n) const;
};

#endif

// copyright 2023 Gladys Monagan`
