//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Board.h"
    Board::Board(){}

    Board::Board(int lines, int columns){
        this->lines = lines;
        this->columns = columns;
        this->matrix = std::vector< std::vector<char> >(this->getLines(), std::vector<char>(this->getColumns()));
        putMatrixEmpty();
    }

    Board::Board(int lines, int columns, std::vector<Piece> pieces){
        this->lines = lines;
        this->columns = columns;
        this->pieces = pieces;
        this->matrix = std::vector< std::vector<char> >(this->getLines(), std::vector<char>(this->getColumns()));
        putMatrixEmpty();
        putPiecesMatrix();
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

    void Board::setMatrixPosition(char icon, int x, int y){
        this->matrix[x][y] = icon; 
    }

    void Board::putPiecesMatrix(){
         for(unsigned int i = 0; i < this->getPieces().size(); i++)
        {
            for(unsigned int j = 0; j < this->getPieces()[i].getCells().size(); j++)
            {
                this->matrix[this->getPieces()[i].getCells()[j].getY()][this->getPieces()[i].getCells()[j].getX()] 
                = this->getPieces()[i].getPieceCharColor();       
            }
        }
    }

    Cell Board::moveCell(Cell cell, char direction){
        Cell response;
        if(direction == 'd')
            response = Cell(cell.getX()+1, cell.getY());
        else if(direction == 'w')
            response = Cell(cell.getX(), cell.getY()-1);
        else if(direction == 'a')
            response = Cell(cell.getX()-1, cell.getY());
        else if(direction == 's')
            response = Cell(cell.getX(), cell.getY()+1);

        return response;
    }

    void Board::putMatrixEmpty(){
        for(int i = 0; i < this->lines; i++){
            for(int j = 0; j < this->columns; j++){
                setMatrixPosition(' ',i,j);
            }
        }
    }

    bool Board::hasPieceWithCell(Cell cell){
        for(unsigned int i = 0; i < this->pieces.size(); i++){
            if(this->pieces[i].containsCell(cell)){
                return true;
            }
        }
        return false;
    }

    bool Board::possibleMove(Cell cell, char direction){
        Cell newCell;
        int numberCells;
        
        for(unsigned int i = 0; i < this->pieces.size(); i++){
            if(this->pieces[i].containsCell(cell)){
                numberCells = this->pieces[i].getCells().size();

                for(unsigned int j = 0; j < this->pieces[i].getCells().size(); j++){
                    newCell = moveCell(this->pieces[i].getCells()[j],direction);
                    
                    if(this->pieces[i].containsCell(newCell) || !hasPieceWithCell(newCell) ) {
                        if(newCell.getX() >= 0 && newCell.getX() < this->columns && newCell.getY() >= 0 && newCell.getY() < this->lines)
                            numberCells--;
                    }
                }
            }
        }
        if(numberCells == 0){
            return true;
        }
        return false;
    }

    void Board::printBoard(){

        for(int i = 0; i < this->getLines(); i++)
        {
            
            if(i == 0){
                for(int j = 1; j < this->getColumns(); j++){
                    if(j == 1)
                        std::cout  << "-----";

                    std::cout  << "----";
                }
                std::cout << std::endl;
            }
            

            for(int j = 0; j < this->getColumns(); j++)
            {
                if(j == 0)
                    std::cout  << "| ";

                std::cout << this->matrix[i][j] << " | ";       
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


