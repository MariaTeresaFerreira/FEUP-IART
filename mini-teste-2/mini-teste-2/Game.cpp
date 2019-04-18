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

bool Game::isGameFinished() {
    int side_size = this->current_board.get_side_size();

    vector <vector <int> > board =  this->current_board.get_current_board();
    vector <vector <int> > final =  this->final_board.get_current_board();

    for(int i = 0; i< side_size; i++){
        for (int j = 0; j < side_size; j++){
            if(board[i][j] != final[i][j]) return false;
            else continue;
        }
    }

    return true;
}


vector<int> Game::get_0_pos(){

    for(int i = 0; i < this->current_board.get_side_size(); i++){
        for(int j = 0; j < this->current_board.get_side_size(); j++){
            if(this->current_board.get_board()[i][j] == 0){
                vector<int> coords {i, j};
                return coords;
            }
        }
    }

}

bool Game::is_move_valid(char dir){

    vector<int> coords = this->get_0_pos();
    int x = coords[0];
    int y = coords[1];
    int max = this->current_board.get_side_size() - 1;


    switch(dir){
        case 'a':
            if(y == 0)
                return false;
            break;
        case 'w':
            if(x == 0)
                return false;
            break;
        case 'd':
            if(y == max)
                return false;
            break;
        case 's':
            if(x == max)
                return false;
            break;
        default:
            break;
    }
    return true;

}