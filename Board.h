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
        std::vector< std::vector<char> > matrix;
        std::vector<Piece> pieces;


    public:
        Board();

        Board(int lines, int columns);

        Board(int lines, int columns, std::vector<Piece> pieces);

        int getLines();

        int getColumns();

        std::vector<Piece> getPieces();

        void setMatrixPosition(char icon, int x, int y);

        void setLines(int lines);

        void setColumns(int columns);

        void setPieces(std::vector<Piece> pieces);

        void putPiecesMatrix();

        void putMatrixEmpty();

        Cell moveCell(Cell cell, char direction);

        bool hasPieceWithCell(Cell cell);

        bool possibleMove(Cell cell, char direction);

        void movePiece(Cell cell, char direction);

        void printBoard();

        friend std::ostream& operator<< (std::ostream& stream, Board& board);

        std::vector< std::vector<char> > getBoard();

        bool isGameFinished();

};


#endif //FEUP_IART_BOARD_H
