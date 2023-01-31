# having the option -DNDEBUG when compiling, means NO debugging occurs
# the next line should be a comment (starting with a #) if you want debugging
# NO_DEBUGGING_STATEMENTS = -DNDEBUG

#DEBUG  = -g
CXX = g++
VERSION = -std=c++17
CFLAGS = -pedantic -Wall -Wextra $(DEBUG) $(VERSION) $(NO_DEBUGGING_STATEMENTS)
LFLAGS = $(VERSION) $(DEBUG)

INCS = Vector.h
SRCS = Vector.cpp\
	testVector.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = testVector

all: $(SRCS) $(EXEC)

# To make an object from source
#.cpp.o: 
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS) 
	$(CXX) $(LFLAGS) $(OBJS) -o $@

# for Windows
clean:
	del *.o  $(EXEC).exe
	@echo clean done

# for UNIX / Linux 
remove:
	\rm -f *.o  $(EXEC)
	@echo clean done

# copyright 2023 Gladys Monagan

