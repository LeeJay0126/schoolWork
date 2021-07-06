OBJS = TestNode.o LinkedList.o

LinkOut: $(OBJS)
	g++ -o LinkOut $(OBJS)
	rm -f $(OBJS)

LinkedList.o: 
	g++ -c LinkedList.cpp
	
TestNode.o:
	g++ -c TestNode.cpp


clean:
	rm -f core LinkOut $(OBJS)