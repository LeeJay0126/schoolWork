OBJS = Stocks.o FileUtil.o TestMain.o 

StockTest: $(OBJS)
	g++ -o StockTest $(OBJS)
	rm -f $(OBJS)

Stocks.o:
	g++ -c Stocks.cpp

FileUtil.o:
	g++ -c FileUtil.cpp

TestMain.o:
	g++ -c TestMain.cpp

clean: rm-f core StockTest$(OBJS)