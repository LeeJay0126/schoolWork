OBJS = Food.o util.o diet_100357736.o
CC = g++

mydietaryplan: $(OBJS)
	g++ -o mydietaryplan $(OBJS)

util.o: 
	g++ -c util.cpp

diet_100357736.o: 
	$(CC) -c diet_100357736.cpp
	

Food.o:
	g++ -c Food.cpp
	
clean:
	rm -f core Food $(OBJS)