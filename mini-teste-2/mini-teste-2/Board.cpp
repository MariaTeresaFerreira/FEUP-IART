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

vector < vector <int> > Board::get_board(){
    return this->board;
}

void Board::update_board(char dir, int x, int y){
    int prev_x, prev_y;
    int prev_value;
    switch(dir){
        case 'a':
            prev_x = x;
            prev_y = y - 1;
            break;
        case 'w':
            prev_x = x - 1;
            prev_y = y;
            break;
        case 'd':
            prev_x = x;
            prev_y = y + 1;
            break;
        case 's':
            prev_x = x + 1;
            prev_y = y;
            break;
        default:
            break;
    }

    prev_value = this->get_board()[prev_x][prev_y];
    this->board[x][y] = prev_value;
    this->board[prev_x][prev_y] = 0;

}

