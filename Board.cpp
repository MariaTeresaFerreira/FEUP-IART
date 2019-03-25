//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Board.h"

    Board::Board(){}

    Board::Board(int width, int height){
        this->width = width;
        this->height = height;
    }

    Board::Board(int width, int height, std::vector<Piece> pieces){
        this->width = width;
        this->height = height;
        this->pieces = pieces;
    }

    int Board::getWidth(){
        return this->width;
    }

    int Board::getHeight(){
        return this->height;
    }

    std::vector<Piece> Board::getPieces(){
        return this->pieces;
    }

    void Board::setWidth(int w){
        this->width = w;
    }

    void Board::setHeight(int h){
        this->height = h;
    }

    void Board::setPieces(std::vector<Piece> pieces){
        this->pieces = pieces;
    }

    std::ostream& operator<< (std::ostream& stream, Board& board){
        stream << board.getWidth() << "\n";
        stream << board.getHeight() << "\n\n";
        for(unsigned int i = 0; i < board.getPieces().size(); i++){
            stream << board.getPieces().at(i).getColor() << "\n";
            for(unsigned int j = 0; j < board.getPieces().at(i).getCells().size(); j++){
                stream << board.getPieces().at(i).getCells().at(j).getX() << " " << board.getPieces().at(i).getCells().at(j).getY() << "\n";
            }
        }
        return stream;
    }

    void Board::printBoard(){

        char piecesArray[this->width][this->height];

        for (int i = 0; i < this->height; ++i)
        {
            for (int j = 0; j < this->width; ++j)
            {
                piecesArray[i][j] = ' ';

            }
        }

        for(int m = 0; m < this->pieces.size(); m++){

            for(int n = 0; n < this->pieces.at(m).getCells().size(); n++){
                piecesArray[this->pieces.at(m).getCells().at(n).getX()][this->pieces.at(m).getCells().at(n).getY()]
                        = this->pieces.at(m).getPieceCharColor();
            }

        }

        for (int i = 0; i < this->height; ++i)
        {
            std::cout << " | " ;
            for (int j = 0; j < this->width; ++j)
            {
                std::cout << piecesArray[i][j] << ' ';
                std::cout << " | " ;

            }
            std::cout << std::endl;
        }
    }




/*

        for(int i = 0; i < this->getHeight(); i++)
        {

            for(int j = 0; j < this->getWidth(); j++)
            {
                Piece newPiece = Piece();
                if (std::find(this->pieces.begin(), this->pieces.end(), ) != this->pieces.end())
                    std::cout << " | ";


                /*
                for(size_t k = 0; k < this->getPieces(); k++)
                {
                    if()
                }

                
            }
            std::cout << "\n";
        }
        
    }*/


