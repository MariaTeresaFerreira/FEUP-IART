//
// Created by Teresa Ferreira on 17/04/2019.
//

#ifndef MINI_TESTE_2_BOARD_H
#define MINI_TESTE_2_BOARD_H

#include <vector>
using namespace std;

class Board {
private:
    vector < vector <int> > board;
    int side_size;

public:
    Board();
    Board(vector<vector<int>> board);
    void print_board();
    int get_side_size();

};


#endif //MINI_TESTE_2_BOARD_H
