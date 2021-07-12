
CC=gcc
CFLAGS=-g -Wall -pedantic -Wextra -O2 -ggdb3

PRGS=str38main.o str38.o str38_test.exe

all: str38main $(PRGS)

str38.o: str38.c str38.h
	$(CC) -c $(CFLAGS) str38.c -o str38.o 
	
str38main.o: str38main.c
	$(CC) -c $(CFLAGS) str38main.c -o str38main.o

str38main: str38.o str38main.o
	$(CC) $(CFLAGS) str38main.o str38.o -o str38main.exe
	
str38_test.exe: str38.o str38_test.cpp
	g++ $(CFLAGS) str38.o str38_test.cpp -pthread -lgtest -lgtest_main -o str38_test.exe

.SUFFIXES: .o .c .h .cpp

.PHONY: clean

clean:
	-/bin/rm $(PRGS) str38.o str38main.exe str38main.o str38_test.exe
