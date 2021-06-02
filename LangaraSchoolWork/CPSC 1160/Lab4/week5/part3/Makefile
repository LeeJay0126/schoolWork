#  -Wall turns on most, but not all, compiler warnings
# core refers to core dump. Some Linux environment produce this file if something goes wrong

OBJS = DayOfYear.o Holiday.o TestMain.o
CFLAGS = -c -Wall
CC = g++

TestHoliday: $(OBJS)
	g++ -o TestHoliday $(OBJS)

TestMain.o: 
	$(CC) $(CFLAGS) TestMain.cpp
DayOfYear.o: 
	g++ -c DayOfYear.cpp

Holiday.o: 
	$(CC) -c Holiday.cpp
	
clean:
	rm -f core TestHoliday $(OBJS)