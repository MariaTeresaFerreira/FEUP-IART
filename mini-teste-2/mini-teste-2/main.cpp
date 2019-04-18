#include <iostream>

#include <vector>
#include "Board.h"
#include "Game.h"
#include "AI.h"
using namespace std;

int main() {

    //vector<vector<int>> board_1{{1, 2, 3}, {5, 0, 6}, {4, 7, 8}};
    //vector<vector<int>> board_1{{1, 2, 3}, {0, 5, 6}, {4, 7, 8}};
    //vector<vector<int>> board_1{{1, 6, 2}, {5, 7, 3}, {0, 4, 8}};

    vector<vector<int>> board_1{{5, 1, 3, 4}, {2, 0, 7, 8}, {10, 6, 11, 12}, {9, 13, 14, 15}};

    /*
    vector<vector<int>> final_board_small{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    vector<vector<int>> final_board_big{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};*/


    Board b = Board(board_1);

    cout << "initial board:" << endl;
    //b.print_board();
    Game g = Game(board_1);

    vector<Move> path = BFS(g);



    for(int i = 0; i < path.size(); i++)

    {
        //cout << flush << "teste";
        cout << path.at(i).direction << endl;
    }

    /*
    g.make_move('a');
    b.print_board();
    g.make_move('s');
    b.print_board();
    g.make_move('d');
    b.print_board();
    g.make_move('d');
    b.print_board();*/








    return 0;
}