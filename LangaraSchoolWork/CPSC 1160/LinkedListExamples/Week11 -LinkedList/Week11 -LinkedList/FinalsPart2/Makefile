OBJS = Node.o Pokemon_100357736.o LoadFile.o Tester.o
CC = g++

TesterOut: $(OBJS)
	g++ -o TesterOut $(OBJS)

LoadFile.o: 
	g++ -c LoadFile.cpp

Pokemon_100357736.o: 
	g++ -c Pokemon_100357736.cpp
	
Node.o: 
	g++ -c Node.cpp
	
Tester.o: 
	$(CC) -c Tester.cpp
	
clean:
	rm -f core Pokemon $(OBJS)