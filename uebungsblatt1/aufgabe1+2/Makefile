
CC=gcc
CFLAGS=-g -Wall -Wextra -O2
PRGS=quadriere.o math_lib.o wurzele.o

all: quadriere wurzele $(PRGS)

math_lib.o: math_lib.c math_lib.h
	$(CC) -c $(CFLAGS) math_lib.c -o math_lib.o

quadriere.o: quadriere.c math_lib.h
	$(CC) -c $(CFLAGS) quadriere.c -o quadriere.o

quadriere: quadriere.o math_lib.o
	$(CC) $(CFLAGS) quadriere.o math_lib.o -o quadriere.exe
	
wurzele.o: wurzele.c math_lib.h
	$(CC) -c $(CFLAGS) wurzele.c -o wurzele.o

wurzele: wurzele.o math_lib.o
	$(CC) $(CFLAGS) wurzele.o math_lib.o -o wurzele.exe

.SUFFIXES: .o .c .h

.PHONY: clean

clean:
	-/bin/rm $(PRGS) quadriere.exe quadriere.o wurzele.exe wurzele.o

