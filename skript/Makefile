
CC = gcc
CFLAGS = -g -Wall -pedantic -Wextra -O0

CXX=g++
CXXFLAGS=-g -std=c++14 -Wall -Wextra -O0 -pedantic

PRGS = 017_helloc.exe 041_geheim.exe 059_arraysize.exe 085_inputvalid.exe 114_memorymanagement.exe 185_integer.exe 176_checkadd.exe 176_checksub.exe 205_bereichspruefung.exe 197_int.exe 285_firstex.exe
#064_widecharacter.exe 
all: $(PRGS)

017_helloc.exe: 017_helloc.c
	$(CC) $(CFLAGS) 017_helloc.c -o 017_helloc.exe
	
041_geheim.exe: 041_geheim.c
	$(CC) $(CFLAGS) 041_geheim.c -o 041_geheim.exe

059_arraysize.exe: 059_arraysize.c
	$(CC) $(CFLAGS) 059_arraysize.c -o 059_arraysize.exe
	
#064_widecharacter.exe: 064_widecharacter.cpp
#	$(CXX) $(CXXFLAGS) 064_widecharacter.cpp -o 064_widecharacter.exe

085_inputvalid.exe: 085_inputvalid.c
	$(CC) $(CFLAGS) 085_inputvalid.c -o 085_inputvalid.exe

114_memorymanagement.exe: 114_memorymanagement.c
	$(CC) $(CFLAGS) 114_memorymanagement.c -o 114_memorymanagement.exe

176_checkadd.exe: 176_checkadd.c
	$(CC) $(CFLAGS) 176_checkadd.c -o 176_checkadd.exe	

176_checksub.exe: 176_checksub.c
	$(CC) $(CFLAGS) 176_checksub.c -o 176_checksub.exe	
	
185_integer.exe: 185_integer.c
	$(CC) $(CFLAGS) 185_integer.c -o 185_integer.exe

205_bereichspruefung.exe: 205_bereichspruefung.c
	$(CC) $(CFLAGS) 205_bereichspruefung.c -o 205_bereichspruefung.exe
	
197_int.exe: 197_int.c
	clang $(CFLAGS) -fsanitize=signed-integer-overflow 197_int.c -o 197_int.exe

285_firstex.exe: 285_firstex.cpp 285_firstex.h
	g++ $(CFLAGS) -fsanitize=address 285_firstex.cpp 285_firstex.h -o 285_firstex.exe

.SUFFIXES: .o .c .h .cpp

.PHONY: clean

clean:
	-/bin/rm $(PRGS)

format:
	clang-format -style=google -i *.c *.cpp

analyse:
	flawfinder *.c *.cpp && clang-tidy *.c *.cpp
#splint
