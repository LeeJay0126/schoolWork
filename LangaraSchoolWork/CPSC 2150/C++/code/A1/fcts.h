// CPSC 2150  Assignment #1
// Do not modify.
// Do not post anywhere.
// Name: Gladys Monagan

#ifndef FCTS_H
#define FCTS_H

#include <iostream>
#include <string>

bool isStrictlyDescending(const int A[], int n);

void swapPairsLeftToRight(int A[], int n);

void outputAsHex(unsigned int n, std::ostream& out = std::cout);

void outInOctal(unsigned int n, std::ostream& out = std::cout);

bool insideInOrder(const std::string& pattern, int m, const std::string& str);

// iterative version with loops
bool insideInOrderI(const std::string& pattern, int m, const std::string& str);

#endif

// copyright 2023 Gladys Monagan 