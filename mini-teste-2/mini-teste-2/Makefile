CC=g++ -std=c++11

CFLAGS=-c -Wall -g

all: game

debug: game 

game: main.o Board.o Game.o Node.o AI.o
	$(CC) main.o Board.o Game.o Node.o AI.o -o game

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Board.o: Board.cpp
	$(CC) $(CFLAGS) Board.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) Game.cpp

Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp

AI.o: AI.cpp
	$(CC) $(CFLAGS) AI.cpp	

clean:
	rm -rf *o game


