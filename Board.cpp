//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Board.h"
  
    int Board::getWidth(){
        return this.width;
    }

    int Board::getHeight(){
        return this.height;
    }

    std::vector<Piece> Board::getPieces(){
        return this.pieces;
    }

    void Board::setWidth(int w){
        this.width = w;
    }

    void Board::setHeight(int h){
        this.height = h;
    }

    void Board::setY(std::vector<Piece> pieces){
        this.pieces = pieces;
    }    


