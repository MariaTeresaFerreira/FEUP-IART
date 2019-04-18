//
// Created by Teresa Ferreira on 17/04/2019.
//

#ifndef MINI_TESTE_2_GAME_H
#define MINI_TESTE_2_GAME_H

#include <vector>
#include "Board.h"


class Game {


private:
    Board current_board;
    Board final_board;

public:
    Game();
    Game(Board board);
    Board get_current_board() & ;
    Board get_final_board();
    Board generate_final_board();
    bool isGameFinished();
};


#endif //MINI_TESTE_2_GAME_H
