#include <iostream>
#include "Cell.h"
#include "Piece.h"
#include "Board.h"

int main() {
/*
    Game game = Game(Board x);
    game.run();
*/

    Cell cell1 = Cell(2,1);
    Cell cell2 = Cell(2,4);
    Cell cell3 = Cell(0,1);
    Cell cell4 = Cell(0,0);
    
    std::vector<Cell> cells;
    
    cells.push_back(cell1);
    cells.push_back(cell2);
    cells.push_back(cell3);
    cells.push_back(cell4);

    Piece piece1 = Piece("green", cells);
    //Piece piece2 = Piece("red", cells);
    //Piece piece3 = Piece("blue", cells);

    std::vector<Piece> pieces;

    pieces.push_back(piece1);
    //pieces.push_back(piece2);
    //pieces.push_back(piece3);

    Board board = Board(5,3,pieces);
    
    //std::cout << board;

    board.printBoard();
    return 0;
}