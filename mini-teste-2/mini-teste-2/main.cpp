#include <iostream>

#include <vector>
#include "Board.h"
#include "Game.h"
using namespace std;

int main() {

    vector<vector<int>> board_1{{1, 2, 3}, {5, 0, 6}, {4, 7, 8}};
    vector<vector<int>> board_2{{1, 3, 6}, {5, 2, 0}, {4, 7, 8}};
    vector<vector<int>> board_3{{1, 6, 2}, {5, 7, 3}, {0, 4, 8}};

    vector<vector<int>> final_board_small{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    vector<vector<int>> final_board_big{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};


    Board b = Board(board_1);

    cout << "initial board:" << endl;
    b.print_board();

    Game g = Game(board_1);

    g.get_current_board().print_board();


    g.get_final_board().print_board();




    return 0;
}