OBJS = GenericStack.o TestMain.o

GenericOut: $(OBJS)
	g++ -o GenerictOut $(OBJS)
	rm -f $(OBJS)

GenericStack.o:
	g++ -c GenericStack.cpp

TestMain.o:
	g++ -c TestMain.cpp

clean:
	rm -f core GenericOut $(OBJS)