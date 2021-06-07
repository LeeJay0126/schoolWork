OBJS = SortLib.o TestMain2.o
CC = g++

Swap: $(OBJS)
	$(CC) -o Sort $(OBJS)
	
swapLib.o:
	$(CC) -c SortLib.cpp
	
TestMain.o:
	$(CC) -c TestMain2.cpp

clean:
	rm -f core Sort $(OBJS)