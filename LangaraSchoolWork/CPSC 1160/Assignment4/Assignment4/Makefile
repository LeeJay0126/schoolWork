# filename: Makefile

OBJS = AS_4_Test.o CarInfo.o Customers.o Utils.o
CC = g++

TestMain4: $(OBJS)
	g++ -o TestMain4 $(OBJS)

CarInfo.o: 
	g++ -c CarInfo.cpp

AS_4_Test.o: 
	$(CC) -c AS_4_Test.cpp
	
Customers.o: 
	g++ -c Customers.cpp

Utils.o:
	g++ -c Util.cpp
	
clean:
	rm -f core CarInfo $(OBJS)
