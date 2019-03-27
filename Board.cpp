//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Board.h"
    Board::Board(){}

    Board::Board(int lines, int columns){
        this->lines = lines;
        this->columns = columns;
    }

    Board::Board(int lines, int columns, std::vector<Piece> pieces){
        this->lines = lines;
        this->columns = columns;
        this->pieces = pieces;
    }

    int Board::getLines(){
        return this->lines;
    }

    int Board::getColumns(){
        return this->columns;
    }

    std::vector<Piece> Board::getPieces(){
        return this->pieces;
    }

    void Board::setLines(int w){
        this->lines = w;
    }

    void Board::setColumns(int h){
        this->columns = h;
    }

    void Board::setPieces(std::vector<Piece> pieces){
        this->pieces = pieces;
    }

    std::ostream& operator<< (std::ostream& stream, Board& board){
        stream << board.getLines() << "\n";
        stream << board.getColumns() << "\n\n";
        for(unsigned int i = 0; i < board.getPieces().size(); i++){
            stream << board.getPieces().at(i).getColor() << "\n";
            for(unsigned int j = 0; j < board.getPieces().at(i).getCells().size(); j++){
                stream << board.getPieces().at(i).getCells().at(j).getX() << " " << board.getPieces().at(i).getCells().at(j).getY() << "\n";
            }
        }
        return stream;
    }

    void Board::printBoard(){

        std::vector< std::vector<char> > vecBoard(this->getLines(), std::vector<char>(this->getColumns()));

        for(int i = 0; i < this->getLines(); i++)
        {
            for(int j = 0; j < this->getColumns(); j++)
            {
                vecBoard[i][j] = ' ';       
            }
        }

        for(unsigned int i = 0; i < this->getPieces().size(); i++)
        {
            for(unsigned int j = 0; j < this->getPieces()[i].getCells().size(); j++)
            {
                vecBoard[this->getPieces()[i].getCells()[j].getY()][this->getPieces()[i].getCells()[j].getX()] 
                = this->getPieces()[i].getPieceCharColor();       
            }
        }

        for(int i = 0; i < this->getLines(); i++)
        {
            for(int j = 0; j < this->getColumns(); j++)
            {
                if(j == 0)
                    std::cout  << "| ";

                std::cout << vecBoard[i][j] << " | ";       
            }
            
            std::cout << std::endl;

            for(int j = 1; j < this->getColumns(); j++)
            {
                if(j == 1)
                    std::cout  << "-----";

                    std::cout  << "----";
            }
            std::cout << std::endl;

        }

        
    }


