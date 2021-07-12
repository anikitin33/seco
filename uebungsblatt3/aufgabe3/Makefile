CXX = g++
CC=gcc
CFLAGS=-g -Wall -pedantic -Wextra -O2

PRGS= searchcpre.exe searchcdyn.exe searchcpp.exe

all: $(PRGS)

searchcpre.exe: searchcpre.c
	$(CC) $(CFLAGS) searchcpre.c -o searchcpre.exe
	
searchcdyn.exe: searchcdyn.c
	$(CC) $(CFLAGS) searchcdyn.c -o searchcdyn.exe
	
searchcpp.exe: searchcpp.cpp
	$(CXX) $(CFLAGS) searchcpp.cpp -o searchcpp.exe

.SUFFIXES: .o .c .h .cpp

.PHONY: clean

clean:
	-/bin/rm $(PRGS)
