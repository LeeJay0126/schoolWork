// Name:


#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for in
#include <ios>    // for declaration of 'streamsize' for in
#include "Graph.h"

Graph::Graph() {

}

// read the graph by first deleting the current graph if it is not empty
std::istream& operator >> (std::istream& in, Graph& graph) {


   // might want to call 
   // clearClean(in);
   // either here or in a helper function
   return in;
}

std::ostream& operator << (std::ostream& out, const Graph& graph) {
   



   return out;
}


int Graph::numberOfVertices() const {

}


// *****************************************************************
// CPSC 2150
// do a breadth first search to determine if the graph is connected
// *****************************************************************
bool Graph::isConnected() const {
 
}

bool Graph::hasCycle() const {
 
}

void Graph::listComponents(std::ostream& out) const {

}


int Graph::pathLength(int from, int to) const {


}

// postcondition:
//    deep copy the rtSide 
Graph& Graph::operator = (const Graph& rtSide) {
 
   return *this;
}

// other is the Graph we are copying from
// postcondition: 
//    the instance variables are initialized using other
Graph::Graph(const Graph& other) {
   
}

// destructor frees up the memory on the heap
Graph::~Graph() {

}

//==============================================================================
//   utility functions
//==============================================================================

// get stream out of the fail state and clear the buffer
// done for you
// call in the input operator >> 
void Graph::clearClean(std::istream& in) {
   in.clear();
   in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
}

// copyright 2023 Gladys Monagan

