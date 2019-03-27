#include <iostream>
#include "Cell.h"
#include "Piece.h"
#include "Board.h"

int main() {
/*
    Game game = Game(Board x);
    game.run();
*/

    Cell cell1 = Cell(4,0);
    Cell cell2 = Cell(0,0);

    Cell cell3 = Cell(0,1);
    Cell cell4 = Cell(0,2);

    Cell cell5 = Cell(1,0);
    Cell cell6 = Cell(2,2);
    
    std::vector<Cell> cells1;
    std::vector<Cell> cells2;
    std::vector<Cell> cells3;

    
    cells1.push_back(cell1);
    cells1.push_back(cell2);
    cells2.push_back(cell3);
    cells2.push_back(cell4);
    cells3.push_back(cell5);
    cells3.push_back(cell6);

    Piece piece1 = Piece("green", cells1);
    Piece piece2 = Piece("red", cells2);
    Piece piece3 = Piece("blue", cells3);

    std::vector<Piece> pieces;

    pieces.push_back(piece1);
    pieces.push_back(piece2);
    pieces.push_back(piece3);

    Board board = Board(3,5,pieces);
    
    //std::cout << board;

    board.printBoard();
    return 0;
}