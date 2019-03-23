CC=g++

CFLAGS=-c -Wall

all: game

game: main.o Cell.o
	$(CC) main.o Cell.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Cell.o: Cell.cpp
	$(CC) $(CFLAGS) Cell.cpp

clean:
	rm -rf *o game


