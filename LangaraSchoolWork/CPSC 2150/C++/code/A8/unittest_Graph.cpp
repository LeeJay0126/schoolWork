/* 
Author: Gladys Monagan 
DO NOT POST THIS ANYWHERE.
This code is copyrighted.
Use it exclusively for CPSC 2150 at Langara College in Vancouver

do NOT run neither pathLengthTest nor listComponentTest
./Graph_unittest --gtest_filter="-pathLengthTest.*:listComponentTest.*"

./Graph_unittest --gtest_filter="copyConstructorTest.*"

./Graph_unittest --gtest_filter="overloadedAssgnOperatorTest.*"

to run all the tests and do NOT run the pathLengthTest (note the minus sign)
./Graph_unittest --gtest_filter="-pathLengthTest.*"

all the tests for the pathLengthTest exclusively
./Graph_unittest --gtest_filter="pathLengthTest.*"
*/

#include "Graph.h"
#include "gtest/gtest.h"

#include <iostream>
using std::cout, std::endl, std::getline;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>  // using std::sort;

// Code assumes that the operators >> work for reading in the graph from a stream
// Code assumes that the operator << works for outputting the graph 

//==============================================================================
// numberOfVerticesTest
//==============================================================================
TEST(numberOfVerticesTest, data0) {
   stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
   Graph graph;
   ss >> graph;
   EXPECT_EQ(graph.numberOfVertices(), 7);
}
TEST(numberOfVerticesTest, data1) {
   stringstream ss("7   0 1  1 2   2 3   2 4   4 3"); 
   Graph graph;
   ss >> graph;
   EXPECT_EQ(graph.numberOfVertices(), 7);
}
TEST(numberOfVerticesTest, data4) {
   stringstream ss("2  0 1");
   Graph graph;
   ss >> graph;
   EXPECT_EQ(graph.numberOfVertices(), 2);
}
TEST(numberOfVerticesTest, data6) {
   stringstream ss("33");
   Graph graph;
   ss >> graph;
   EXPECT_EQ(graph.numberOfVertices(), 33);
}
TEST(numberOfVerticesTest, data7) {
   stringstream ss("8  0 1  1 2  2 3  4 3  5 6  4 5  7 6");
   Graph graph;
   ss >> graph;
   EXPECT_EQ(graph.numberOfVertices(), 8);
}

//==============================================================================
// isConnectedTest
//==============================================================================
TEST(isConnectedTest, data0_Fail) {
   stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.isConnected()) << graph;
}
TEST(isConnectedTest, data1_WithCycleIn3Components) {
   stringstream ss("7   0 1  1 2   2 3   2 4   4 3"); 
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.isConnected()) << graph;
}
TEST(isConnectedTest, data6_11SingletonsFail) {
   stringstream ss("11");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.isConnected()) << graph;
}
TEST(isConnectedTest, data7_OneLongComponent) {
   stringstream ss("8  0 1  1 2  2 3  4 3  5 6  4 5  7 6");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.isConnected()) << graph;
}
TEST(isConnectedTest, data4_SingleEdge) {
   stringstream ss("2  0 1");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.isConnected()) << graph;
}
TEST(isConnectedTest, data2_3ComponentsFail) {
   stringstream ss("5   0 1  3 4");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.isConnected()) << graph;
}
TEST(isConnectedTest, SameSourceNDestinationWithTwoCyclesFail) {
   stringstream ss("7 0  1   2  1   2  6   6  4   4  3   3  1   1  5   5  0");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.isConnected()) << graph;
}

// //==============================================================================
// // hasCycleTest
// //==============================================================================
TEST(hasCycleTest, data0) {
   stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, data1_WithCycleIn3Components) {
   stringstream ss("7   0 1  1 2   2 3   2 4   4 3"); 
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, data6_11SingletonsFail) {
   stringstream ss("11");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, data7_OneLongComponentFail) {
   stringstream ss("8  0 1  1 2  2 3  4 3  5 6  4 5  7 6");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, data4_SingleEdgeFail) {
   stringstream ss("2  0 1");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, data2_3ComponentsFail) {
   stringstream ss("5   0 1  3 4");
   Graph graph;
   ss >> graph;
   EXPECT_FALSE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, SameSourceNDestinationWithTwoCycles) {
   stringstream ss("7 0  1   2  1   2  6   6  4   4  3   3  1   1  5   5  0");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, WithCycle) {
   stringstream ss("6      0  1   2  3   4  3   5  2   4  5");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.hasCycle()) << graph;
}
TEST(hasCycleTest, 9WithCycle) {
   stringstream ss("9   8  7   0  1   1  2   2  3   3  4   4  5   5  6   6  7   0  8");
   Graph graph;
   ss >> graph;
   EXPECT_TRUE(graph.hasCycle()) << graph;
}

//==============================================================================
// listComponentTest
//==============================================================================

// expected is a vector of vectors storing a vector of components and
// each internal vector has the vertices of that component
// actual is a vector of vectors storing a vector of components and
// each internal vector has the vertices of that component
// the string stream input has first the number of vertices followed
// by pairs of endpoints of each edge

// using the stringstream ss that has the components, fill vecs
// getting a line from each ss and then sorting in ascending order
void fill(stringstream& ss, vector< vector<int> > &vecs) {
   string buffer;
   while (getline(ss, buffer)) {
      stringstream one_component_ss(buffer);
      vector<int> one_component_vector;
      int u;
      while (one_component_ss >> u) one_component_vector.push_back(u);
      std::sort(one_component_vector.begin(), one_component_vector.end(), 
            [](int a, int b) {return a < b;});
      vecs.push_back(one_component_vector);
   }   
   if (vecs.size() > 1)
      std::sort(vecs.begin(), vecs.end(), 
         [](const vector<int>& v, const vector<int>& w) {return v[0] < w[0];});
}

TEST(listComponentTest, data0_2Components) {
   stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
   // all the vectors and their vertices need to be entered in ascending order
   vector< vector<int> > expected;
   vector<int> v0{0, 3};
   vector<int> v1{1, 2, 4, 5, 6};
   expected.push_back(v0);
   expected.push_back(v1);
   Graph graph;
   ss >> graph;
   stringstream actual_ss;
   graph.listComponents(actual_ss);
   vector< vector<int> > actual;
   fill(actual_ss, actual);  
   EXPECT_EQ(actual, expected) << "\nlist of components =\n" << actual_ss.str();
}
TEST(listComponentTest, data7_OneLongComponent) {
   stringstream ss("8  0 1  1 2  2 3  4 3  5 6  4 5  7 6");
   // all the vectors and their vertices need to be entered in ascending order
   vector< vector<int> > expected;
   vector<int> v0{0, 1, 2, 3, 4, 5, 6, 7};
   expected.push_back(v0);
   Graph graph;
   ss >> graph;
   stringstream actual_ss;
   graph.listComponents(actual_ss);
   vector< vector<int> > actual;
   fill(actual_ss, actual);  
   EXPECT_EQ(actual, expected) << "\nlist of components =\n" << actual_ss.str();
}
TEST(listComponentTest, data1_WithCycleIn3Components) {
   stringstream ss("7   0 1  1 2   2 3   2 4   4 3"); 
   // all the vectors and their vertices need to be entered in ascending order
   vector< vector<int> > expected;
   vector<int> v0{0, 1, 2, 3, 4};
   vector<int> v1{5};
   vector<int> v2{6};
   expected.push_back(v0);
   expected.push_back(v1);
   expected.push_back(v2);
   Graph graph;
   ss >> graph;
   stringstream actual_ss;
   graph.listComponents(actual_ss);
   vector< vector<int> > actual;
   fill(actual_ss, actual);  
   EXPECT_EQ(actual, expected) << "\nlist of components =\n" << actual_ss.str();
}
TEST(listComponentTest, data4_SingleEdge) {
   stringstream ss("2  0 1");
   // all the vectors and their vertices need to be entered in ascending order
   vector< vector<int> > expected;
   vector<int> v0{0, 1};
   expected.push_back(v0);
   Graph graph;
   ss >> graph;
   stringstream actual_ss;
   graph.listComponents(actual_ss);
   vector< vector<int> > actual;
   fill(actual_ss, actual);  
   EXPECT_EQ(actual, expected) << "\nlist of components =\n" << actual_ss.str();
}
TEST(listComponentTest, WithSingletons) {
   stringstream ss("5   1 3  3 4 ");
   // all the vectors and their vertices need to be entered in ascending order
   vector< vector<int> > expected;
   vector<int> v0{0};
   vector<int> v1{1, 3, 4};
   vector<int> v2{2};
   expected.push_back(v0);
   expected.push_back(v1);
   expected.push_back(v2);
   Graph graph;
   ss >> graph;
   stringstream actual_ss;
   graph.listComponents(actual_ss);
   vector< vector<int> > actual;
   fill(actual_ss, actual);  
   EXPECT_EQ(actual, expected) << "\nlist of components =\n" << actual_ss.str();
}
TEST(listComponentTest, data2_3Components) {
   stringstream ss("5   0 1  3 4");
   // all the vectors and their vertices need to be entered in ascending order
   vector< vector<int> > expected;
   vector<int> v0{0, 1};
   vector<int> v1{2};
   vector<int> v2{3, 4};
   expected.push_back(v0);
   expected.push_back(v1);
   expected.push_back(v2);
   Graph graph;
   ss >> graph;
   stringstream actual_ss;
   graph.listComponents(actual_ss);
   vector< vector<int> > actual;
   fill(actual_ss, actual);  
   EXPECT_EQ(actual, expected) << "\nlist of components =\n" << actual_ss.str();
}

// //==============================================================================
// // copyConstructorTest
// //==============================================================================
TEST(copyConstructorTest, data8_numberOfVertices) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   int before1, after1, inside2;
   before1 = graph1.numberOfVertices();
   {
      Graph graph2(graph1);
      inside2 = graph2.numberOfVertices();
      // expecting the destructor to be called
   }
   after1 = graph1.numberOfVertices();
   EXPECT_EQ(before1, after1);
   EXPECT_EQ(before1, inside2);
   EXPECT_EQ(after1, inside2);
}
TEST(copyConstructorTest, data8_isConnected) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   bool before1, after1, inside2;
   before1 = graph1.isConnected();
   {
      Graph graph2(graph1);
      inside2 = graph2.isConnected();
      // expecting the destructor to be called
   }
   after1 = graph1.isConnected();
   EXPECT_EQ(before1, after1);
   EXPECT_EQ(before1, inside2);
   EXPECT_EQ(after1, inside2);
}
TEST(copyConstructorTest, data8_hasCycle) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   bool before1, after1, inside2;
   before1 = graph1.hasCycle();
   {
      Graph graph2(graph1);
      inside2 = graph2.hasCycle();
      // expecting the destructor to be called
   }
   after1 = graph1.hasCycle();
   EXPECT_EQ(before1, after1);
   EXPECT_EQ(before1, inside2);
   EXPECT_EQ(after1, inside2);
}
TEST(copyConstructorTest, data8_listComponents) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   stringstream before1_ss, after1_ss, inside2_ss;
   graph1.listComponents(before1_ss);
   vector< vector<int> > before1;
   vector< vector<int> > inside2;
   fill(before1_ss, before1);
   {
      Graph graph2(graph1);
      graph2.listComponents(inside2_ss);
      // expecting the destructor to be called
      fill(inside2_ss, inside2);
   }
   graph1.listComponents(after1_ss);
   vector< vector<int> > after1;
   fill(after1_ss, after1);
   EXPECT_EQ(before1, after1);
   EXPECT_EQ(before1, inside2);
   EXPECT_EQ(after1, inside2);
}

// //==============================================================================
// // overloadedAssgnOperatorTest
// //==============================================================================
TEST(overloadedAssgnOperatorTest, data8_numberOfVertices) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   stringstream ss2("7  1 4  5 6  6 3  3 5");
   Graph graph2;
   ss2 >> graph2;
   int before1, before2, after1, after2;
   before1 = graph1.numberOfVertices();
   before2 = graph2.numberOfVertices();
   graph2 = graph1;
   after1 = graph1.numberOfVertices();
   after2 = graph2.numberOfVertices();
   EXPECT_EQ(before1, after1);
   EXPECT_NE(before2, after2);
   EXPECT_EQ(after1, after2);
}
TEST(overloadedAssgnOperatorTest, data8_isConnected) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   stringstream ss2("7  0 1 1  2  2 3  3 4  4 5  5 6 ");
   Graph graph2;
   ss2 >> graph2;
   bool before1, before2, after1, after2;
   before1 = graph1.isConnected();
   before2 = graph2.isConnected();
   graph2 = graph1;
   after1 = graph1.isConnected();
   after2 = graph2.isConnected();
   EXPECT_EQ(before1, after1);
   EXPECT_NE(before2, after2);
   EXPECT_EQ(after1, after2);
}

TEST(overloadedAssgnOperatorTest, data8_hasCycle) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   stringstream ss2("7  1 4  5 6  3 5");
   Graph graph2;
   ss2 >> graph2;
   bool before1, before2, after1, after2;
   before1 = graph1.hasCycle();
   before2 = graph2.hasCycle();
   graph2 = graph1;
   after1 = graph1.hasCycle();
   after2 = graph2.hasCycle();
   EXPECT_EQ(before1, after1);
   EXPECT_NE(before2, after2);
   EXPECT_EQ(after1, after2);
}
TEST(overloadedAssgnOperatorTest, data8_listComponents) {
   stringstream ss1("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
   Graph graph1;
   ss1 >> graph1;
   stringstream ss2("7  1 4  5 6  6 3  3 5");
   Graph graph2;
   ss2 >> graph2;
   stringstream before1_ss, before2_ss, after1_ss, after2_ss;
   vector< vector<int> > before1, before2, after1, after2;
   graph1.listComponents(before1_ss);
   graph2.listComponents(before2_ss);
   fill (before1_ss, before1);
   fill (before2_ss, before2);

   graph2 = graph1;

   graph1.listComponents(after1_ss);
   graph2.listComponents(after2_ss);
   fill(after1_ss, after1);  
   fill(after2_ss, after2);  
   EXPECT_EQ(before1, after1);
   EXPECT_NE(before2, after2);
   EXPECT_EQ(after1, after2);
}

// //==============================================================================
// // destructorTest
// //==============================================================================
// TEST(destructorTest, data8_numberOfVertices) {
//    stringstream ss1("2 0 1");
//    Graph* p;
//    p = new Graph;
//    ss1 >> (*p);
//    EXPECT_EQ(p->numberOfVertices(), 2);
//    delete p;
//    stringstream ss2("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
//    p = new Graph;
//    ss2 >> (*p);
//    EXPECT_EQ(p->numberOfVertices(), 14);
//    delete p;
// }
// TEST(destructorTest, data8_listComponents) {
//    stringstream ss1("2 0 1");
//    Graph* p;
//    p = new Graph;
//    ss1 >> (*p);
//    stringstream first;
//    p->listComponents(first);
//    EXPECT_EQ(p->numberOfVertices(), 2);
//    delete p;
//    stringstream ss2("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
//    p = new Graph;
//    ss2 >> (*p);
//    stringstream second;
//    p->listComponents(second);
//    delete p;
//    EXPECT_NE(first.str(), second.str());
// }
// //==============================================================================
// // pathLengthTest
// //==============================================================================

// testing::AssertionResult isEitherOr(int value, int a, int b)  {
//    if (value == a || value == b) {
//       return testing::AssertionSuccess() 
//          << "pathLength=" << value << "  ==>  ==" << a <<  " or ==" << b;
//    }
//    else  {
//       return testing::AssertionFailure() 
//          << "pathLength=" << value << "  ==>  !=" << a <<  " and !=" << b;
//    }
// }

// testing::AssertionResult isEitherOrOr(int value, int a, int b, int c)  {
//    if (value == a || value == b || value == c) {
//       return testing::AssertionSuccess() 
//          << "pathLength=" << value << "  ==>  ==" << a <<  " or ==" << b <<  " or ==" << c;
//    }
//    else {
//       return testing::AssertionFailure() 
//          << "pathLength=" << value << "  ==>  !=" << a <<  " and !=" << b <<  " and !=" << c;
//    }
// }
// TEST(pathLengthTest, data0_1_vStart2vDest4) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 2;
//    int vDest = 4;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 2;
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data0_2_vStart4vDest2) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 4;
//    int vDest = 2;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 2;
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data0_vStart4vDest2) {
//    stringstream ss("7   2  6   6  4   1  2   1  6   4  5   3  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 4;
//    int vDest = 2;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 2;
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data0_vStart6vDest5) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 6;
//    int vDest = 5;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data0_vStart5vDest6) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 5;
//    int vDest = 6;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data0_vStart2vDest4) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 2;
//    int vDest = 4;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 2;
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }

// TEST(pathLengthTest, data0_vStart2vDest5) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 2;
//    int vDest = 5;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 3;
//    int exp_pathLength_b = 4;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data0_vStart5vDest2) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 5;
//    int vDest = 2;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 3;
//    int exp_pathLength_b = 4;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, Anotherg0_vStart3vDest0) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 3;
//    int vDest = 0;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(1, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, Anotherg0_vStart0vDest3) {
//    stringstream ss("7    2 1   2 6    1 6     6 4    4 5   0 3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 0;
//    int vDest = 3;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(1, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data4_SingleEdge) {
//    stringstream ss("2  0 1");
//    Graph graph;
//    ss >> graph;
//    int vStart = 1;
//    int vDest = 0;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(1, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data4_SingleEdgeBackwards) {
//    stringstream ss("2  0 1");
//    Graph graph;
//    ss >> graph;
//    int vStart = 0;
//    int vDest = 1;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(1, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, vStart3vDest4Fail) {
//    stringstream ss("7   2  6   6  4   1  2   1  6   4  5   3  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 3;
//    int vDest = 4;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, vStart0vDest5Fail) {
//    stringstream ss("7    2  6   6  4   1  2   1  6   4  5   3  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 0;
//    int vDest = 5;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, vStart5vDest0Fail) {
//    stringstream ss("7   2  6   6  4   1  2   1  6   4  5   3  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 5;
//    int vDest = 0;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, SameSourceNDestinationvStart0vDest0) {
//    stringstream ss("7    0  1   1  2   2  3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 0;
//    int vDest = 0;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(0, pathLength) << "[ --ERROR--] length should be 0 because vStart and vDest are equal\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, WithCycleDisconnectedvStart4vDest2) {
//    stringstream ss("6      0  1   2  3   4  3   5  2   4  5");
//    Graph graph;
//    ss >> graph;
//    int vStart = 4;
//    int vDest = 2;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, WithCycleDisconnectedvStart2vDest4) {
//    stringstream ss("6     0  1   2  3   4  5   5  2   4  3");
//    Graph graph;
//    ss >> graph;
//    int vStart = 4;
//    int vDest = 2;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, TwoCycles) {
//    stringstream ss("6     4  5   4  3   4  2   2  3   1  2   0  2   0  1");
//    int vStart = 1;
//    int vDest = 4;
//    Graph graph;
//    ss >> graph;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 2;
//    int exp_pathLength_b = 3;
//    int exp_pathLength_c = 4;
//    EXPECT_TRUE(isEitherOrOr(pathLength, exp_pathLength_a, exp_pathLength_b, exp_pathLength_c))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 9VerticesvStart6vDest1Fail) {
//    stringstream ss("9     1  3   4  5   6  7   7  4   2  8");
//    Graph graph;
//    ss >> graph;
//    int vStart = 6;
//    int vDest = 1;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 9VerticesvStart1vDest6Fail) {
//    stringstream ss("9    1  3   4  5   6  7   7  4   2  8");
//    Graph graph;
//    ss >> graph;
//    int vStart = 1;
//    int vDest = 6;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 9VerticesvStart7vDest5) {
//    stringstream ss("9     1  3   4  5   6  7   7  4   2  8");
//    Graph graph;
//    ss >> graph;
//    int vStart = 7;
//    int vDest = 5;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << " vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 9VerticesvStart5vDest7) {
//    stringstream ss("9     1  3   4  5   6  7   7  4   2  8");
//    Graph graph;
//    ss >> graph;
//    int vStart = 5;
//    int vDest = 7;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << " vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 9WithCyclevStart7vDest0) {
//    stringstream ss("9     0  1   1  2   2  3   3  4   4  5   5  6   6  7   7  8   8  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 7;
//    int vDest = 0;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 7;
//    int exp_pathLength_b = 2;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 8vStart4vDest6) {
//    stringstream ss("8 3  2   2  1   1  0   4  5   5  6   7  6");
//    int vStart = 4;
//    int vDest = 6;
//    Graph graph;
//    ss >> graph;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 2;
//    int exp_pathLength_b = 1;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 8vStart2vDest5Fail) {
//    stringstream ss("8 3  2   2  1   1  0   4  5   5  6   7  6");
//    int vStart = 2;
//    int vDest = 5;
//    Graph graph;
//    ss >> graph;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 15vStart10vDest13) {;
//    stringstream ss("15  0  1   0  2   0  3   0  4   0  5   0  6 1  7   1  8   1  9   1  10   5  11   5  12   5  13   5  14");
//    int vStart = 10;
//    int vDest = 13;
//    Graph graph;
//    ss >> graph;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(4, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 15vStart0vDest11) {;
//    stringstream ss("15  0  1   0  2   0  3   0  4   0  5   0  6   1  7   1  8   1  9   1  10   5  11   5  12   5  13   5  14");
//    int vStart = 0;
//    int vDest = 11;
//    Graph graph;
//    ss >> graph;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(2, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 15vStart5vDest12) {;
//    stringstream ss("15  0  1   0  2   0  3   0  4   0  5   0  6   1  7   1  8   1  9   1  10   5  11   5  12   5  13   5  14");
//    int vStart = 5;
//    int vDest = 12;
//    Graph graph;
//    ss >> graph;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(1, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data8_OneComponentWithForks) {
//    stringstream ss("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
//    Graph graph;
//    ss >> graph;
//    int vStart = 1;
//    int vDest = 12;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 3;
//    int exp_pathLength_b = 9;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, MultiplePLength1) {
//    stringstream ss("9  1  2   2  3   3  4   4  5   5  6   6  7   7  8   8  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 1;
//    int exp_pathLength = 0;
//    for (int vDest = 1; vDest < graph.numberOfVertices(); vDest++, exp_pathLength++)  {
//       int pathLength = graph.pathLength(vStart, vDest);
//       EXPECT_EQ(exp_pathLength, pathLength)
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
//    }
// }
// TEST(pathLengthTest, SameSourceNDestination) {
//    stringstream ss("5   0  1   1  2   2  3   3  4");
//    Graph graph;
//    ss >> graph;
//    for (int k = 0; k < graph.numberOfVertices(); k++)  {
//       int vStart = k;
//       int vDest = k;
//       int pathLength = graph.pathLength(vStart, vDest);
//       EXPECT_EQ(0, pathLength) 
//          << "[ --ERROR--]"
//          << " length should be 0 because vStart and vDest are equal\n"
//          << "vStart=vDest=" << vDest
//          << "  # of vertices=" << graph.numberOfVertices()
//          << endl << graph;
//    }
// }
// TEST(pathLengthTest, 7TwoComponentsvStart6vDest5) {
//    stringstream ss("7 2  1   2  6   6  4   4  3   3  1   1  5   5  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 6;
//    int vDest = 5;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 4;
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vvDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 7TwoComponentsvStart0vDest2) {
//    stringstream ss("7   2  1   2  6   6  4   4  3   3  1   1  5   5  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 0;
//    int vDest = 2;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 6;
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vvDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, 7TwoComponentsvStart2vDest0) {
//    stringstream ss("7     2  1   2  6   6  4   4  3   3  1   1  5   5  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 2;
//    int vDest = 0;
//    int pathLength = graph.pathLength(vStart, vDest);
//    int exp_pathLength_a = 6; 
//    int exp_pathLength_b = 3;
//    EXPECT_TRUE(isEitherOr(pathLength, exp_pathLength_a, exp_pathLength_b))
//       << "vvDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, SameSourceNDestinationWithTwoCycles) {
//    stringstream ss("7 0  1   2  1   2  6   6  4   4  3   3  1   1  5   5  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 1;
//    int vDest = 1;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(0, pathLength) 
//       << "[ --ERROR--]"
//       << " length should be 0 because vStart and vDest are equal\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }

// TEST(pathLengthTest, 8TwoComponentsvStart6vDest7Fail) {
//    stringstream ss("8     2  1   2  6   6  4   4  3   3  1   1  5   5  0");
//    Graph graph;
//    ss >> graph;
//    int vStart = 6;
//    int vDest = 7;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }
// TEST(pathLengthTest, data8_OneComponentWithForksFail) {
//    stringstream ss("14   0  1   1  6   1  2   2  3   3  4   4  5   6  7   6  10   7  8   8  5   10  11   10  12   10  13");
//    Graph graph;
//    ss >> graph;
//    int vStart = 0;
//    int vDest = 9;
//    int pathLength = graph.pathLength(vStart, vDest);
//    EXPECT_EQ(-1, pathLength) << "[ --ERROR--] there is no path\n"
//       << "vStart=" << vStart << "  vDest=" << vDest << endl << graph;
// }

// // copyright 2023 Gladys Monagan
