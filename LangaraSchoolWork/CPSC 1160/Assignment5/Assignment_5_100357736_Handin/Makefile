OBJS = players.o util.o nba_100357736.o
CC = g++

NbaOut: $(OBJS)
	g++ -o NbaOut $(OBJS)

util.o: 
	g++ -c util.cpp

nba_100357736.o: 
	$(CC) -c nba_100357736.cpp
	

players.o:
	g++ -c players.cpp
	
clean:
	rm -f core players $(OBJS)
