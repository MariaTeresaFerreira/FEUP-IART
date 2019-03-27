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
        int lines;
        int columns;
        std::vector<Piece> pieces;

    public:
        Board();

        Board(int lines, int columns);

        Board(int lines, int columns, std::vector<Piece> pieces);

        int getLines();

        int getColumns();

        std::vector<Piece> getPieces();

        void setLines(int lines);

        void setColumns(int columns);

        void setPieces(std::vector<Piece>);

        friend std::ostream& operator<< (std::ostream& stream, Board& board);

        void printBoard();


};


#endif //FEUP_IART_BOARD_H
