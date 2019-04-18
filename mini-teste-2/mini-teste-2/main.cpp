#include <iostream>

#include <vector>
#include "Board.h"
#include "Game.h"
using namespace std;

int main() {

    //vector<vector<int>> board_1{{1, 2, 3}, {5, 0, 6}, {4, 7, 8}};
    //vector<vector<int>> board_1{{1, 2, 3}, {0, 5, 6}, {4, 7, 8}};
    vector<vector<int>> board_1{{1, 3, 6}, {4, 7, 8}, {5, 2, 0}};
    /*
    vector<vector<int>> board_3{{1, 6, 2}, {5, 7, 3}, {0, 4, 8}};

    vector<vector<int>> final_board_small{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    vector<vector<int>> final_board_big{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};*/


    Board b = Board(board_1);

    //cout << "initial board:" << endl;
    b.print_board();

    Game g = Game(board_1);

    g.make_move('w');
    cout << endl << endl << "w" << endl;
    g.get_current_board().print_board();

    g.make_move('a');
    cout << endl << endl << "a" << endl;
    g.get_current_board().print_board();

    g.make_move('s');
    cout << endl << endl << "s" << endl;
    g.get_current_board().print_board();

    g.make_move('d');
    cout << endl << endl << "d" << endl;
    g.get_current_board().print_board();


    //g.get_final_board().print_board();



    if(g.isGameFinished())
        cout << "WON" << endl;
    else cout << "NOT WON" << endl;




    return 0;
}