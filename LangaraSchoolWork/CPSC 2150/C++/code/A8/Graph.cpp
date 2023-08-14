// Name:

#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for in
#include <ios>    // for declaration of 'streamsize' for in
#include "Graph.h"
#include <queue>

Graph::Graph()
{
   vertices = 0;
   vertextList = nullptr;
}

Graph::Node *Graph::cons(int vert)
{
   Node *newNode = new Node{vert, nullptr};
   return newNode;
}

// read the graph by first deleting the current graph if it is not empty
std::istream &operator>>(std::istream &in, Graph &graph)
{
   int n;
   in >> n;
   graph.vertices = n;
   graph.vertextList = new Graph::Node *[n];
   Graph::Node **v = graph.vertextList;

   for (int i = 0; i < n; i++)
   {
      v[i] = nullptr;
   }

   if (!in.fail())
   {
      int start;
      int destination;

      while (in >> start >> destination)
      {
         // storing the value for the first number
         if (v[start] == nullptr)
         {
            v[start] = graph.cons(destination);
         }
         else
         {
            Graph::Node *t = v[start];
            while (t->next != nullptr && t->vertext != destination)
            {
               t = t->next;
            }
            if (t->vertext != destination)
            {
               t->next = graph.cons(destination);
            }
         }
         // storing the value for the second number
         if (v[destination] == nullptr)
         {
            v[destination] = graph.cons(start);
         }
         else
         {
            Graph::Node *t = v[destination];
            while (t->next != nullptr && t->vertext != start)
            {
               t = t->next;
            }
            if (t->vertext != start)
            {
               t->next = graph.cons(start);
            }
         }
      }
   }

   Graph::clearClean(in);
   in.ignore();
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
      out << i << "     ";
      if (temp != nullptr)
      {
         out << temp->vertext << "  ";
         temp = temp->next;
      }
      out << std::endl;
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
   int n = vertices;
   bool *marker = new bool[n];

   for (int i = 0; i < n; i++)
   {
      if (vertextList[i] == nullptr)
      {
         return false;
      }
   }

   // if (n < 2)
   // {
   //    return true;
   // }

   for (int i = 0; i < n; i++)
   {
      marker[i] = false;
   }

   std::queue<int> que;

   for (int i = 0; i < n; i++)
   {
      que.push(i);

      while (!que.empty())
      {
         int k = que.front();
         que.pop();
         if (!marker[k])
         {
            marker[k] = true;
            int o = getNum(vertextList[k]);
            Node *p = vertextList[k];
            for (int i = 0; i < o; i++)
            {
               que.push(p->vertext);
            }
            p = p->next;
         }
      }
   }

   for (int i = 0; i < n; i++)
   {
      if (marker[i] == false)
      {
         return false;
      }
   }

   return true;
}

int Graph::getNum(Node *p) const
{
   int res = 0;
   while (p != nullptr)
   {
      res += 1;
      p = p->next;
   }
   return res;
}

bool Graph::hasCycle() const
{
   bool *marker = new bool[vertices];
   for (int i = 0; i < vertices; i++)
   {
      marker[i] = false;
   }
   bool cycleFlag = false;
   for (int i = 0; i < vertices; i++)
   {
      if (vertextList[i] != nullptr)
      {
         cycleFlag = cycleHelper(marker, i);
         if (cycleFlag)
         {
            return true;
         }
      }
   }
   return false;
}

bool Graph::cycleHelper(bool *marker, int parent) const
{
   if (marker[parent] == false)
   {
      marker[parent] = true;
      std::queue<int> que;
      que.push(parent);
      while (!que.empty())
      {
         int o = que.front();
         que.pop();
         if (!marker[o])
         {
            marker[o] = true;
            parent = o;
            int k = getNum(vertextList[o]);
            Node *p = vertextList[o];
            for (int i = 0; i < k; i++)
            {
               if (marker[p->vertext] == true && p->vertext != parent)
               {
                  return true;
               }
               else
               {
                  que.push(p->vertext);
                  p = p->next;
               }
            }
         }
      }
   }
   return false;
}

void Graph::listComponents(std::ostream &out) const
{
}

int Graph::pathLength(int from, int to) const
{
}

Graph &Graph::operator=(const Graph &rtSide)
{
}

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
