//
// Created by Teresa Ferreira on 22/03/2019.
//

#include <iostream>
#include "Piece.h"

    Piece::Piece(){}

    Piece::Piece(std::string color, std::vector<Cell> cells){
        if(cellsAdjacent(cells)){
            this->color = color;
            this->cells = cells;
        }
        else{
            std::cout << "Cells are not adjacent" << std::endl;
        }
    }

    std::string Piece::getColor(){
        return this->color;
    }

    std::vector<Cell> & Piece::getCells(){
        return (this->cells);
    }

    void Piece::setColor(std::string color){
        this->color = color;
    }

    void Piece::setCells(std::vector<Cell> cells){
        this->cells = cells;
    }

    std::ostream& operator<< (std::ostream& stream, Piece& piece){
        stream << piece.getColor() << "\n";
        for(unsigned int i = 0; i < piece.getCells().size(); i++){
            stream << piece.getCells().at(i).getX() << " " << piece.getCells().at(i).getY() << "\n";
        }
        return stream;
    }

    bool operator== (const Piece& piece1, const Piece& piece2){
        return piece1.cells == piece2.cells;
    }

    bool Piece::containsCell(Cell cell){
        for(unsigned int i = 0; i < this->cells.size(); i++){
            if(cell.getX() == this->cells[i].getX() && cell.getY() == this->cells[i].getY())
            return true;
        }
        return false;
    }


    bool Piece::cellsAdjacent(std::vector<Cell> cells){

        int numberCells = cells.size();

        if(numberCells == 1){
            return true;
        }

        for(unsigned int i = 0; i < cells.size(); i++){
            for(unsigned int j = 0; j < cells.size(); j++){

                //same cell can not be compared so iteration skipped
                if(i == j){
                    continue;
                }

                //if this.cell is adjacent to other cell they are valid
                if(cells[i].isAdjacent(cells[j])){
                    numberCells--;
                    break;
                }
            }
        }

        if(numberCells == 0)
            return true;
        return false;
    }

    int Piece::getColorInt(std::string color){
        int response = -1;

        if(color == "red")
            response = 1;
        else if(color == "blue")
            response = 2;
        else if(color == "green")
            response = 3;
        else if(color == "yellow")
            response = 4;

        return response;
    }


    void Piece::printPiece(){
        int colorInt = this->getColorInt(this->getColor());

        switch(colorInt){
            case 1:
                std::cout << "r";
                break;
            case 2:
                std::cout << "b";
                break;
            case 3:
                std::cout << "g";
                break;
            case 4:
                std::cout << "y";
                break;
            default:
                break;
        }
    }

    char Piece::getPieceCharColor(){
        int colorInt = this->getColorInt(this->getColor());
        switch(colorInt){
            case 1:
                return 'r';
            case 2:
                return 'b';
            case 3:
                return 'g';
            case 4:
                return 'y';
            default:
                break;
        }
        return ' ';
    }

    bool Piece::isPieceAdjacent(Piece piece){
        for(unsigned int i = 0; i < this->cells.size(); i++){
          for(unsigned int j = 0; j < piece.getCells().size(); j++){
            if (this->cells.at(i).isAdjacent(piece.getCells().at(j))) {
              return true;
            }
          }
        }
        return false;
    }

    void Piece::addCell(Cell cell) {
        this->cells.push_back(cell);

    }