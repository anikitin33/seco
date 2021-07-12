CXX = g++
CC=gcc
CFLAGS=-g -Wall -pedantic -Wextra -O2

PRGS= showcanary32.exe showcanary64.exe showcanary32none.exe

all: $(PRGS)

showcanary32.exe: showcanary32.c
	$(CC) $(CFLAGS) -m32 showcanary32.c -o showcanary32.exe
	
showcanary64.exe: showcanary64.c
	$(CC) $(CFLAGS) showcanary64.c -o showcanary64.exe
	
showcanary32none.exe: showcanary32none.c
	$(CC) $(CFLAGS) -m32 -fno-stack-protector showcanary32none.c -o showcanary32none.exe
	
.SUFFIXES: .o .c .h .cpp

.PHONY: clean

clean:
	-/bin/rm $(PRGS)
