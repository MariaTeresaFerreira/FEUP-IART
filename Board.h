//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_BOARD_H
#define FEUP_IART_BOARD_H

#include "Piece.h"
#include "vector"
#include "string"

class Board {
    protected:
        int width;
        int height;
        std:vector<Piece> pieces;

    public:

        int getWidth();

        int getHeight();

        std::vector<Piece> getPieces();

        void setWidth(int width);

        void setHeight(int height);

        void setHeight(std::vector<Piece>);

};


#endif //FEUP_IART_BOARD_H
