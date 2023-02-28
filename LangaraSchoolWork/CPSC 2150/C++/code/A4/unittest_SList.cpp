// A unit test for Langara CPSC 2150 
// Assignment 4: Skip List
// C++ unit test framework: Google Test
// Author: Gladys Monagan 

#include "SList.h"
#include "gtest/gtest.h"
#include <string.h>
#include <sstream>
#include <iostream>

using std::string, std::stringstream, std::cout;

/*
The top list is comparing with output and this might not match your code
because of the plus or minus one, 
so you might not want to run the TopList tests

do only the tests that have a test with TopList in the name 
(regardless of the test suite)
./unittest_SList --gtest_filter="*.*TopList*"

only test with Empty in it
./unittest_SList --gtest_filter="*.*Empty*"

do NOT do the tests that have a test with TopList in the name 
(regardless of the test suite)
./unittest_SList --gtest_filter=-"*.*TopList*"

*/

testing::AssertionResult isEitherOr(string actual, string a, string b)  {
   if (actual == a || actual == b) {
      return testing::AssertionSuccess() 
         << "actual=" << actual << "  ==>  ==" << a <<  " or ==" << b;
   }
   else  {
      return testing::AssertionFailure() 
         << "actual=" << actual << "  ==>  !=" << a <<  " and !=" << b;
   }
}

//-----------------------------------------------------------------
// constructorTest
//    depends on the << operator, setTopListOutput
//-----------------------------------------------------------------
TEST(constructorTest, EmptyBottomList) {
   SList sList;
   stringstream actual;
   actual << sList;
   EXPECT_EQ(string(""), actual.str());
}
TEST(constructorTest, EmptyTopList) {
   SList sList;
   stringstream actual;
   actual << sList;
   sList.setTopListOutput(true);
   EXPECT_EQ(string(""), actual.str());
}
//-----------------------------------------------------------------
// isEmptyTest
//    depends on insert, setTopListOutput
//-----------------------------------------------------------------
TEST(isEmptyTest, EmptyList) {
   SList sList;
   EXPECT_TRUE(sList.isEmpty()) << "A new list should be empty";
}
TEST(isEmptyTest, EmptyTopList) {
   SList sList;
   // setTopListOutput is for output, it should not affect isEmpty
   sList.setTopListOutput(true);
   EXPECT_TRUE(sList.isEmpty()) << "A new list should be empty";
}
TEST(isEmptyTest, FailBorderCaseBottomList) {
   SList sList;
   sList.insert(-99);
   EXPECT_FALSE(sList.isEmpty()) << "A list with -99 is not empty";
}
TEST(isEmptyTest, FailBorderCaseTopList) {
   SList sList;
   sList.insert(-55);
   // setTopListOutput is for output, it should not affect isEmpty
   sList.setTopListOutput(true);
   EXPECT_FALSE(sList.isEmpty()) << "A list with -55 is not empty";
}
//-----------------------------------------------------------------
// insertTest
//    depends on insert, the << operator, setTopListOutput
//-----------------------------------------------------------------
TEST(insertTest, OneElementBottomList) {
   SList sList;
   sList.insert(0);
   stringstream actual;
   actual << sList;
   stringstream expected;
   expected << 0 << SList::SEP;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertTest, OneElementTopList) {
   SList sList;
   sList.insert(1984);
   sList.setTopListOutput(true);
   stringstream actual;
   actual << sList;
   stringstream expected;
   expected << 1984 << SList::SEP;
   EXPECT_EQ(actual.str(), expected.str());
}
//-----------------------------------------------------------------
// numberOfElementsTest
//    depends on the << operator, insert
//-----------------------------------------------------------------
TEST(numberOfElementsTest, OneSpecialCase) {
   SList sList;
   sList.insert(111);
   EXPECT_EQ(sList.numberOfElements(), 1);
}
TEST(numberOfElementsTest, 2ElementsBottomList) {
   SList sList;
   sList.insert(98);
   sList.insert(87);
   EXPECT_EQ(sList.numberOfElements(), 2);
}
TEST(numberOfElementsTest, 3ElementsBottomList) {
   SList sList;
   int A[] = {-8, 2345, 1};
   unsigned n = 3;
   for (unsigned i = 0; i < n; i++) {
      sList.insert(A[i]);
   }
   EXPECT_EQ(sList.numberOfElements(), 3);
}
TEST(numberOfElementsTest, LargeNumber) {
   SList sList;
   for (unsigned i = 0u; i < 10000; i++) {
      sList.insert(rand());
   }
   EXPECT_EQ(sList.numberOfElements(), 10000);
}
//-----------------------------------------------------------------
// insertDescendingTest
//    depends on insert, the << operator, setTopListOutput
//-----------------------------------------------------------------
TEST(insertRandomTest,9BottomAndTopList) {
   SList sList;
   int A[] = {5, 7, 20, 19, 3, 6, 10, 12, 11};
   unsigned n = 9;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   stringstream actual, expected;
   actual << sList;
   expected
      << 3 << SList::SEP << 5 << SList::SEP << 6 << SList::SEP
      << 7 << SList::SEP << 10 << SList::SEP << 11 << SList::SEP
      << 12 << SList::SEP << 19 << SList::SEP << 20 << SList::SEP;
   EXPECT_EQ(actual.str(), expected.str());

   sList.setTopListOutput(true);
   actual = stringstream();
   actual << sList;
   expected = stringstream();
   expected 
      << 3  << SList::SEP << 7 << SList::SEP << 12 << SList::SEP;
   EXPECT_EQ(actual.str(), expected.str());
}

//-----------------------------------------------------------------
// insertAscendingTest
//    depends on insert, the << operator, setTopListOutput
//-----------------------------------------------------------------
TEST(insertAscendingTest, 2ElementsBottomList) {
   SList sList;
   sList.insert(43);
   sList.insert(67);
   stringstream actual;
   actual << sList;
   stringstream expected;
   expected
      << 43 << SList::SEP
      << 67 << SList::SEP;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, 2ElementsTopList) {
   SList sList;
   sList.insert(111);
   sList.insert(222);
   stringstream actual;
   actual << sList;
   sList.setTopListOutput(true);
   stringstream expected_a;
   expected_a
      << 111 << SList::SEP;
   stringstream expected_b;
   expected_b
      << 111 << SList::SEP
      << 222 << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
TEST(insertAscendingTest, 3ElementsBottomList) {
   SList sList;
   int A[] = {21, 65, 78};
   unsigned n = 3;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[i] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, 3ElementsTopList) {
   SList sList;
   int A[] = {11, 555, 982};
   unsigned n = 3;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   stringstream actual;
   sList.setTopListOutput(true);
   actual << sList;
   stringstream expected_a;
   expected_a
      << A[0] << SList::SEP;
   stringstream expected_b;
   expected_b
      << A[0] << SList::SEP
      << A[2] << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
TEST(insertAscendingTest, 4ElementsBottomList) {
   SList sList;
   int A[] = {10, 20, 30, 40};
   unsigned n = 4;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[i] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, 5ElementsBottomList) {
   SList sList;
   int A[] = {10, 20, 30, 40, 50};
   unsigned n = 5;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[i] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest, 5ElementsTopList) {
   SList sList;
   int A[] = {10, 20, 30, 40, 50};
   unsigned n = 5;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   stringstream actual;
   sList.setTopListOutput(true);
   actual << sList;

   stringstream expected_a;
   expected_a
      << A[0] << SList::SEP
      << A[2] << SList::SEP
      << A[4] << SList::SEP;
   stringstream expected_b;
   expected_b
      << A[0] << SList::SEP
      << A[2] << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
TEST(insertAscendingTest, 9ElementsBottomList) {
   SList sList;
   int A[] = {10, 20, 30, 40, 50, 61, 77, 88, 99};
   unsigned n = 9;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[i] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertAscendingTest,9ElementsTopList) {
   SList sList;
   int A[] = {10, 20, 30, 40, 50, 61, 77, 88, 99};
   unsigned n = 9;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   stringstream actual;
   sList.setTopListOutput(true);
   actual << sList;
   stringstream expected_a;
   expected_a
      << A[0] << SList::SEP
      << A[3] << SList::SEP
      << A[6] << SList::SEP;
   stringstream expected_b;
   expected_b
      << A[0] << SList::SEP
      << A[4] << SList::SEP
      << A[7] << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
//-----------------------------------------------------------------
// insertDescendingTest
//    depends on insert, the << operator, setTopListOutput
//-----------------------------------------------------------------
TEST(insertDescendingTest, 2ElementsBottomList) {
   SList sList;
   sList.insert(789);
   sList.insert(123);
   stringstream actual;
   actual << sList;
   stringstream expected;
   expected
      << 123 << SList::SEP
      << 789 << SList::SEP;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertDescendingTest, 2ElementsTopList) {
   SList sList;
   sList.insert(654);
   sList.insert(653);
   stringstream actual;
   actual << sList;
   sList.setTopListOutput(true);
   stringstream expected_a;
   expected_a
      << 654 << SList::SEP;
   stringstream expected_b;
   expected_b
      << 653 << SList::SEP
      << 654 << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
TEST(insertDescendingTest, 3ElementsBottomList) {
   SList sList;
   int A[] = {233, 222, 211};
   unsigned n = 3;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[n-i-1] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertDescendingTest, 3ElementsTopList) {
   SList sList;
   int A[] = {533, 522, 511};
   unsigned n = 3;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   stringstream actual;
   sList.setTopListOutput(true);
   actual << sList;
   stringstream expected_a;
   expected_a
      << A[2] << SList::SEP;
   stringstream expected_b;
   expected_b
      << A[2] << SList::SEP
      << A[0] << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
TEST(insertDescendingTest, 4ElementsBottomList) {
   SList sList;
   int A[] = {44, 33, 22, 11};
   unsigned n = 4;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[n-i-1] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertDescendingTest, 5ElementsBottomList) {
   SList sList;
   int A[] = {55, 44, 33, 22, 11};
   unsigned n = 5;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[n-i-1] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}

TEST(insertDescendingTest, 5ElementsTopList) {
   SList sList;
   int A[] = {55, 44, 33, 22, 11};
   unsigned n = 5;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   sList.setTopListOutput(true);
   stringstream actual;
   actual << sList;
   stringstream expected_a;
   expected_a
      << A[4] << SList::SEP
      << A[2] << SList::SEP;
   stringstream expected_b;
   expected_b
      << A[4] << SList::SEP
      << A[1]<< SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}
TEST(insertDescendingTest, 9ElementsBottomList) {
   SList sList;
   int A[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
   unsigned n = 9;
   stringstream expected;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
      expected << A[n-i-1] << SList::SEP;
   }
   stringstream actual;
   actual << sList;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(insertDescendingTest, 9ElementsTopList) {
   SList sList;
   int A[] = {99, 88, 77, 66, 55, 44, 33, 22, 11};
   unsigned n = 9;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   stringstream actual;
   sList.setTopListOutput(true);
   actual << sList;
   stringstream expected_a;
   expected_a
      << A[8] << SList::SEP
      << A[5] << SList::SEP
      << A[2] << SList::SEP;
   stringstream expected_b;
   expected_b
      << A[8] << SList::SEP
      << A[4] << SList::SEP
      << A[0] << SList::SEP;
   EXPECT_TRUE(isEitherOr(actual.str(), expected_a.str(), expected_b.str()));
}

//-----------------------------------------------------------------
// searchTest
//    depends on insert
//-----------------------------------------------------------------
TEST(searchTest, NoElementsFail) {
   SList sList;
   EXPECT_FALSE(sList.search(3));
}
TEST(searchTest, 9Elements) {
   SList sList;
   int A[] = {161, 199, 130, 140, 150, 110, 177, 188, 120};
   unsigned n = 9;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   for (unsigned i = 0u; i < n; i++) {
      EXPECT_TRUE(sList.search(A[i]));
   }
}
TEST(searchTest, 9ElementsFail) {
   SList sList;
   int A[] = {161, 199, 130, 140, 150, 110, 177, 188, 120};
   unsigned n = 9;
   for (unsigned i = 0u; i < n; i++) {
      sList.insert(A[i]);
   }
   int not_in = 100;
   EXPECT_FALSE(sList.search(not_in));
}
TEST(searchTest, 10000RandomRepeatsFail) {
   SList sList;
   for (unsigned i = 0u; i <= 10000; i++) {
      sList.insert(rand()%1000);
   }
   int x = 2023;
   sList.insert(2023);
   EXPECT_TRUE(sList.search(x));
   int not_in = -1;
   EXPECT_FALSE(sList.search(not_in));
}

//-----------------------------------------------------------------
// resetTest
//    depends on insert and isEmpty and the operator << 
//-----------------------------------------------------------------
TEST(resetTest, EmptyList) {
   SList sList;
   sList.reset();
   EXPECT_TRUE(sList.isEmpty()) << "an empty list should be able to set to empty";
}
TEST(resetTest, ManyRandomNumbersEmpty) {
   SList sList;
   for (int i = 0; i <= 10000; i++) {
      sList.insert(rand()%1000);
   }
   sList.reset();
   EXPECT_TRUE(sList.isEmpty());
   stringstream actual;
   actual << sList;
   EXPECT_EQ(string(""), actual.str());
}
TEST(resetTest, ManyRandomNumbersIsEmpty) {
   SList sList;
   for (int i = 0; i <= 10000; i++) {
      sList.insert(rand()%1000);
   }
   sList.reset();
   EXPECT_TRUE(sList.isEmpty());
   stringstream actual;
   actual << sList;
   EXPECT_EQ(string(""), actual.str());
}
TEST(resetTest, 10000PlusMinusUniqueEmpty) {
   SList sList;
   int j;
   for (int i = 1; i <= 10000; i++) {
      j = (i & 1) ? i : -i;
      sList.insert(j);
   }
   sList.insert(100001);
   sList.insert(-100001);
   sList.reset();
   EXPECT_TRUE(sList.isEmpty());
   stringstream actual;
   actual << sList;
   EXPECT_EQ(string(""), actual.str());
}

// copyright 2023 Gladys Monagan

