#ifndef FEUP_IART_AI_H
#define FEUP_IART_AI_H

#include <string>
#include <iostream>
#include "Board.h"
#include "Node.h"
#include "Cell.h"
#include "Piece.h"
#include "Game.h"
#include <set>
#include <vector>
#include <queue>

typedef struct{
    int x;
    int y;
    char direction;
} Move;

std::vector<Move> AStar(Board board, std::string heuristic_choice);
std::vector<Move> greedy(Board board, std::string heuristic_choice);
std::vector<Move> DFS(Board board, int total_cost = 0);
std::vector<Move> IDA(Board board);
std::vector<Move> BFS(Board board);

Node* findNodeOnList(std::set<Node*>& nodes_, Board board);
unsigned int heuristic(Board board);
unsigned int heuristic_2(Board board);
unsigned int heuristic_3(Board board);
void releaseNodes(std::set<Node*> & nodes_);


#endif //FEUP_IART_AI_H