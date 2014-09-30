# Detecting OS
CC = g++

# compiler flags for debug
CPPFLAGS=-std=c++11 -Wall -g -DDEBUG

# name of the binary
all: bin/Movie.o main

bin/Movie.o: Movie.cpp Movie.h
	$(CC) $(CPPFLAGS) -c Movie.cpp -o bin/Movie.o

main: bin/Movie.o main.cpp
	$(CC) $(CPPFLAGS) main.cpp bin/Movie.o -o main

# Memory check rule. Depends on a fresh binary.
.PHONY: memcheck

memcheck: lab5
	valgrind --tool=memcheck ./$<

# The clean rule
.PHONY: clean

clean:
	rm *.o *~ *# bin/Movie.o main