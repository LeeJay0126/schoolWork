# filename: Makefile

OBJS = TestMain3.o SortLib.o
CC = g++

SortOut: $(OBJS)
	g++ -o SortOut $(OBJS)

SortLib.o: 
	g++ -c SortLib.cpp

TestMain2.o: 
	$(CC) -c TestMain3.cpp
	
clean:
	rm -f core SortOut $(OBJS)
