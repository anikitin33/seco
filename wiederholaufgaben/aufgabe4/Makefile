
CC=gcc
CFLAGS=-g -Wall -Wextra -O2
PRGS=myqueue.o testmyqueue.o

all: testmyqueue $(PRGS)

myqueue.o: myqueue.c myqueue.h
	$(CC) -c $(CFLAGS) myqueue.c -o myqueue.o

testmyqueue.o: testmyqueue.c myqueue.h
	$(CC) -c $(CFLAGS) testmyqueue.c -o testmyqueue.o

testmyqueue: testmyqueue.o myqueue.o
	$(CC) $(CFLAGS) testmyqueue.o myqueue.o -o testmyqueue.exe

.SUFFIXES: .o .c .h

.PHONY: clean

clean:
	-/bin/rm $(PRGS) testmyqueue.exe

