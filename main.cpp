#include <iostream>
#include "Cell.h"
#include "Piece.h"
#include "Board.h"
#include "Game.h"
#include <fstream>




int main() {
    int col;
    int lin;
    std::vector<Piece> pieces;

    std::string lines;
    std::string columns;

    std::string numPieces;
    std::string piece;

    std::string color;

    std::string strY;
    std::string strX;
    
    long stop;
    long lastStop;

    std::ifstream fileBoard;
    int game_level = 0;

    while(game_level < 1 || game_level > 3){

        std::cout << "Please select level" << std::endl;
        std::cout << "1 - Easy" << std::endl;
        std::cout << "2 - Medium" << std::endl;
        std::cout << "3 - Hard" << std::endl;
        std::cin >> game_level;

        if(game_level == 1){
        fileBoard.open("nivel1.txt");
        break;
        }
        else if(game_level == 2){
        fileBoard.open("nivel2.txt");
        break;
        }
        else if(game_level == 3){
        fileBoard.open("nivel3.txt");
        break;
        }
    }
    
    if (fileBoard.is_open()) {
        while (!fileBoard.eof()) {

            std::getline(fileBoard, lines);
            std::getline(fileBoard, columns);            
            lin = atoi( lines.c_str() );
            col = atoi( columns.c_str() );
            
            std::getline(fileBoard, numPieces);
            int nPiece = atoi( numPieces.c_str() );


            for(int i = 1; i <= nPiece; i++){
                std::getline(fileBoard, piece);
                lastStop = piece.find_last_of(';');
                color = piece.substr(lastStop+1);
                std::vector<Cell> cells;

                while(lastStop != stop){
                    stop = piece.find_first_of(';');
                    strX = piece.substr(0,stop);
                    piece = piece.substr(stop+1); 
                    stop = piece.find_first_of(';');
                    strY = piece.substr(0,stop);

                    lastStop = piece.find_last_of(';');
                    piece = piece.substr(stop+1);
                    
                    cells.push_back(Cell(atoi( strX.c_str() ),atoi( strY.c_str() )));
                }
                pieces.push_back(Piece(color, cells));                  
            }
        }
    }
    Board board = Board(col,lin,pieces);

    fileBoard.close();
    
    Game game = Game(board);

    game.run();

    return 0;
}
