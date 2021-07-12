CXX = g++
CC=gcc
CFLAGS=-g -fsanitize=address -Wall -pedantic -Wextra -O2

PRGS= offbyone.exe

all: $(PRGS)

offbyone.exe: offbyone.c
	$(CC) $(CFLAGS) offbyone.c -o offbyone.exe
	
.SUFFIXES: .o .c .h .cpp

.PHONY: clean

clean:
	-/bin/rm $(PRGS)
