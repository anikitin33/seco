CC=gcc
CFLAGS=-g -Wall -Wextra -O2
PRGS=mylib.o testmylib.o

all: testmylib $(PRGS)

mylib.o: mylib.c mylib.h
	$(CC) -c $(CFLAGS) mylib.c -o mylib.o

testmylib.o: testmylib.c mylib.h
	$(CC) -c $(CFLAGS) testmylib.c -o testmylib.o

testmylib: testmylib.o mylib.o
	$(CC) $(CFLAGS) testmylib.o mylib.o -o testmylib.exe

.SUFFIXES: .o .c .h

.PHONY: clean

clean:
	-/bin/rm $(PRGS) testmylib.exe

test: testmylib
	./testmylib.exe index Hallo a
	./testmylib.exe index Hallo l
	./testmylib.exe index Hallali a
	./testmylib.exe index hallo e
	./testmylib.exe strcasecmp Hallo hallo
	./testmylib.exe strcasecmp HAlLo HaLlO
	./testmylib.exe strcasecmp hallo hello
