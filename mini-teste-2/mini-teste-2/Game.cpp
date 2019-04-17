//
// Created by Teresa Ferreira on 17/04/2019.
//

#include "Game.h"
Game::Game(){

}

Game::Game(Board board) {
    this->current_board = board;

    Board final = this->generate_final_board();
    this->final_board = final;

}

Board Game::generate_final_board() {

    int side_size = this->current_board.get_side_size();

    vector <vector <int> > board(side_size, vector<int> (side_size));
    int piece_counter = 1;

    for(int i = 0; i< side_size; i++){
        for (int j = 0; j < side_size; j++){
            board[i][j] = piece_counter;
            piece_counter++;
        }

    }

    board[side_size-1][side_size-1] = 0;

    Board b = Board(board);
    return b;

}

Board Game::get_final_board() {
    return this->final_board;
}

Board Game::get_current_board()& {
    return this->current_board;
}