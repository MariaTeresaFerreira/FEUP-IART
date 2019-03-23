//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Piece.h"

    Piece::Piece(){}

    Piece::Piece(std::string color, std::vector<Cell> cells){
        this->color = color;
        this->cells = cells;
    }

    std::string Piece::getColor(){
        return this->color;
    }

    std::vector<Cell> Piece::getCells(){
        return this->cells;
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

