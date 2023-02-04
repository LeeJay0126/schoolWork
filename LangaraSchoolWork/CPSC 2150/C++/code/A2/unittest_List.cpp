// if you did the bonus, uncomment the next statement
// #define BONUS

// A unit test for Langara CPSC 2150
// Assignment 2: Linked Lists
// C++ unit test framework: Google Test
// Author: Gladys Monagan
// Do not post anywhere.

/*
you may not need the "./" if you are
on a Windows Command Line (but yes in a Windows powershell)

to run only the insertTest suite do
./unittest_List --gtest_filter="insertTest.*"

to run all the tests BUT the insertTest suite do (note the minus sign)
./unittest_List --gtest_filter="-insertTest.*"

to run all the tests that have to do with an EmptyList
./unittest_List --gtest_filter="*.*EmptyList*"

*/

#include "List.h"
#include "gtest/gtest.h"
#include <string>
using namespace std;

// return a string concatenating [----ERROR-] and msg
string error(string msg)
{
   return "[  ERROR   ] " + msg;
}

// I have put the dependencies meaning that if the << operator
// is not functioning, then even if the constructor is building
// properly an empty list, the constructorTest will fail

//-----------------------------------------------------------------
// constructorTest
//    depends on the << operator
//-----------------------------------------------------------------
TEST(constructorTest, DefaultConstructor)
{
   List a;
   stringstream actual;
   actual << a;
   cout << a << endl;
   stringstream expected;
   expected << List::START << List::END;
   cout << expected.str() << "    " << actual.str() << endl;
   EXPECT_EQ(expected.str(), actual.str()) << error("the constructor should have made an empty list");
}

//-----------------------------------------------------------------
// isEmptyTest
//    depends on insert, removeAll, the << operator
//-----------------------------------------------------------------
// TEST(isEmptyTest, SpecialCaseEmptyList) {
//    List a;
//    EXPECT_TRUE(a.isEmpty()) <<
//       error("a new list should be empty");
// }
// TEST(isEmptyTest, NoElementsInsertAndThenRemove) {
//    List a;
//    a.insert(-100);
//    EXPECT_TRUE(a.removeAll(-100));
//    EXPECT_TRUE(a.isEmpty()) <<
//       error("inserting and removing should give an empty list");
//    // making sure that b is separate from a
//    List b;
//    b.insert(200);
//    EXPECT_FALSE(b.removeAll(-100));
//    EXPECT_FALSE(b.isEmpty()) <<
//       error("b is not empty but a is");
// }
// TEST(isEmptyTest, RemoveANonExistentElementFail) {
//    List a;
//    EXPECT_FALSE(a.removeAll(0));
//    EXPECT_TRUE(a.isEmpty()) <<
//       error("trying to remove from an empty list");
//    // making sure that b is separate from a
//    List b;
//    EXPECT_FALSE(b.removeAll(-1));
//    EXPECT_TRUE(b.isEmpty()) <<
//       error("trying to remove but since not there => empty list");
// }

// //-----------------------------------------------------------------
// // insertTest
// //    depends on the << operator
// //-----------------------------------------------------------------
// TEST(insertTest, 1ElementSpecialCase) {
//    List a;
//    a.insert(11);
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START << 11 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }
// TEST(insertTest, 2ElementsBorderCase) {
//    List a;
//    a.insert(-1);
//    a.insert(1);
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START << -1 << a.sep() << 1 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }
// TEST(insertTest, 3ElementsOddNumber) {
//    List a;
//    a.insert(-1);
//    a.insert(1);
//    a.insert(0);
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START
//       << -1 << a.sep() << 0 << a.sep()
//       << 1 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }

// //-----------------------------------------------------------------
// // set_sepTest
// //    depends on the << operator
// //-----------------------------------------------------------------
// TEST(set_sepTest, changeSeparator) {
//    List a;
//    a.set_sep(",");
//    a.insert(3);
//    a.insert(6);
//    a.insert(3);
//    a.insert(3);
//    a.insert(6);
//    a.insert(2);
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START
//       << 2 << "," << 3 << ","
//       << 3 << "," << 3 << "," << 6 << ","
//       << 6 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
//    actual.clear();
//    actual.str(string());
//    expected.clear();
//    expected.str(string());
//    a.set_sep("/");
//    actual << a;
//    expected << List::START
//       << 2 << "/" << 3 << "/"
//       << 3 << "/" << 3 << "/" << 6 << "/"
//       << 6 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }

// //-----------------------------------------------------------------
// // lengthTest
// //    depends on insert and the << operator
// //-----------------------------------------------------------------
// TEST(lengthTest, SpecialCaseEmptyList) {
//    List a;
//    EXPECT_EQ(a.length(), 0) << error("A new list should have a length of 0");
// }
// TEST(lengthTest, 1ElementBoundaryCase) {
//    List a;
//    a.insert(11);
//    EXPECT_EQ(a.length(), 1) << error("should be 1, after inserting 1 item.");
//    // making sure that b is separate from a
//    List b;
//    b.insert(33);
//    EXPECT_EQ(b.length(), 1) << error("should be 1, after inserting 1 item.");
// }
// TEST(lengthTest, 2Elements) {
//    List a;
//    a.insert(22);
//    a.insert(11);
//    EXPECT_EQ(a.length(), 2) << error("should be 2, after inserting 2 items.");
// }
// TEST(lengthTest, 3ElementsOddNumber) {
//    List a;
//    a.insert(33);
//    a.insert(22);
//    a.insert(11);
//    EXPECT_EQ(a.length(), 3) << error("should be 3, after inserting 3 items.");
//    // making sure that b is separate from a
//    List b;
//    b.insert(44);
//    b.insert(55);
//    b.insert(77);
//    b.insert(66);
//    EXPECT_EQ(b.length(), 4) << error("should be 4, after inserting 4 items.");
// }
// TEST(lengthTest, Many) {
//    List a;
//    const int N = 299;
//    for (int i = 0; i < N; i++)
//       a.insert(i);
//    EXPECT_EQ(a.length(), N);
// }

// //-----------------------------------------------------------------
// // searchTest
// //    depends on insert and the << operator
// //-----------------------------------------------------------------
// TEST(searchTest, MiddleElementFound) {
//    List a;
//    a.insert(55);
//    a.insert(11);
//    a.insert(22);
//    a.insert(33);
//    a.insert(44);
//    EXPECT_TRUE(a.search(22)) << error("should find 22 in ") << a;
//    EXPECT_TRUE(a.search(33)) << error("should find 33 in ") << a;
//    EXPECT_TRUE(a.search(44)) << error("should find 44 in ") << a;
// }
// TEST(searchTest, RepeatsFound) {
//    List a;
//    EXPECT_FALSE(a.search(11)) << error("should not find 11 in ") << a;
//    a.insert(11);
//    EXPECT_TRUE(a.search(11)) << error("should find 11 in ") << a;
//    a.insert(11);
//    EXPECT_TRUE(a.search(11)) << error("should find 11 in ") << a;
//    a.insert(22);
//    EXPECT_TRUE(a.search(22)) << error("should find 22 in ") << a;
//    EXPECT_TRUE(a.search(11)) << error("should find 11 in ") << a;
// }

// //-----------------------------------------------------------------
// // firstTest
// //    depends on insert
// //-----------------------------------------------------------------
// TEST(firstTest, MoreElements) {
//    List a;
//    a.insert(7);
//    EXPECT_EQ(a.first(), 7);
//    a.insert(1);
//    EXPECT_EQ(a.first(), 1);
//    a.insert(3);
//    EXPECT_EQ(a.first(), 1);
//    a.insert(4);
//    EXPECT_EQ(a.first(), 1);
//    a.insert(5);
//    EXPECT_EQ(a.first(), 1);
// }

// //-----------------------------------------------------------------
// // lastTest
// //    depends on insert
// //-----------------------------------------------------------------
// TEST(lastTest, MoreElements) {
//    List a;
//    a.insert(1);
//    EXPECT_EQ(a.last(), 1);
//    a.insert(2);
//    EXPECT_EQ(a.last(), 2);
//    a.insert(-1);
//    EXPECT_EQ(a.last(), 2);
//    a.insert(3);
//    EXPECT_EQ(a.last(), 3);
//    a.insert(5);
//    EXPECT_EQ(a.last(), 5);
// }

// //-----------------------------------------------------------------
// // oddsTest
// //    depends on insert, isEmpty, length, removeAll, the << operator
// //-----------------------------------------------------------------
// TEST(oddsTest, TypicalLength5) {
//    List a;
//    a.insert(11);
//    a.insert(22);
//    a.insert(33);
//    a.insert(44);
//    a.insert(55);
//    List resList = a.odds();
//    ASSERT_EQ(a.length(), 5);
//    ASSERT_EQ(resList.length(), 3);
//    stringstream actual;
//    actual << resList;
//    stringstream expected;
//    expected << List::START
//       << 11 << a.sep() << 33 << a.sep()
//       << 55 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }

// //-----------------------------------------------------------------
// // evensTest
// //    depends on insert, isEmpty, length, removeAll, the << operator
// //-----------------------------------------------------------------
// TEST(evensTest, TypicalLength5) {
//    List a;
//    a.insert(11);
//    a.insert(22);
//    a.insert(33);
//    a.insert(44);
//    a.insert(55);
//    List resList = a.evens();
//    ASSERT_EQ(a.length(), 5);
//    ASSERT_EQ(resList.length(), 2);
//    stringstream actual;
//    actual << resList;
//    stringstream expected;
//    expected << List::START
//       << 22 << a.sep()
//       << 44 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }

// //-----------------------------------------------------------------
// // removeAllTest
// //    depends on insert, isEmpty, the << operator
// //-----------------------------------------------------------------
// TEST(removeAllTest, SpecialCaseEmptyListFail) {
//    List a;
//    EXPECT_FALSE(a.removeAll(-62)) <<
//       error("cannot remove from empty list");
// }
// TEST(removeAllTest, 1ElementBorderCaseSuccess) {
//    List a;
//    a.insert(-97);
//    EXPECT_TRUE(a.removeAll(-97)) <<
//       error("failed to remove -97 from ") << a;
// }
// TEST(removeAllTest, 1ElementBorderCaseFail) {
//    List a;
//    a.insert(-75);
//    EXPECT_FALSE(a.removeAll(-13)) <<
//       error("should have failed when removing -13 from ") << a;
// }
// TEST(removeAllTest, RemoveAllSameReturnValueSuccess) {
//    List a;
//    a.insert(11);
//    a.insert(11);
//    a.insert(11);
//    EXPECT_TRUE(a.removeAll(11));
//    EXPECT_TRUE(a.isEmpty()) << error("all 11's should be removed");
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START<< List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }
// TEST(removeAllTest, LastElementReturnValueSuccess) {
//    List a;
//    a.insert(1);
//    a.insert(2);
//    a.insert(3);
//    a.insert(4);
//    a.insert(5);
//    a.insert(6);
//    a.insert(7);
//    EXPECT_TRUE(a.removeAll(7)) <<
//       error("failed to return true when 7 was removed: ") << a;
// }
// TEST(removeAllTest, LastElement) {
//    List a;
//    a.insert(1);
//    a.insert(2);
//    a.insert(3);
//    a.insert(4);
//    a.insert(6);
//    a.insert(5);
//    a.insert(7);
//    a.removeAll(7);
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START
//       << 1 << a.sep() << 2 << a.sep() << 3 << a.sep()
//       << 4 << a.sep() << 5 << a.sep()
//       << 6 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }

// //-----------------------------------------------------------------
// // equalsTest
// //    depends on insert and the << operator
// //-----------------------------------------------------------------
// TEST(equalsTest, SpecialCaseEmptyLists) {
//    List a, b;
//    EXPECT_TRUE(a == b) <<
//       error("two empty lists are equal");
// }
// TEST(equalsTest, SameLengthDifferentValuesFail) {
//    List a, b;
//    a.insert(7);
//    a.insert(10);
//    b.insert(-2);
//    b.insert(3);
//    stringstream a_ss;
//    a_ss << a;
//    stringstream b_ss;
//    b_ss << b;
//    EXPECT_FALSE(a == b) <<
//       error(a_ss.str() + " is not equal to " + b_ss.str());
//    EXPECT_FALSE(b == a) <<
//       error(b_ss.str() + " is not equal to " + a_ss.str());
// }
// TEST(equalsTest, SameLengthSameValues) {
//    List a, b;
//    a.insert(2);
//    a.insert(3);
//    b.insert(3);
//    b.insert(2);
//    stringstream a_ss;
//    a_ss << a;
//    stringstream b_ss;
//    b_ss << b;
//    EXPECT_TRUE(a == b) <<
//       error(a_ss.str() + " is equal to " + b_ss.str());
//    EXPECT_TRUE(b == a) <<
//       error(b_ss.str() + " is equal to " + a_ss.str());
// }

// //-----------------------------------------------------------------
// // notEqualsTest
// //    depends on insert and the << operator
// //-----------------------------------------------------------------
// TEST(notEqualsTest, SpecialCaseEmptyLists) {
//    List a, b;
//    EXPECT_FALSE(a != b) <<
//       error("it is false that two empty lists are not equal");
// }
// TEST(notEqualsTest, SameLengthSameValuesFail) {
//    List a, b;
//    a.insert(2);
//    a.insert(3);
//    b.insert(3);
//    b.insert(2);
//    stringstream a_ss;
//    a_ss << a;
//    stringstream b_ss;
//    b_ss << b;
//    EXPECT_FALSE(a != b) <<
//       error(a_ss.str() + " is equal to " + b_ss.str());
//    EXPECT_FALSE(b != a) <<
//       error(b_ss.str() + " is equal to " + a_ss.str());
// }
// TEST(notEqualsTest, SameLengthDifferentValues) {
//    List a, b;
//    a.insert(7);
//    a.insert(10);
//    b.insert(-2);
//    b.insert(3);
//    stringstream a_ss;
//    a_ss << a;
//    stringstream b_ss;
//    b_ss << b;
//    EXPECT_TRUE(a != b) <<
//       error(a_ss.str() + " is not equal to " + b_ss.str());
//    EXPECT_TRUE(b != a) <<
//       error(b_ss.str() + " is not equal to " + a_ss.str());
// }

// //-----------------------------------------------------------------
// // copyConstructor
// //    depends on insert, removeAll and the << operator
// //-----------------------------------------------------------------
// TEST(copyConstructorTest, SpecialCaseEmptyList) {
//    List a;
//    List copiedList = a; // calls the copy constructor
//    stringstream a_ss;
//    a_ss << a;
//    stringstream copied_ss;
//    copied_ss << copiedList;
//    EXPECT_EQ(a_ss.str(), copied_ss.str()) << error("failed to copy properly");
// }
// TEST(copyConstructorTest, ListWithElementsModifyOriginal) {
//    List a;
//    a.insert(33);
//    a.insert(22);
//    a.insert(11);
//    List copiedList(a); // calls the copy constructor
//    stringstream a_ss;
//    a_ss << a;
//    stringstream copied_ss;
//    copied_ss << copiedList;
//    ASSERT_EQ(a_ss.str(), copied_ss.str()) << error("failed to copy");
//    // modify the original a which should then be different from copiedList
//    EXPECT_TRUE(a.removeAll(11));
//    EXPECT_TRUE(a.removeAll(33));
//    stringstream modified_a_ss;
//    modified_a_ss << a;
//    stringstream ssc;
//    ssc << copiedList;
//    EXPECT_NE(modified_a_ss.str(), ssc.str()) << error("failed to copy");
//    stringstream a_ss_expected;
//    a_ss_expected << List::START
//       << 22 << List::END;
//    EXPECT_EQ(modified_a_ss.str(), a_ss_expected.str());
//    stringstream expected_ssc;
//    expected_ssc << List::START
//       << 11 << a.sep() << 22 << a.sep()
//       << 33 << List::END;
//    EXPECT_EQ(ssc.str(), expected_ssc.str());
// }
// TEST(copyConstructorTest, ListWithElementsModifyCopy) {
//    List a;
//    a.insert(33);
//    a.insert(22);
//    a.insert(11);
//    List copiedList(a); // calls the copy constructor
//    stringstream a_ss;
//    a_ss << a;
//    stringstream copied_ss;
//    copied_ss << copiedList;
//    ASSERT_EQ(a_ss.str(), copied_ss.str()) << error("failed to copy");
//    // modify the copied list which should then be different from a
//    EXPECT_TRUE(copiedList.removeAll(11));
//    EXPECT_TRUE(copiedList.removeAll(33));
//    stringstream modified_copied_ss;
//    modified_copied_ss << copiedList;
//    stringstream ssa;
//    ssa << a;
//    EXPECT_NE(modified_copied_ss.str(), ssa.str()) << error("failed to copy");
//    stringstream expected_ssa;
//    expected_ssa << List::START
//       << 11 << a.sep() << 22 << a.sep()
//       << 33 << List::END;
//    EXPECT_EQ(ssa.str(), expected_ssa.str());
//    stringstream modified_copiedList_expected_ss;
//    modified_copiedList_expected_ss << List::START
//       << 22 << List::END;
//    EXPECT_EQ(modified_copied_ss.str(), modified_copiedList_expected_ss.str());
// }

// //-----------------------------------------------------------------
// // overloadedAssgnOpTest
// //    depends on insert, isEmpty, search, removeAll, the << operator
// //-----------------------------------------------------------------
// TEST(overloadedAssgnOpTest, ListsWith1Element) {
//    List lfSide;
//    List rtSide;
//    lfSide.insert(17);
//    stringstream lfSide_ss; lfSide_ss << lfSide;
//    stringstream rtSide_ss; rtSide_ss << rtSide;
//    ASSERT_TRUE(lfSide.search(17)) <<
//       error("should find 17 => original lfSide not built properly");
//    ASSERT_FALSE(rtSide.search(17)) <<
//       error("should NOT find 17 in the empty rtSide => rtSide not built properly");

//    rtSide.insert(99);
//    ASSERT_TRUE(rtSide.search(99)) <<
//       error("should find 99 => cons on rtSide failed ") << rtSide;
//    ASSERT_FALSE(lfSide.search(99)) <<
//       error("rtSide that was changed so should not find 99 in ") << lfSide;

//    lfSide = rtSide;
//    stringstream ssl; ssl << lfSide;
//    stringstream ssr; ssr << rtSide;
//    EXPECT_EQ(ssl.str(), ssr.str()) << error("failed in the overloading of = ");
//    EXPECT_FALSE(lfSide.search(17)) <<
//       error("should NO LONGER find 17 in ") << lfSide;
//    EXPECT_TRUE(rtSide.search(99)) <<
//       error("should find 99 in ") << rtSide;
//    EXPECT_TRUE(lfSide.search(99)) <<
//       error("should find 99 which was copied from ") << rtSide;
// }
// TEST(overloadedAssgnOpTest, ListWith1ElementRemove) {
//    List lfSide;
//    lfSide.insert(17);
//    List rtSide;
//    rtSide.insert(17);
//    lfSide = rtSide;
//    stringstream lfSide_ss; lfSide_ss << lfSide;
//    stringstream rtSide_ss; rtSide_ss << rtSide;
//    ASSERT_EQ(lfSide_ss.str(), rtSide_ss.str());
//    EXPECT_TRUE(rtSide.removeAll(17));
//    stringstream ssl; ssl << lfSide;
//    stringstream ssr; ssr << rtSide;
//    EXPECT_NE(ssl.str(), ssr.str());
// }
// TEST(overloadedAssgnOpTest, ListWithElements) {
//    List lfSide;
//    List rtSide;
//    lfSide.insert(44);
//    lfSide.insert(33);
//    lfSide.insert(22);
//    lfSide.insert(11);
//    rtSide.insert(44);
//    rtSide.insert(33);
//    rtSide.insert(22);
//    rtSide.insert(11);
//    stringstream lfSide_ss;
//    lfSide_ss << lfSide;
//    stringstream rtSide_ss;
//    rtSide_ss << rtSide;
//    ASSERT_EQ(lfSide_ss.str(), rtSide_ss.str());
//    lfSide = rtSide;
//    EXPECT_TRUE(lfSide.removeAll(33));
//    stringstream ssl; ssl << lfSide;
//    stringstream ssr; ssr << rtSide;
//    EXPECT_NE(ssl.str(), ssr.str());
// }
// TEST(overloadedAssgnOpTest, ListWithElementsModifyOriginal) {
//    List rtSide;
//    rtSide.insert(33);
//    rtSide.insert(22);
//    rtSide.insert(11);
//    List lfSide;
//    lfSide.insert(-99);
//    lfSide.insert(-98);
//    lfSide = rtSide;
//    stringstream lfSide_ss;
//    lfSide_ss << lfSide;
//    stringstream rtSide_ss;
//    rtSide_ss << rtSide;
//    EXPECT_EQ(rtSide_ss.str(), lfSide_ss.str())
//       << error("both lists should be equal");

//    // modify rtSide which should then be different from lfSide
//    EXPECT_TRUE(rtSide.removeAll(11));
//    EXPECT_TRUE(rtSide.removeAll(33));
//    stringstream ssl;
//    ssl << lfSide;
//    stringstream ssr;
//    ssr << rtSide;
//    EXPECT_NE(ssl.str(), ssr.str()) <<
//       error("assignment of rtSide was not done properly");
//    stringstream lexpected;
//    lexpected << List::START
//       << 11 << rtSide.sep() << 22 << rtSide.sep()
//       << 33 << List::END;
//    EXPECT_EQ(ssl.str(), lexpected.str());
//    stringstream rexpected;
//    rexpected << List::START<< 22 << List::END;
//    EXPECT_EQ(ssr.str(), rexpected.str());
// }
// TEST(overloadedAssgnOpTest, ListWithElementsModifyAssignedTo) {
//    List rtSide;
//    rtSide.insert(-33);
//    rtSide.insert(-22);
//    rtSide.insert(-11);
//    List lfSide;
//    lfSide.insert(-99);
//    lfSide.insert(-98);
//    lfSide = rtSide;
//    stringstream lfSide_ss;
//    lfSide_ss << lfSide;
//    stringstream rtSide_ss;
//    rtSide_ss << rtSide;
//    EXPECT_EQ(rtSide_ss.str(), lfSide_ss.str()) <<
//       error("both lists should be equal");

//    // modify lfSide which should then be different from rtSide
//    EXPECT_TRUE(lfSide.removeAll(-11));
//    EXPECT_TRUE(lfSide.removeAll(-33));

//    lfSide_ss.clear();
//    lfSide_ss.str(string());
//    lfSide_ss << lfSide;

//    rtSide_ss.clear();
//    rtSide_ss.str(string());
//    rtSide_ss << rtSide;

//    EXPECT_NE(lfSide_ss.str(), rtSide_ss.str()) <<
//       error("assignment of rtSide was not done properly");

//    stringstream lexpected;
//    lexpected << List::START << -22 << List::END;
//    EXPECT_EQ(lfSide_ss.str(), lexpected.str());

//    stringstream rexpected;
//    rexpected << List::START
//       << -33 << rtSide.sep() << -22 << rtSide.sep()
//       << -11 << List::END;
//    EXPECT_EQ(rtSide_ss.str(), rexpected.str());
// }

// //-----------------------------------------------------------------
// // destructorTest
// //    depends on insert, isEmpty, the << operator
// //-----------------------------------------------------------------
// TEST(destructorTest, SpecialCaseEmptyList) {
//    {
//       List a;
//       ASSERT_TRUE(a.isEmpty()) <<
//          error("should be empty => destructor test aborted");
//       // the destructor is called, list is going out of scope
//    }
//    List a;
//    EXPECT_TRUE(a.isEmpty()) << error("this new list should be empty");
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START+ List::END;
//    EXPECT_EQ(actual.str(), expected.str()) << error("the list should be empty");
// }
// TEST(destructorTest, ListWithElementsGoesOutOfScope) {
//    {
//       List a;
//       a.insert(1);
//       a.insert(2);
//       a.insert(3);
//       ASSERT_FALSE(a.isEmpty()) <<
//          error("list should not be empty => destructor test aborted");
//       // the destructor is called, list is going out of scope
//    }
//    List a;
//    EXPECT_TRUE(a.isEmpty()) << error("this new list should be empty");
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START+ List::END;
//    EXPECT_EQ(actual.str(), expected.str()) << error("the list should be empty");
// }
// TEST(destructorTest, WithPointer) {
//    List* p = new List;
//    ASSERT_TRUE(p->isEmpty())
//       << error("list pointed to should be empty => destructor test aborted");
//    p->insert(1);
//    p->insert(2);
//    p->insert(3);
//    p->insert(4);
//    p->insert(5);
//    delete p; // calling the destructor
//    p = new List;
//    EXPECT_TRUE(p->isEmpty()) << error("list pointed to should be empty");
//    stringstream actual;
//    actual << (*p);
//    stringstream expected;
//    expected << List::START+ List::END;
//    EXPECT_EQ(actual.str(), expected.str()) << error("the list should be empty");
//    delete p; // calling the destructor .... it should not crash!
// }

// #ifdef BONUS
// //-----------------------------------------------------------------
// // simplifyTest
// //    depends on insert, isEmpty, removeAll, length and the << operator
// //-----------------------------------------------------------------
// TEST(simplifyTest, NoDuplicates) {
//    List a;
//    a.insert(44);
//    a.insert(22);
//    a.insert(33);
//    a.insert(11);
//    a.insert(55);
//    ASSERT_EQ(a.length(), 5);
//    a.simplify();
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START
//       << 11 << a.sep() << 22 << a.sep()
//       << 33 << a.sep() << 44 << a.sep()
//       << 55 << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }
// TEST(simplifyTest, AllRepeats) {
//    List a;
//    a.insert(7);
//    a.insert(7);
//    a.insert(7);
//    a.insert(7);
//    a.insert(7);
//    a.insert(7);
//    ASSERT_EQ(a.length(), 6);
//    a.simplify();
//    stringstream actual;
//    actual << a;
//    stringstream expected;
//    expected << List::START
//       << 7
//       << List::END;
//    EXPECT_EQ(actual.str(), expected.str());
// }

// #endif

// // copyright 2023 Gladys Monagan
