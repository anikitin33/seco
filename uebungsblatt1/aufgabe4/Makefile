
CC=gcc
CFLAGS=-g -Wall -Wextra -O2 -m32
PRGS=queue.o cmdq.o

all: cmdq $(PRGS)

queue.o: queue.c queue.h
	$(CC) -c $(CFLAGS) queue.c -o queue.o

cmdq.o: cmdq.c queue.h
	$(CC) -c $(CFLAGS) cmdq.c -o cmdq.o

cmdq: cmdq.o queue.o
	$(CC) $(CFLAGS) cmdq.o queue.o -o cmdq.exe

.SUFFIXES: .o .c .h

.PHONY: clean

clean:
	-/bin/rm $(PRGS) cmdq.exe

