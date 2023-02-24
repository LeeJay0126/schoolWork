// C++ unit test framework: google test
// Author: Gladys Monagan
// Do not post anywhere

/*
run test that have addBack
./unittest_D --gtest_filter="*.*addBack*"
run test that have addFront
./unittest_D --gtest_filter="*.*addFront*"
run tests that do NOT have removeFrontTest and removeBackTest
(note the - after the equals=)
./unittest_D --gtest_filter=-"remove*.*"

or
  run test that have addBack
  unittest_D --gtest_filter="*.*addBack*"
  run test that have addFront
  unittest_D --gtest_filter="*.*addFront*"
  run tests that do NOT have removeFrontTest and removeBackTest
  (note the - after the equals=)
  unittest_D --gtest_filter=-"remove*.*"
*/

// skip the required big three by changing the variable to true
const bool skip_big3Tests = false;

#include "D.h"
#include "DException.h"
#include "gtest/gtest.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

//-----------------------------------------------------------------
// constructorTest
//    depends on the << operator front to back
//    depends on the >> operator back to front
//-----------------------------------------------------------------
TEST(constructorTest, DefaultConstructorOutputFrontToBack) {
   D d;
   stringstream actual;
   actual << d;
   EXPECT_EQ(actual.str(), D::FRONT + D::BACK );
}
TEST(constructorTest, DefaultConstructorOutputBackToFront) {
   D d;
   stringstream actual;
   actual >> d;
   EXPECT_EQ(actual.str(), D::BACK + D::FRONT );
}
//-----------------------------------------------------------------
// isEmptyTest
//-----------------------------------------------------------------
TEST(isEmptyTest, EmptyD) {
   D d;
   EXPECT_TRUE(d.isEmpty());
}
//-----------------------------------------------------------------
// outputFrontToBackTest
//    depends on addBack 
//    depends on the << operator front to back
//-----------------------------------------------------------------
TEST(outputFrontToBackTest, addBack3Items) {
   D d;
   d.addBack(11);
   d.addBack(22);
   d.addBack(33);
   stringstream actual;
   actual << d;
   stringstream expected;
   expected
      << D::FRONT
      << 11 << D::SEP
      << 22 << D::SEP
      << 33 << D::SEP
      << D::BACK;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(outputFrontToBackTest, addFront4Items) {
   D d;
   d.addFront(66);
   d.addFront(77);
   d.addFront(8);
   d.addFront(99);
   stringstream actual;
   actual << d;
   stringstream expected;
   expected
      << D::FRONT
      << 99 << D::SEP
      << 8 << D::SEP
      << 77 << D::SEP
      << 66 << D::SEP
      << D::BACK;
   EXPECT_EQ(actual.str(), expected.str());
}
//-----------------------------------------------------------------
// outputBackToFrontTest
//    depends on addBack 
//    depends on the >> operator back to front
//-----------------------------------------------------------------
TEST(outputBackToFrontTest, addBack4Items) {
   D d;
   d.addBack(-55);
   d.addBack(-22);
   d.addBack(-33);
   d.addBack(-4);
   stringstream actual;
   actual >> d;
   stringstream expected;
   expected
      << D::BACK
      << -4 << D::SEP
      << -33 << D::SEP
      << -22 << D::SEP
      << -55 << D::SEP
      << D::FRONT;
   EXPECT_EQ(actual.str(), expected.str());
}
TEST(outputBackToFrontTest, addFront3Items) {
   D d;
   d.addFront(77);
   d.addFront(-88);
   d.addFront(-99);
   stringstream actual;
   actual >> d;
   stringstream expected;
   expected
      << D::BACK
      << 77 << D::SEP
      << -88 << D::SEP
      << -99 << D::SEP
      << D::FRONT;
   EXPECT_EQ(actual.str(), expected.str());
}
//-----------------------------------------------------------------
// removeFrontTest
//    depends on addBack
//    depends on addFront
//    depends on isEmpty
//    depends on the >> operator back to front
//    depends on the << operator front to back
//-----------------------------------------------------------------
TEST(removeFrontTest, addBack3FrontToBack) {
   D d;
   d.addBack(123);
   d.addBack(456);
   d.addBack(789);
   EXPECT_EQ(d.remFront(), 123);
   stringstream actualFrontToBack;
   actualFrontToBack << d;
   stringstream expectedFrontToBack;
   expectedFrontToBack
      << D::FRONT
      << 456 << D::SEP
      << 789 << D::SEP
      << D::BACK;
   EXPECT_EQ(actualFrontToBack.str(), expectedFrontToBack.str());
}
TEST(removeFrontTest, addFront3BackToFront) {
   D d;
   d.addFront(-123);
   d.addFront(-456);
   d.addFront(-789);
   EXPECT_EQ(d.remFront(), -789);
   stringstream actualBackToFront;
   actualBackToFront >> d;
   stringstream expectedBackToFront;
   expectedBackToFront
      << D::BACK
      << -123 << D::SEP
      << -456 << D::SEP
      << D::FRONT;
   EXPECT_EQ(actualBackToFront.str(), expectedBackToFront.str());
}
TEST(removeFrontTest, EmptyThrow) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remFront(), DException);
}
TEST(removeFrontTest, addFront1Throw) {
   D d;
   d.addFront(2023);
   ASSERT_EQ(d.remFront(), 2023);
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remFront(), DException);
}
TEST(removeFrontTest, addBackaddFront) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   d.addBack(666);
   EXPECT_EQ(666, d.remFront());
   d.addFront(555);
   EXPECT_EQ(555, d.remFront());
   EXPECT_TRUE(d.isEmpty());
}
TEST(removeFrontTest, addFrontaddBack) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   d.addFront(-666);
   EXPECT_EQ(-666, d.remFront());
   d.addBack(-555);
   EXPECT_EQ(-555, d.remFront());
   EXPECT_TRUE(d.isEmpty());
}
TEST(removeFrontTest, addBackaddFrontThrow) {
   D d;
   d.addBack(1984);
   d.addFront(1985);
   ASSERT_EQ(d.remFront(), 1985);
   ASSERT_EQ(d.remFront(), 1984);
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remFront(), DException);
}
TEST(removeFrontTest, addBackThrow) {
   D d;
   d.addBack(1984);
   ASSERT_EQ(d.remFront(), 1984);
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remFront(), DException);
}
//-----------------------------------------------------------------
// removeBackTest
//    depends on addBack
//    depends on addFront
//    depends on isEmpty
//    depends on the >> operator back to front
//    depends on the << operator front to back
//-----------------------------------------------------------------
TEST(removeBackTest, addBack3FrontToBack) {
   D d;
   d.addBack(12);
   d.addBack(45);
   d.addBack(78);
   EXPECT_EQ(d.remBack(), 78);
   stringstream actualFrontToBack;
   actualFrontToBack << d;
   stringstream expectedFrontToBack;
   expectedFrontToBack
      << D::FRONT
      << 12 << D::SEP
      << 45 << D::SEP
      << D::BACK;
   EXPECT_EQ(actualFrontToBack.str(), expectedFrontToBack.str());
}
TEST(removeBackTest, addFront3BackToFront) {
   D d;
   d.addFront(-12);
   d.addFront(-45);
   d.addFront(-78);
   EXPECT_EQ(d.remBack(), -12);
   stringstream actualBackToFront;
   actualBackToFront >> d;
   stringstream expectedBackToFront;
   expectedBackToFront
      << D::BACK
      << -45 << D::SEP
      << -78 << D::SEP
      << D::FRONT;
   EXPECT_EQ(actualBackToFront.str(), expectedBackToFront.str());
}
TEST(removeBackTest, EmptyThrow) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remBack(), DException);
}
TEST(removeBackTest, addBack1Throw) {
   D d;
   d.addBack(5023);
   ASSERT_EQ(d.remBack(), 5023);
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remBack(), DException);
}
TEST(removeBackTest, addBackaddFront) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   d.addBack(669);
   EXPECT_EQ(669, d.remBack());
   d.addFront(554);
   EXPECT_EQ(554, d.remBack());
   EXPECT_TRUE(d.isEmpty());
}
TEST(removeBackTest, addFrontaddBack) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   d.addFront(-656);
   EXPECT_EQ(-656, d.remBack());
   d.addBack(-525);
   EXPECT_EQ(-525, d.remBack());
   EXPECT_TRUE(d.isEmpty());
}
TEST(removeBackTest, addFrontaddBackThrow) {
   D d;
   d.addFront(1970);
   d.addBack(1971);
   ASSERT_EQ(d.remBack(), 1971);
   ASSERT_EQ(d.remBack(), 1970);
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remBack(), DException);
}
TEST(removeBackTest, addBackThrow) {
   D d;
   d.addBack(1884);
   ASSERT_EQ(d.remBack(), 1884);
   ASSERT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remBack(), DException);
}
//-----------------------------------------------------------------
// lengthTest
//    depends on isEmpty
//    depends on addBack
//    depends on addFront
//    depends on remBack
//    depends on remFront
//-----------------------------------------------------------------
TEST(lengthTest, SpecialCase) {
   D d;
   ASSERT_TRUE(d.isEmpty());
   EXPECT_EQ(d.length(), 0);
}
TEST(lengthTest, addFrontBorderCase1) {
   D d;
   d.addFront(202310);
   // cout << d.length() << endl;
   EXPECT_EQ(d.length(), 1);
}
TEST(lengthTest, addFrontOnly) {
   D d;
   d.addFront(1);
   d.addFront(2);
   d.addFront(3);
   d.addFront(4);
   d.addFront(5);
   EXPECT_EQ(d.length(), 5);
}
TEST(lengthTest, addFrontaddBack) {
   D d;
   d.addFront(23);
   d.addBack(33);
   d.addBack(43);
   d.addFront(53);
   EXPECT_EQ(d.length(), 4);
}
TEST(lengthTest, removeFrontremoveBack) {
   D d;
   d.addFront(23);
   d.addBack(33);
   d.addBack(43);
   d.addFront(53);
   EXPECT_EQ(d.length(), 4);
   EXPECT_EQ(d.remFront(), 53);
   EXPECT_EQ(d.length(), 3);
   EXPECT_EQ(d.remBack(), 43);
   EXPECT_EQ(d.length(), 2);
}
TEST(lengthTest, addBackBorderCase1) {
   D d;
   d.addBack(202310);
   EXPECT_EQ(d.length(), 1);
}
TEST(lengthTest, addBackOnly) {
   D d;
   d.addBack(1);
   d.addBack(2);
   d.addBack(3);
   d.addBack(4);
   d.addBack(5);
   EXPECT_EQ(d.length(), 5);
}
//-----------------------------------------------------------------
// equalsTest
//    depends on isEmpty
//    depends on length
//    depends on addBack
//    depends on addFront
//    depends on remBack
//    depends on remFront
//-----------------------------------------------------------------
TEST(equalsTest, EmptyDs) {
   D dA, dB;
   ASSERT_TRUE(dA.isEmpty());
   ASSERT_TRUE(dB.isEmpty());
   EXPECT_TRUE(dA == dB) << "two empty ds are equal";
}
// TEST(equalsTest, addBack1ItemFail) {
//    D dA, dB;
//    dA.addBack(7);
//    ASSERT_TRUE(dB.isEmpty());
//    EXPECT_FALSE(dA == dB) << "dA does have an item";
//    EXPECT_FALSE(dB == dA) << "dA does have an item";
// }
// TEST(equalsTest, addBackaddFront1Item) {
//    D dA, dB;
//    dA.addBack(7);
//    dB.addFront(7);
//    EXPECT_TRUE(dA == dB);
//    EXPECT_TRUE(dB == dA);
// }
TEST(equalsTest, addBackaddFrontLength2SameValues) {
   D dA, dB;
   dA.addBack(1160);
   dA.addFront(1160);
   dB.addFront(1160);
   dB.addBack(1160);
   EXPECT_EQ(dA.length(), dB.length());
   EXPECT_TRUE(dA == dB) << "same 1160s in both ds";
   EXPECT_TRUE(dB == dA) << "same 1160s in both ds";
}
TEST(equalsTest, addBackLength1DifferentValuesFail) {
   D dA, dB;
   dA.addBack(1150);
   dB.addBack(1155);
   EXPECT_EQ(dA.length(), dB.length());
   EXPECT_FALSE(dA == dB) << "d has 1150 and the other 1155";
   EXPECT_FALSE(dB == dA) << "d has 1150 and the other 1155";
}
TEST(equalsTest, addFrontSameLengthDifferentValuesFail) {
   D dA, dB;
   dA.addFront(1050);
   dA.addFront(1150);
   dB.addFront(1045);
   dB.addFront(1155);
   EXPECT_EQ(dA.length(), dB.length());
   EXPECT_FALSE(dA == dB) << "different values in ds of length 2";
   EXPECT_FALSE(dB == dA) << "different values in ds of length 2";
}
TEST(equalsTest, addBackaddFrontSameLengthSameValuesDifferentOrderFail) {
   D dA, dB;
   dA.addBack(2);
   dA.addBack(3);
   dA.addBack(4);
   dB.addFront(2);
   dB.addFront(3);
   dB.addFront(4);
   EXPECT_EQ(dA.length(), dB.length());
   EXPECT_FALSE(dA == dB) << "same values but different order";
   EXPECT_FALSE(dB == dA) << "same values but different order";
}
TEST(equalsTest, addBackSameValuesSameLength) {
   D dA, dB;
   dA.addBack(1111);
   dA.addBack(1112);
   dA.addBack(1113);
   dA.addBack(1114);
   dA.addBack(1115);
   dA.addBack(1116);
   dA.addBack(1117);
   dB.addBack(1111);
   dB.addBack(1112);
   dB.addBack(1113);
   dB.addBack(1114);
   dB.addBack(1115);
   dB.addBack(1116);
   dB.addBack(1117);
   EXPECT_EQ(dA.length(), dB.length());
   EXPECT_TRUE(dA == dB) << "same values in the same order";
   EXPECT_TRUE(dB == dA) << "same values in the same order";
}
TEST(equalsTest, addFrontSameSameLengthOneDifferentValueFail) {
   D dA, dB;
   dA.addFront(1);
   dA.addFront(2);
   dA.addFront(3);
   dA.addFront(4);
   dA.addFront(5);
   dA.addFront(6);
   dA.addFront(7);

   dB.addFront(1);
   dB.addFront(2);
   dB.addFront(-100);
   dB.addFront(4);
   dB.addFront(5);
   dB.addFront(6);
   dB.addFront(7);

   EXPECT_EQ(dA.length(), dB.length());
   EXPECT_FALSE(dA == dB) << "same values in the same order except for 1 value";
   EXPECT_FALSE(dB == dA) << "same values in the same order except for 1 value";
}
TEST(equalsTest, addFrontaddBack1Fail) {
   D dA;
   dA.addBack(1);
   D dB;
   dB.addFront(5);
   EXPECT_FALSE(dA == dB);
   EXPECT_FALSE(dB == dA); 
}
TEST(equalsTest, addFrontaddBackFail) {
   D dA;
   dA.addBack(-1987);
   dA.addBack(-1256);
   D dB;
   dB.addFront(-1987);
   dB.addFront(-1256);
   EXPECT_FALSE(dA == dB);
   EXPECT_FALSE(dB == dA);
}
TEST(equalsTest, addFrontaddBackSame) {
   D dA;
   dA.addBack(-987);
   dA.addBack(-256);
   D dB;
   dB.addFront(-256);
   dB.addFront(-987);
   EXPECT_TRUE(dA == dB);
   EXPECT_TRUE(dB == dA); 
}
TEST(equalsTest, FirstLongerFail) {
   D dA;
   dA.addBack(1);
   dA.addBack(2);
   dA.addBack(3);
   dA.addBack(4);
   D dB;
   dB.addBack(1);
   dB.addBack(2);
   EXPECT_FALSE(dA == dB);
   EXPECT_FALSE(dB == dA); 
}
TEST(equalsTest, SecondLongerFail) {
   D dA;
   dA.addFront(1);
   dA.addFront(2);
   D dB;
   dB.addFront(1);
   dA.addFront(2);
   dA.addFront(3);
   dA.addFront(4);
   EXPECT_FALSE(dA == dB);
   EXPECT_FALSE(dB == dA); 
}
//-----------------------------------------------------------------
// big3CopyConstructorTest
//    depends on isEmpty
//    depends on length
//    depends on addBack
//    depends on addFront
//    depends on remBack
//    depends on remFront
//-----------------------------------------------------------------
TEST(big3CopyConstructorTest, SameLength) {
   if (skip_big3Tests) GTEST_SKIP();
   D d;
   d.addBack(1);
   d.addFront(2);
   d.addBack(5);
   d.addBack(4);
   d.addFront(5);
   ASSERT_EQ(d.length(), 5);
   D copied(d);
   EXPECT_EQ(copied.length(), 5);
}
TEST(big3CopyConstructorTest, EmptyList) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   D dB;
   ASSERT_TRUE(dA.isEmpty());
   ASSERT_TRUE(dB.isEmpty());
   dB = dA;
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_TRUE(dB.isEmpty());
}
TEST(big3CopyConstructorTest, OneElementRemoveFront) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(911);
   D dB = dA;
   EXPECT_EQ(dA.length(), 1);
   EXPECT_EQ(dB.length(), 1);
   EXPECT_EQ(dA.remFront(), 911);
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_FALSE(dB.isEmpty());
   EXPECT_EQ(dB.remFront(), 911);
   EXPECT_TRUE(dB.isEmpty());
}
TEST(big3CopyConstructorTest, OneElementRemoveBack) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(911);
   D dB = dA;
   EXPECT_EQ(dA.length(), 1);
   EXPECT_EQ(dB.length(), 1);
   EXPECT_EQ(dA.remBack(), 911);
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_FALSE(dB.isEmpty());
   EXPECT_EQ(dB.remBack(), 911);
   EXPECT_TRUE(dB.isEmpty());
}
TEST(big3CopyConstructorTest, RemoveFromOriginal) {
   if (skip_big3Tests) GTEST_SKIP();
   D d;
   d.addBack(11);
   d.addBack(22);
   d.addBack(33);
   d.addBack(44);
   D copied(d);
   EXPECT_EQ(d.length(), 4);
   EXPECT_EQ(copied.length(), 4);
   d.remFront();
   d.remFront();
   d.remFront();
   EXPECT_EQ(d.length(), 1);
   EXPECT_EQ(copied.length(), 4);
}
TEST(big3CopyConstructorTest, RemoveFromCopy) {
   if (skip_big3Tests) GTEST_SKIP();
   D d;
   d.addBack(11);
   d.addBack(22);
   d.addBack(33);
   d.addBack(44);
   D copied(d);
   EXPECT_EQ(d.length(), 4);
   EXPECT_EQ(copied.length(), 4);
   copied.remFront();
   copied.remFront();
   copied.remFront();
   EXPECT_EQ(d.length(), 4);
   EXPECT_EQ(copied.length(), 1);
}
TEST(big3CopyConstructorTest, EmptyOriginalThrow) {
   if (skip_big3Tests) GTEST_SKIP();
   D d;
   d.addBack(11);
   D copied(d);
   d.remFront();
   EXPECT_FALSE(copied.isEmpty());
   EXPECT_TRUE(d.isEmpty());
   EXPECT_THROW(d.remFront(), DException);
}
TEST(big3CopyConstructorTest, EmptyCopiedThrow) {
   if (skip_big3Tests) GTEST_SKIP();
   D d;
   d.addBack(11);
   D copied(d);
   copied.remFront();
   EXPECT_FALSE(d.isEmpty());
   EXPECT_TRUE(copied.isEmpty());
   EXPECT_THROW(copied.remFront(), DException);
}
//-----------------------------------------------------------------
// big3OverloadedAssgnOpTest
//    depends on isEmpty
//    depends on length
//    depends on addBack
//    depends on addFront
//    depends on remBack
//    depends on remFront
//-----------------------------------------------------------------
TEST(big3OverloadedAssgnOpTest, EmptyLists) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   ASSERT_TRUE(dA.isEmpty());
   D dB;
   ASSERT_TRUE(dB.isEmpty());
   dA = dB;
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_TRUE(dB.isEmpty());
}
TEST(big3OverloadedAssgnOpTest, EmptyTheFirst) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(1);
   dA.addBack(2);
   dA.addBack(3);
   dA.addBack(4);
   D dB;
   dB = dA;
   EXPECT_EQ(dA.remFront(), 1);
   EXPECT_EQ(dA.remFront(), 2);
   EXPECT_EQ(dA.remFront(), 3);
   EXPECT_EQ(dA.remFront(), 4);
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_FALSE(dB.isEmpty());
   EXPECT_EQ(dA.length(), 0);
   EXPECT_EQ(dB.length(), 4);
}
TEST(big3OverloadedAssgnOpTest, EmptyTheSecond) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(1);
   dA.addBack(2);
   dA.addBack(3);
   dA.addBack(4);
   dA.addBack(5);
   D dB;
   dB = dA;
   EXPECT_EQ(dB.remFront(), 1);
   EXPECT_EQ(dB.remFront(), 2);
   EXPECT_EQ(dB.remFront(), 3);
   EXPECT_EQ(dB.remFront(), 4);
   EXPECT_EQ(dB.remFront(), 5);
   EXPECT_TRUE(dB.isEmpty());
   EXPECT_FALSE(dA.isEmpty());
   EXPECT_EQ(dB.length(), 0);
   EXPECT_EQ(dA.length(), 5);
}
TEST(big3OverloadedAssgnOpTest, DWithOneElement) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(-1);
   D dB;
   dB = dA;
   EXPECT_EQ(dA.remFront(), -1);
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_FALSE(dB.isEmpty());
   EXPECT_EQ(dB.remFront(), -1);
   EXPECT_TRUE(dB.isEmpty());
}
// TEST(big3OverloadedAssgnOpTest, SelfAssignment) {
//    if (skip_big3Tests) GTEST_SKIP();
//    D dA;
//    dA.addBack(1);
//    dA.addBack(2);
//    dA.addBack(3);
//    dA = dA;
//    EXPECT_FALSE(dA.isEmpty());
//    EXPECT_EQ(dA.length(), 3);
//    dA.remFront();
//    dA = dA;
//    EXPECT_FALSE(dA.isEmpty());
//    EXPECT_EQ(dA.length(), 2);
//    dA.remFront();
//    dA = dA;
//    EXPECT_FALSE(dA.isEmpty());
//    EXPECT_EQ(dA.length(), 1);
//    dA.remFront();
//    dA = dA;
//    EXPECT_TRUE(dA.isEmpty());
// }
TEST(big3OverloadedAssgnOpTest, DFromLeftSide) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(11);
   dA.addBack(22);
   dA.addBack(33);
   dA.addBack(44);
   D dB;
   dB.addBack(-1);
   dB.addBack(-2);
   dB.addBack(-3);
   dB.addBack(-4);
   dB.addBack(-5);
   dA = dB;
   EXPECT_EQ(dA.length(), 5);
   EXPECT_EQ(dB.length(), 5);
   dA.remFront();
   dA.remFront();
   dA.remFront();
   dA.remFront();
   EXPECT_EQ(dA.length(), 1);
   EXPECT_EQ(dB.length(), 5);
}
TEST(big3OverloadedAssgnOpTest, DFromRightSide) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(11);
   dA.addBack(22);
   dA.addBack(33);
   dA.addBack(44);
   D dB;
   dB.addBack(-1);
   dB.addBack(-2);
   dB.addBack(-3);
   dB.addBack(-4);
   dB.addBack(-5);
   dA = dB;
   EXPECT_EQ(dA.length(), 5);
   EXPECT_EQ(dB.length(), 5);
   dB.remFront();
   dB.remFront();
   dB.remFront();
   dB.remFront();
   EXPECT_EQ(dA.length(), 5);
   EXPECT_EQ(dB.length(), 1);
}
TEST(big3OverloadedAssgnOpTest, EndToLeftSide) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(11);
   dA.addBack(22);
   dA.addBack(33);
   dA.addBack(44);
   D dB;
   dB.addBack(-1);
   dB.addBack(-2);
   dB.addBack(-3);
   dB.addBack(-4);
   dB.addBack(-5);
   dA = dB;
   EXPECT_EQ(dA.length(), 5);
   EXPECT_EQ(dB.length(), 5);
   dA.addBack(55);
   dA.addBack(66);
   dA.addBack(77);
   EXPECT_EQ(dA.length(), 8);
   EXPECT_EQ(dB.length(), 5);
}
TEST(big3OverloadedAssgnOpTest, EndToRightSide) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(11);
   D dB;
   dB.addBack(-1);
   dB.addBack(-2);
   dB.addBack(-3);
   dB.addBack(-4);
   dA = dB;
   EXPECT_EQ(dA.length(), 4);
   EXPECT_EQ(dB.length(), 4);
   dB.addBack(55);
   dB.addBack(66);
   dB.addBack(77);
   dB.addBack(88);
   dB.addBack(99);
   EXPECT_EQ(dA.length(), 4);
   EXPECT_EQ(dB.length(), 9);
}
TEST(big3OverloadedAssgnOpTest, EmptyLeftSideThrow) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(11);
   D dB;
   dB.addBack(-1);
   dA = dB;
   dA.remFront();
   EXPECT_FALSE(dB.isEmpty());
   EXPECT_TRUE(dA.isEmpty());
   EXPECT_THROW(dA.remFront(), DException);
}
TEST(big3OverloadedAssgnOpTest, EmptyRightSideThrow) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addBack(11);
   D dB;
   dB.addBack(-1);
   dA = dB;
   dB.remFront();
   EXPECT_FALSE(dA.isEmpty());
   EXPECT_TRUE(dB.isEmpty());
   EXPECT_THROW(dB.remFront(), DException);
}
//-----------------------------------------------------------------
// big3DestructorTest
//    depends on isEmpty
//    depends on length
//    depends on addBack
//    depends on addFront
//    depends on remBack
//    depends on remFront
//-----------------------------------------------------------------
TEST(big3DestructorTest, Empty) {
   if (skip_big3Tests) GTEST_SKIP();
   D d;
}
TEST(big3DestructorTest, EmptyInner) {
   if (skip_big3Tests) GTEST_SKIP();
   {
         D d;
   }
}
TEST(big3DestructorTest, EmptyDequeueAtFirstGoesOutOfScope) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   EXPECT_EQ(dA.length(), 0);
   {
      D dB;
      dB.addBack(-1);
      EXPECT_TRUE(dA.isEmpty());
      dB.addBack(-2);
      EXPECT_TRUE(dA.isEmpty());
      dB.addBack(-3);
      EXPECT_TRUE(dA.isEmpty());
      dA.addFront(100);
      EXPECT_FALSE(dA.isEmpty());
      dA.addBack(200);
      EXPECT_FALSE(dA.isEmpty());
      dA.addFront(300);
      EXPECT_FALSE(dA.isEmpty());
      EXPECT_EQ(dA.length(), 3);
      EXPECT_EQ(dB.length(), 3);
   }
   EXPECT_FALSE(dA.isEmpty());
   EXPECT_EQ(dA.length(), 3);
}

TEST(big3DestructorTest, Df3GoesOutOfScope) {
   if (skip_big3Tests) GTEST_SKIP();
   D dA;
   dA.addFront(1);
   dA.addBack(2);
   dA.addFront(3);
   dA.addBack(4);
   ASSERT_EQ(dA.length(), 4);
   {
      D dB;
      dB.addBack(-1);
      dB.addFront(-2);
      dB.addBack(-3);
      ASSERT_EQ(dA.length(), 4);
      ASSERT_EQ(dB.length(), 3);
      dB.remFront();
   }
   EXPECT_EQ(dA.length(), 4);
   dA.remFront();
   EXPECT_EQ(dA.length(), 3);
   dA.remBack();
   EXPECT_EQ(dA.length(), 2);
   dA.remFront();
   EXPECT_EQ(dA.length(), 1);
   dA.remBack();
   EXPECT_EQ(dA.length(), 0);
}
TEST(big3DestructorTest, WithPointer) {
   if (skip_big3Tests) GTEST_SKIP();
   D* q = new D;
   q->addBack(-6);
   q->addBack(-5);
   q->addFront(-4);
   q->addFront(-3);
   q->addBack(-2);
   q->addBack(-1);
   delete q; // calls the destructor
   q = new D;
   delete q; // calls the destructor again .... it should not crash
}


