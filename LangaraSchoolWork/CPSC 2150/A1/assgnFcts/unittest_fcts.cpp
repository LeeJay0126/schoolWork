// Name: 

// CPSC 2150, Assignment #1 by Gladys Monagan
// Do not post anywhere.

#include <string>
#include <sstream> 
#include "gtest/gtest.h"
#include <climits>        // UINT_MAX
#include "fcts.h"

using std::stringstream, std::string;
using std::cout, std::endl;

//---------------------------------------------------------------------------//
TEST(isStrictlyDescendingTest, NoElements) {
   const int MAX_SIZE = 4;
   int A[MAX_SIZE] = {5, 8, 3, 2};
   int n = 0;
   EXPECT_TRUE(isStrictlyDescending(A, n));
}
TEST(isStrictlyDescendingTest, OneElement) {
   const int MAX_SIZE = 4;
   int A[MAX_SIZE] = {8, 8, 3, 2};
   int n = 1;
   EXPECT_TRUE(isStrictlyDescending(A, n));
}
TEST(isStrictlyDescendingTest, FirstTwoElementsEqualFail) {
   const int MAX_SIZE = 4;
   int A[MAX_SIZE] = {8, 8, 3, 2};
   int n = 2;
   EXPECT_FALSE(isStrictlyDescending(A, n));
}
TEST(isStrictlyDescendingTest, 3Typical) {
   const int MAX_SIZE = 4;
   int A[MAX_SIZE] = {8, 6, 3, 3};
   int n = 3;
   EXPECT_TRUE(isStrictlyDescending(A, n));
}
//---------------------------------------------------------------------------//
// swapPairsLeftToRight precondition: n > 0
// helper function to make a string 
//   [----ERROR-]
//   the n values of A
//   msg
string errorArrayString(string arrayName, const int A[], int n, string msg){
   string arrayStr = arrayName + " = { ";
   for (int i = 0; i < n; i++) {
      arrayStr += std::to_string(A[i]) + " ";
   }
   arrayStr += "} ";
   return "[----ERROR-] " + arrayStr + msg;
}

// determines if A and B are equal return true if such is the case, false otherwise
bool equalArrays(const int A[], int nA, const int B[], int nB) {
   if (nA != nB)
      return false;
   for (int i = 0; i < nA; i++) {
      if (A[i] != B[i])
         return false;
   }
   return true;
}
TEST(swapPairsLeftToRightTest, OneElement) {
   int A[] = {11, -22, -33, -44, -55};
   int EXPECTED_A[] = {11};
   swapPairsLeftToRight(A, 1);
   EXPECT_TRUE(equalArrays(A, 1, EXPECTED_A, 1)) <<
      errorArrayString("A", A, 1, " with one element nothing to swap " );
}

TEST(swapPairsLeftToRightTest, EvenNumberOfElements2) {
   int A[] = {11, 22, -33, -44};
   int EXPECTED_A[] = {22, 11};
   swapPairsLeftToRight(A, 2);
   EXPECT_TRUE(equalArrays(A, 2, EXPECTED_A, 2)) <<
      errorArrayString("A", A, 2, " not swapped correctly " );
}

TEST(swapPairsLeftToRightTest, OddNumberOfElements3) {
   int A[] = {11, 22, 33, -44, -55};
   int EXPECTED_A[] = {22, 11, 33};
   swapPairsLeftToRight(A, 3);
   EXPECT_TRUE(equalArrays(A, 3, EXPECTED_A, 3)) <<
      errorArrayString("A", A, 3, " not swapped correctly " );
}

TEST(swapPairsLeftToRightTest, EvenNumberOfElements) {
   int A[] = {11, 22, 33, 44, 55, 66, -77, -88, -99};
   int EXPECTED_A[] = {22, 11, 44, 33, 66, 55};
   swapPairsLeftToRight(A, 6);
   EXPECT_TRUE(equalArrays(A, 6, EXPECTED_A, 6)) <<
      errorArrayString("A", A, 6, " not swapped correctly " );
}

TEST(swapPairsLeftToRightTest, OddNumberOfElements) {
   int A[] = {11, 22, 33, 44, 55, -66, -77, -88, -99};
   int EXPECTED_A[] = {22, 11, 44, 33, 55};
   swapPairsLeftToRight(A, 5);
   EXPECT_TRUE(equalArrays(A, 5, EXPECTED_A, 5)) <<
      errorArrayString("A", A, 5, " not swapped correctly " );
}


//---------------------------------------------------------------------------//
TEST(outputAsHexTest, TypicalFewDigits) {
   stringstream actual;
   outputAsHex(1529, actual);
   string expected = "5F9";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outputAsHexTest, BorderCaseOneDigit) {
   stringstream actual;
   outputAsHex(15, actual);
   string expected = "F";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outputAsHexTest, BorderCaseTwoDigits) {
   stringstream actual;
   outputAsHex(16, actual);
   string expected = "10";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outputAsHexTest, BorderCase) {
   stringstream actual;
   outputAsHex(1, actual);
   string expected = "1";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outputAsHexTest, SpecialCase0) {
   stringstream actual;
   outputAsHex(0, actual);
   string expected = "0";
   EXPECT_EQ(actual.str(), expected);
}

//---------------------------------------------------------------------------//
// expected values when CHAR_BIT is 8 and sizeof(unsigned) is 4
TEST(outInOctalTest, TypicalFewDigits) {
   stringstream actual;
   outInOctal(32, actual);
   string expected = "00000000040";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outInOctalTest, BorderCaseTwoDigits) {
   stringstream actual;
   outInOctal(8, actual);
   string expected = "00000000010";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outInOctalTest, BorderCaseOneDigit) {
   stringstream actual;
   outInOctal(7, actual);
   string expected = "00000000007";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outInOctalTest, LargeValue) {
   stringstream actual;
   outInOctal(2147483647, actual);
   string expected = "17777777777";
   EXPECT_EQ(actual.str(), expected);
}
TEST(outInOctalTest, BorderCase) {
   stringstream actual;
   outInOctal(1, actual);
   string expected = "00000000001";
   EXPECT_EQ(actual.str(), expected);
}

//---------------------------------------------------------------------------//
TEST(insideInOrderTest, EmptyString) {
   EXPECT_TRUE(insideInOrder("", 5, "abcdef"));
}
TEST(insideInOrderTest, NoOccurences) {
   EXPECT_TRUE(insideInOrder("dog", 0, "dog"));
}
TEST(insideInOrderTest, ExactMatch) {
   EXPECT_TRUE(insideInOrder("dog", 1, "dog"));
}
TEST(insideInOrderTest, 1LetterAfterLikePattern) {
   EXPECT_TRUE(insideInOrder("dog", 1, "dogs"));
}
TEST(insideInOrderTest, ScrambledLettersFail) {
   EXPECT_FALSE(insideInOrder("dog", 1, "ogd"));
}
TEST(insideInOrderTest, NotInOrderWithLettersInbetweenFail) {
   EXPECT_FALSE(insideInOrder("dog", 1, "dXoXg"));
}
TEST(insideInOrderTest, WithLettersAfterMatch) {
   EXPECT_TRUE(insideInOrder("dog", 1, "a doggie"));
}
TEST(insideInOrderTest, OnlyOneOccurrenceNot2Fail) {
   EXPECT_FALSE(insideInOrder("dog", 2, "doggie dxg"));
}
TEST(insideInOrderTest, 2OccurrencesWithLettersBeforeNAfter) {
   EXPECT_TRUE(insideInOrder("dog", 2, "two doggie doggie"));
}
TEST(insideInOrderTest, AtLeast0Times) {
   EXPECT_TRUE(insideInOrder("the", 0, "these are their theses"));
}
TEST(insideInOrderTest, AtLeast1Time) {
   EXPECT_TRUE(insideInOrder("the", 1, "these are their theses"));
}
TEST(insideInOrderTest, AtLeast2Times) {
   EXPECT_TRUE(insideInOrder("the", 2, "these are their theses"));
}
TEST(insideInOrderTest, AtLeast3Times) {
   EXPECT_TRUE(insideInOrder("the", 3, "these are their theses"));
}
TEST(insideInOrderTest, AtLeast4Times) {
   EXPECT_FALSE(insideInOrder("the", 4, "these are their theses"));
}
TEST(insideInOrderTest, AtLeast5TimesFail) {
   EXPECT_FALSE(insideInOrder("the", 5, "these are their theses"));
}

//---------------------------------------------------------------------------//
TEST(insideInOrderITest, NoOccurences) {
   EXPECT_TRUE(insideInOrderI("dog", 0, "dog"));
}
TEST(insideInOrderITest, ExactMatch) {
   EXPECT_TRUE(insideInOrderI("dog", 1, "dog"));
}
TEST(insideInOrderITest, 1LetterAfterLikePattern) {
   EXPECT_TRUE(insideInOrderI("dog", 1, "dogs"));
}


