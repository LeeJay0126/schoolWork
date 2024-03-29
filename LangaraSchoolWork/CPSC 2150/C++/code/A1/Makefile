# A Makefile for using Google Test and building a unit test program 
# as well as a test program that is independent of Google Test
# Author: Gladys Monagan
# Do not post anywhere
# based on the old Google Test distribution sample Makefiles
#
# SYNOPSIS:
#   make [all]  - makes everything.
#   make clean  - removes all files generated by make, for Windows
#   make remove - removes all files generated by make, for UNIX/Linux
#   make run    - makes everything and runs the built unit test program, for Windows
#   make check  - makes everything and runs the built unit test program, for UNIX/Linux
#   make test   - make a test main program (no Google Test)

.PHONY: all clean remove run check test

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ../..

# Where to find user code.
USER_DIR = .

#DEBUG  = -g

VERSION = -std=c++17
CXX = g++

# Flags passed to the preprocessor.
# We have no idea here whether pthreads is available in the system, so disable its use.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS = -I$(GTEST_DIR)/include -DGTEST_HAS_PTHREAD=0

# Flags passed to the C++ compiler.
CXXFLAGS = $(CPPFLAGS) -pedantic -Wall -Wextra  $(DEBUG) $(VERSION)

LFLAGS = $(DEBUG) $(VERSION)

# Where to find gtest_main.cc.
GTEST_MAIN_CC = $(GTEST_DIR)/gtest_main.cc

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

SRC = fcts

# a main program that runs with the Google Tests
UNITTEST = unittest_$(SRC)

# a main that produces a main executable without Google Tests
TEST_PROG = test_$(SRC)

# House-keeping build targets.
all : $(UNITTEST)

check : all
	./$(UNITTEST)

run : all
	$(UNITTEST).exe

remove :
	rm -f $(UNITTEST) $(TEST_PROG) *.o

clean :
	del $(UNITTEST).exe $(TEST_PROG).exe *.o  /Q

test : $(TEST_PROG)

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

$(SRC).o : $(USER_DIR)/$(SRC).cpp $(USER_DIR)/$(SRC).h
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/$(SRC).cpp

$(UNITTEST).o : $(USER_DIR)/$(UNITTEST).cpp  \
                  $(USER_DIR)/$(SRC).h \
                  $(GTEST_HEADERS)
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/$(UNITTEST).cpp

$(UNITTEST) : $(SRC).o $(UNITTEST).o gtest-all.o gtest_main.o
	$(CXX) $(LFLAGS) $(CXXFLAGS) $^ -o $@

$(TEST_PROG).o : $(USER_DIR)/$(TEST_PROG).cpp  \
                  $(USER_DIR)/$(SRC).h 
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/$(TEST_PROG).cpp

$(TEST_PROG): $(SRC).o $(TEST_PROG).o
	$(CXX) $(LFLAGS) $^ -o $@

# copyright 2023 Gladys Monagan

