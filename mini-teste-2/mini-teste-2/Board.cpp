//
// Created by Teresa Ferreira on 17/04/2019.
//

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(){}

Board::Board(vector<vector<int>> board) {
    this->board = board;
    this->side_size = board.size();
}

void Board::print_board(){

    for(int i = 0; i < this->side_size; i++){

        for(int j = 0; j < this->side_size; j++){
            cout << this->board[i][j];
        }
        cout << endl;
    }

}

int Board::get_side_size(){
    return this->side_size;
}
vector<vector<int>> Board::get_current_board(){
    return this->board;
}