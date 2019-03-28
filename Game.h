//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_GAME_H
#define FEUP_IART_GAME_H

#include "Board.h"



class Game {
    protected:
        Board board;

    public:

        Game();

        Game(Board board);

        void draw();

        void run();

        Cell imputCell();
        
};


#endif //FEUP_IART_GAME_H
