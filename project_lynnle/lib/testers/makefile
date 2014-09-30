CC=g++
CFLAGS=-g -Wall -std=c++11

all: email create map.o set.o

map.o: map.h map.cpp
	$(CC) $(CFLAGS) -c  map.h -o map.o

set.o: set.h set.cpp
	$(CC) $(CFLAGS) -c set.h -o set.o

email: email.cpp map.h map.cpp
	$(CC) $(CFLAGS) email.cpp -o email

create: create.cpp set.h set.cpp map.h map.cpp
	$(CC) $(CFLAGS) create.cpp -o create

clean:
	rm *~ *# email create map.o set.o