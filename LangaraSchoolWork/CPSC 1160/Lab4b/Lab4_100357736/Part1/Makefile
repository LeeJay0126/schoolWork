OBJS = swapLib.o TestMain.o
CC = g++

Swap: $(OBJS)
	$(CC) -o Swap $(OBJS)
	
swapLib.o:
	$(CC) -c swapLib.cpp
	
TestMain.o:
	$(CC) -c TestMain.cpp

clean:
	rm -f core Swap $(OBJS)