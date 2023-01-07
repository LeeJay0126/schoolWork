// Name: 
/*

to run only the toIntegerITest suite

unittest_lfcts --gtest_filter="toIntegerITest.*"

or on Linux

./unittest_lfcts --gtest_filter="toIntegerITest.*"

to run all the tests BUT NOT the toIntegerITest suite 
(note the minus sign before toIntegerITest)

unittest_lfcts --gtest_filter="-toIntegerITest.*"

or on Linux

./unittest_lfcts --gtest_filter="-toIntegerITest.*"

*/

#include <string>
#include <iostream>
#include <climits>     // INT_MAX
#include "gtest/gtest.h"
#include "lfcts.h"

using std::string, std::cout;

//-----------------------------------------------------------------
// toIntegerI: iterative version
// precondition: 
//     every character of the argument is numeric
//     there are no white spaces in the argument
//     there is no unary operator
//     argument represents a positive integer or 0
//-----------------------------------------------------------------
TEST(toIntegerITest, TwoDigitsRepeats) {
   EXPECT_EQ(toIntegerI("99"), 99);
}


//-----------------------------------------------------------------
// toInteger: recursive version
// precondition: 
//     every character of the argument is numeric
//     there are no white spaces in the argument
//     there is no unary operator
//     argument represents a positive integer or 0
//-----------------------------------------------------------------
TEST(toIntegerTest, TwoDigitsRepeats) {
   EXPECT_EQ(toInteger("99"), 99);
}

// copyright 2023 Gladys Monagan 
