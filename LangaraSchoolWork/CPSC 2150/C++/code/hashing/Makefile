CXX = g++
#DEBUG = -g
VERSION = -std=c++17
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(VERSION)

INCS = hash_function.h
SRCS =  hash_function.cpp \
	experiments.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = experiments

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