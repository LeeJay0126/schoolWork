#  -Wall turns on most, but not all, compiler warnings
# core refers to core dump. Some Linux environment produce this file if something goes wrong

OBJS = TestBankAccount.o BankAccount.o
CFLAGS = -o -Wall
CC = g++

BankOut: $(OBJS)
	g++ -o BankOut $(OBJS)

BankAccount.o: 
	g++ -c BankAccount.cpp

TestBankAccount.o: 
	$(CC) -c TestBankAccount.cpp
	
clean:
	rm -f core Bankout $(OBJS)