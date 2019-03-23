//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_PIECE_H
#define FEUP_IART_PIECE_H

#include "Cell.h"
#include "vector"
#include "string"

class Piece {
    protected:
        std::string color;
        std::vector<Cell> cells;

    public:
        std::string getColor();

        std::vector<Cell> getCells();

        std::string setColor(std::string color);

        std::std::string setCells(std::vector<Cell> cell);
};


#endif //FEUP_IART_PIECE_H
