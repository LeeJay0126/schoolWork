OBJS = TestNode.o

LinkOut: $(OBJS)
	g++ -o LinkOut $(OBJS)
	rm -f $(OBJS)


TestNode.o:
	g++ -c TestNode.cpp


clean:
	rm -f core LinkOut $(OBJS)