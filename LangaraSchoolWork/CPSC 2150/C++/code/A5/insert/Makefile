
.PHONY: all clean remove runu check test

USER_DIR = .

VERSION = -std=c++17
CXX = g++

CPPFLAGS = $(CPPFLAGS) - pedantic -Wall -Wextra $(DEBUG) $(VERSION)

LFLAGS = $(DEBUG) $(VERSION)

GTEST_MAIN_CC = $(GTEST_DIR)/main.cc

SRC = Insert

TEST_PROG = time_$(SRC)

# House-keeping build targets.

clean :
	del $(TEST_PROG).exe *.o  /Q

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

$(TEST_PROG).o : $(USER_DIR)/$(TEST_PROG).cpp  \
                  $(USER_DIR)/$(SRC).h 
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/$(TEST_PROG).cpp

$(TEST_PROG): $(SRC).o $(TEST_PROG).o
	$(CXX) $(LFLAGS) $^ -o $@

