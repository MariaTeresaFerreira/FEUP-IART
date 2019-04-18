//
// Created by Teresa Ferreira on 17/04/2019.
//

#ifndef MINI_TESTE_2_GAME_H
#define MINI_TESTE_2_GAME_H

#include <vector>
#include "Board.h"
#include <iostream>


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
    void make_move(char dir);
    bool is_move_valid(char dir);
    vector<int> get_0_pos();
};


#endif //MINI_TESTE_2_GAME_H
