//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Piece.h"

    Piece::Piece(){};

    Piece::Piece(std::string color, std::vector<Cell> cells){
        this.color = color;
        this.cells = cells;
    }

    std::string Piece::getColor(){
        return this.color;
    }

    std::vector<Cell> Piece::getCells(){
        return this.cells;
    }

    void setY(std::string color){
        this.color = color;
    }

    void setX(std::vector<Cell> cells){
        this.cells = cells;
    }

