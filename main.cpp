#include <iostream>
#include "Cell.h"
#include "Piece.h"
#include "Board.h"

int main() {
    Cell cellb1 = Cell(0,0);

    Cell cellb2 = Cell(3,0);

    Cell cellb3 = Cell(0,3);

    Cell cellg1 = Cell(1,0);
    Cell cellg2 = Cell(1,1);
    Cell cellg3 = Cell(1,2);
    Cell cellg4 = Cell(2,2);

    Cell cellr1 = Cell(2,1);
    Cell cellr2 = Cell(3,1);
    Cell cellr3 = Cell(3,2);
    Cell cellr4 = Cell(3,3);

    std::vector<Cell> cells1;
    std::vector<Cell> cells2;
    std::vector<Cell> cells3;
    std::vector<Cell> cells4;
    std::vector<Cell> cells5;

    cells1.push_back(cellb1);

    cells2.push_back(cellb2);

    cells3.push_back(cellb3);
    
    cells4.push_back(cellg1);
    cells4.push_back(cellg2);
    cells4.push_back(cellg3);
    cells4.push_back(cellg4);

    cells5.push_back(cellr1);
    cells5.push_back(cellr2);
    cells5.push_back(cellr3);
    cells5.push_back(cellr4);
    
    Piece piece1 = Piece("blue", cells1);
    Piece piece2 = Piece("blue", cells2);
    Piece piece3 = Piece("blue", cells3);
    Piece piece4 = Piece("green", cells4);
    Piece piece5 = Piece("red", cells5);

    std::vector<Piece> pieces;

    pieces.push_back(piece1);
    pieces.push_back(piece2);
    pieces.push_back(piece3);
    pieces.push_back(piece4);
    pieces.push_back(piece5);

    Board board = Board(4,4,pieces);
    
    board.printBoard();

    /*
    Game game = Game(Board board);
    game.run();
    */

    return 0;
}