#include <iostream>
#include "Cell.h"
#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include "AI.h"


int main() {

    std::string game_level;
    std::cout << "Please select level" << std::endl;
    std::cout << "1 - Easy" << std::endl;
    std::cout << "2 - Medium" << std::endl;
    std::cout << "3 - Hard" << std::endl;
    std::cin >> game_level;

    std::vector<Piece> pieces;
while(true){
    if(game_level == "1"){
        //lvl1 easy

        std::cout << "Easy level selected" << std::endl;

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

        pieces.push_back(piece1);
        pieces.push_back(piece2);
        pieces.push_back(piece3);
        pieces.push_back(piece4);
        pieces.push_back(piece5);
        break;

    } else if( game_level == "2"){
        //lvl2 easy

        std::cout << "Medium level selected" << std::endl;

        Cell cellr1 = Cell(1,0);
        Cell cellr2 = Cell(1,1);

        Cell cellb1 = Cell(2,1);
        Cell cellb2 = Cell(3,1);

        Cell cellr3 = Cell(2,2);
        Cell cellr4 = Cell(3,2);

        Cell cellb3 = Cell(1,2);
        Cell cellb4 = Cell(1,3);

        std::vector<Cell> cells1;
        std::vector<Cell> cells2;
        std::vector<Cell> cells3;
        std::vector<Cell> cells4;

        cells1.push_back(cellr1);
        cells1.push_back(cellr2);

        cells2.push_back(cellb1);
        cells2.push_back(cellb2);

        cells3.push_back(cellr3);
        cells3.push_back(cellr4);

        cells4.push_back(cellb3);
        cells4.push_back(cellb4);

        Piece piece1 = Piece("red", cells1);
        Piece piece2 = Piece("blue", cells2);
        Piece piece3 = Piece("red", cells3);
        Piece piece4 = Piece("blue", cells4);

        pieces.push_back(piece1);
        pieces.push_back(piece2);
        pieces.push_back(piece3);
        pieces.push_back(piece4);
        break;
    } else if (game_level == "3"){

        //lvl 1 hard

        std::cout << "Hard level selected" << std::endl;

        Cell cellb1 = Cell(0, 0);
        Cell cellb2 = Cell(1, 0);
        Cell cellb3 = Cell(3, 2);
        Cell cellb4 = Cell(2, 3);

        Cell cellg1 = Cell(3, 0);
        Cell cellg2 = Cell(1, 3);

        Cell cellr1 = Cell(0, 1);
        Cell cellr2 = Cell(1, 1);
        Cell cellr3 = Cell(2, 1);
        Cell cellr4 = Cell(0, 2);
        Cell cellr5 = Cell(1, 2);
        Cell cellr6 = Cell(2, 2);



        std::vector<Cell> cells1;
        std::vector<Cell> cells2;
        std::vector<Cell> cells3;
        std::vector<Cell> cells4;
        std::vector<Cell> cells5;
        std::vector<Cell> cells6;

        cells1.push_back(cellb1);
        cells1.push_back(cellb2);

        cells2.push_back(cellg1);

        cells3.push_back(cellr1);
        cells3.push_back(cellr2);
        cells3.push_back(cellr3);
        cells3.push_back(cellr4);
        cells3.push_back(cellr5);
        cells3.push_back(cellr6);

        cells4.push_back(cellb3);

        cells5.push_back(cellg2);

        cells6.push_back(cellb4);

        Piece piece1 = Piece("blue", cells1);
        Piece piece2 = Piece("green", cells2);
        Piece piece3 = Piece("red", cells3);
        Piece piece4 = Piece("blue", cells4);
        Piece piece5 = Piece("green", cells5);
        Piece piece6 = Piece("blue", cells6);




        pieces.push_back(piece1);
        pieces.push_back(piece2);
        pieces.push_back(piece3);
        pieces.push_back(piece4);
        pieces.push_back(piece5);
        pieces.push_back(piece6);
        break;
    }

}
    Board board = Board(4,4,pieces);

    //std::cout << board.hasPieceInCell(Cell(0,0)) << std::endl;
    //std::cout << board.hasPieceInCell(Cell(0,1)) << std::endl;


    Game game = Game(board);
    game.run();


    return 0;
}
