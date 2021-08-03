OBJS = TestQueue.o 

LinkOut: $(OBJS)
	g++ -o LinkOut $(OBJS)
	rm -f $(OBJS)


TestQueue.o:
	g++ -c TestQueue.cpp


clean:
	rm -f core LinkOut $(OBJS)