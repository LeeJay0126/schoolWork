// Name:

#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for in
#include <ios>    // for declaration of 'streamsize' for in
#include "Graph.h"

Graph::Graph()
{
   marker = NULL;
   vertextList = nullptr;
   vertices = 0;
}

// read the graph by first deleting the current graph if it is not empty
std::istream &operator>>(std::istream &in, Graph &graph)
{
   int n;

   in >> n;

   graph.vertices = n;
   graph.marker = new bool[n];

   for (int i = 0; i < n; i++)
   {
      graph.marker[i] = false;
   }

   graph.vertextList = new Graph::Node *[n];
   for (int i = 0; i < n; i++)
   {
      graph.vertextList[i] = nullptr;
   }

   int destination;
   int start;
   bool flag;

   for (int i = 0; i < n; i++)
   {
      in >> start;
      in >> destination;

      flag = false;

      if (graph.vertextList[start] == nullptr)
      {
         graph.vertextList[start] = new Graph::Node{destination, nullptr};
      }
      else
      {
         Graph::Node *temp = graph.vertextList[start];
         while (temp->next != nullptr)
         {
            if (temp->vertext == destination)
            {
               flag = true;
            }
            temp = temp->next;
         }
         if (flag == false)
         {
            Graph::Node *newNode = new Graph::Node{destination, nullptr};
            temp->next = newNode;
         }
      }

      if (graph.vertextList[destination] == nullptr)
      {
         graph.vertextList[destination] = new Graph::Node{start, nullptr};
      }
      else
      {
         if (flag == false)
         {
            Graph::Node *temp = graph.vertextList[destination];
            while (temp->next != nullptr)
            {
               temp = temp->next;
            }

            Graph::Node *newNode = new Graph::Node{start, nullptr};
            temp->next = newNode;
         }
      }
   }

   Graph::clearClean(in);
   // might want to call
   // clearClean(in);
   // either here or in a helper function
   return in;
}

std::ostream &operator<<(std::ostream &out, const Graph &graph)
{
   int n = graph.numberOfVertices();
   Graph::Node *temp;

   for (int i = 0; i < n; i++)
   {
      temp = graph.vertextList[i];
      if (temp != nullptr)
      {
         out << temp->vertext << "     ";
         while (temp != nullptr)
         {
            out << temp->vertext << " ";
         }
         out << std::endl;
      }
   }

   return out;
}

int Graph::numberOfVertices() const
{
   return vertices;
}

// *****************************************************************
// CPSC 2150
// do a breadth first search to determine if the graph is connected
// *****************************************************************
bool Graph::isConnected() const
{

}



bool Graph::hasCycle() const
{
}

void Graph::listComponents(std::ostream &out) const
{
}

int Graph::pathLength(int from, int to) const
{
}

// postcondition:
//    deep copy the rtSide
Graph &Graph::operator=(const Graph &rtSide)
{

   return *this;
}

// other is the Graph we are copying from
// postcondition:
//    the instance variables are initialized using other
Graph::Graph(const Graph &other)
{
}

// destructor frees up the memory on the heap
Graph::~Graph()
{
}

//==============================================================================
//   utility functions
//==============================================================================

// get stream out of the fail state and clear the buffer
// done for you
// call in the input operator >>
void Graph::clearClean(std::istream &in)
{
   in.clear();
   in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// copyright 2023 Gladys Monagan
