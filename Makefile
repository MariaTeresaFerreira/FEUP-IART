CC=g++

CFLAGS=-c -Wall

all: game

game: main.o Cell.o Piece.o Board.o Game.o
	$(CC) main.o Cell.o  Piece.o Board.o Game.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Cell.o: Cell.cpp
	$(CC) $(CFLAGS) Cell.cpp

Piece.o: Piece.cpp
	$(CC) $(CFLAGS) Piece.cpp

Board.o: Board.cpp
	$(CC) $(CFLAGS) Board.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) Game.cpp

clean:
	rm -rf *o game


