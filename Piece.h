//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_PIECE_H
#define FEUP_IART_PIECE_H

#include "Cell.h"
#include <vector>
#include <string>
#include <iostream>

class Piece {
    protected:
        std::string color;
        std::vector<Cell> cells;

    public:
        Piece();

        Piece(std::string color, std::vector<Cell> cells);

        std::string getColor();

        std::vector<Cell> & getCells();

        void setColor(std::string color);

        void setCells(std::vector<Cell> cell);

        friend std::ostream& operator<< (std::ostream& stream, Piece& piece);

        int getColorInt(std::string color);

        bool containsCell(Cell cell);

        bool cellsAdjacent(std::vector<Cell> cells);

        void printPiece();

        char getPieceCharColor();
        
        bool isPieceAdjacent(Piece piece);

        void addCell(Cell cell);

        friend bool operator== (const Piece& piece1, const Piece& piece2);
};


#endif //FEUP_IART_PIECE_H
