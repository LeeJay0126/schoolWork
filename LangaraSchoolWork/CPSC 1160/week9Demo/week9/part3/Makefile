OBJS = SelectionSortGeneric.o TestMain.o

SortOut: $(OBJS)
	g++ -o SortOut $(OBJS)
	rm -f $(OBJS)

SelectionSortGeneric.o:
	g++ -c SelectionSortGeneric.cpp

TestMain.o:
	g++ -c TestMain.cpp

clean:
	rm -f core SortOut $(OBJS)