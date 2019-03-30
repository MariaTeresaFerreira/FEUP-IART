//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_GAME_H
#define FEUP_IART_GAME_H

#include "Board.h"
#include "AI.h"
#include <vector>



class Game {
    protected:
        Board board;

    public:

        Game();

        Game(Board board);

        void draw();

        void run();

        Cell inputCell();

        char inputDirection();

        std::vector<char> inputAIDirection(Piece piece);

        void AIGame(Board b);

        Board getBoardGame();
        
};


#endif //FEUP_IART_GAME_H
