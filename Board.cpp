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


