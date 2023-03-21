.PHONY: all clean remove solver

CXX = g++
VERSION = -std=c++17
#DEBUG = -g
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG) 
LFLAGS = -Wall $(DEBUG) $(VERSION) 

INCS = Term.h\
	Commands.h\
	Polynomial.h
SRCS = Term.cpp\
	Commands.cpp\
	Polynomial.cpp\
	solver.cpp

OBJS = $(SRCS:.cpp=.o)
#solver has the main program
EXEC = solver

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
