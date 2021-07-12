
CC=gcc
CFLAGS=-g -Wall -pedantic -Wextra -O2 -ggdb3

PRGS=mygetline_main.o mygetline.o test_mygetline.exe

all: mygetline_main $(PRGS)

mygetline.o: mygetline.c mygetline.h
	$(CC) -c $(CFLAGS) mygetline.c -o mygetline.o 
	
mygetline_main.o: mygetline_main.c
	$(CC) -c $(CFLAGS) mygetline_main.c -o mygetline_main.o

mygetline_main: mygetline.o mygetline_main.o
	$(CC) $(CFLAGS) mygetline_main.o mygetline.o -o mygetline_main.exe
	
test_mygetline.exe: mygetline.o test_mygetline.cpp
	g++ $(CFLAGS) mygetline.o test_mygetline.cpp -pthread -lgtest -lgtest_main -o test_mygetline.exe

.SUFFIXES: .o .c .h .cpp

.PHONY: clean

clean:
	-/bin/rm $(PRGS) mygetline.o mygetline_main.exe mygetline_main.o test_mygetline.exe
