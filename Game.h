//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_GAME_H
#define FEUP_IART_GAME_H

#include "Board.h"



class Game {
    protected:
        Board board;
        Board newBoard;

    public:

        Game();

        Game(Board board);

        Game(Board board, Board newBoard);

        void draw();

        void run();
        
};


#endif //FEUP_IART_GAME_H
