// Name:

#include <iostream>
#include <limits> // for declaration of 'numeric_limits' for in
#include <ios>    // for declaration of 'streamsize' for in
#include "Graph.h"
#include <queue>

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

   if (!in.fail())
   {
      while (in >> start >> destination)
      {
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
      if (temp != nullptr)
      {
         out << i << "     ";
         while (temp != nullptr)
         {
            out << temp->vertext << " ";
            temp = temp->next;
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
   int n = vertices;
   if (vertices <= 2)
   {
      return true;
   }

   for (int i = 0; i < n; i++)
   {
      if (vertextList[i] == nullptr)
      {
         return false;
      }
   }
   Graph::recursiveConnect(marker, 0);

   bool isConnected = true;
   for (int i = 0; i < n; i++)
   {
      if (marker[i] == false)
      {
         isConnected = false;
      }
   }

   for (int i = 0; i < n; i++)
   {
      marker[i] = false;
   }

   return (isConnected);
}

void Graph::recursiveConnect(bool *marker, int s) const
{
   marker[s] = true;
   std::queue<int> que;
   que.push(s);

   while (!que.empty())
   {
      int i = que.front();
      que.pop();
      int o = Graph::getNum(vertextList[i]);
      Node *temp = vertextList[i];
      for (int k = 0; k < o; k++)
      {
         if (!marker[temp->vertext])
         {
            marker[temp->vertext] = true;
            que.push(temp->vertext);
         }
         temp = temp->next;
      }
   }
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
   if (vertices < 2 || vertextList == nullptr)
   {
      return false;
   }

   int parent = -1;
   bool *visited = new bool[vertices];

   for (int i = 0; i < vertices; i++)
   {
      visited[i] = false;
   }

   for (int k = 0; k < vertices; k++)
   {
      if (!visited[k])
      {
         if (cycleHelper(k, visited, parent))
         {
            return true;
         }
      }
   }
   return false;
}

bool Graph::cycleHelper(int k, bool visited[], int parent) const
{
   visited[k] = true;
   Node *temp = vertextList[k];
   while (temp != nullptr)
   {
      int p = temp->vertext;
      if (!visited[p])
      {
         if (cycleHelper(p, visited, k))
         {
            return true;
         }
         else if (visited[p] == true && p != parent)
         {
            return true;
         }
      }
      temp = temp->next;
   }
   return false;
}

void Graph::listComponents(std::ostream &out) const
{
   int *arr = new int[vertices];
   for (int i = 0; i < vertices; i++)
   {
      arr[i] = i;
   }
   int total = 0;
   for (int i = 0; i < vertices; i++)
   {
      if (marker[i] == false)
      {
         recursiveConnect(marker, i);
         // int q = boolCount(marker, vertices);
         for (int t = 0; t < vertices; t++)
         {
            if (marker[t] != NULL && arr[t] != -1)
            {
               out << t << " ";
               arr[t] = -1;
               // gotta find a way to print , after each print except for the last one (new arrays?)
            }
         }
         out << "\n";
      }
   }
}

// int Graph::boolCount(bool arr[], int n) const
// {
//    int res = 0;
//    for (int i = 0; i < n; i++)
//    {
//       if (arr[i] == false)
//       {
//          res += 1;
//       }
//    }
//    return res;
// }

int Graph::pathLength(int from, int to) const
{
}

// postcondition:
//    deep copy the rtSide
Graph &Graph::operator=(const Graph &rtSide)
{
   vertextList = rtSide.vertextList;
   marker = rtSide.marker;
   vertices = rtSide.vertices;

   return *this;
}

// other is the Graph we are copying from
// postcondition:
//    the instance variables are initialized using other
Graph::Graph(const Graph &other)
{
   vertices = other.vertices;
   marker = new bool[vertices];
   vertextList = new Node *[vertices];

   for (int i = 0; i < vertices; i++)
   {
      if (other.vertextList[i] != nullptr)
      {
         Node *temp = other.vertextList[i];
         Node *newNode = new Node{temp->vertext, nullptr};
         vertextList[i] = newNode;
         temp = temp->next;
         Node *q = newNode;
         while (temp != nullptr)
         {
            Node *t = new Node{temp->vertext, nullptr};
            q->next = t;
            temp = temp->next;
            q = q->next;
         }
      }
   }
}

// destructor frees up the memory on the heap
Graph::~Graph()
{
   if (vertextList != nullptr)
   {
      for (int i = 0; i < vertices; i++)
      {
         if (vertextList[i] != nullptr)
         {
            Node *temp = vertextList[i];
            while (temp != nullptr)
            {
            }
         }
      }
   }
   vertices = 0;
   delete[] marker;
   marker = NULL;
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
