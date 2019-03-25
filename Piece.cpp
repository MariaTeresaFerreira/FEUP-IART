//
// Created by Teresa Ferreira on 22/03/2019.
//

#include <iostream>
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
/*
    string enum{
        red = 1;
        blue = 2;
        green = 3;
        yellow = 4;
    }color_name;
*/
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
}



