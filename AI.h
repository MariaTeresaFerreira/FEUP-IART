#ifndef FEUP_IART_AI_H
#define FEUP_IART_AI_H

#include <string>
#include <iostream>
#include "Board.h"
#include "Node.h"
#include "Cell.h"
#include "Piece.h"
#include <set>
#include <vector>

#define DEPTH_LIMIT 10
#define IDA_LIMIT 20

typedef struct{
    int x;
    int y;
    char direction;
} Move;

std::vector<Move> AStar(Board board);
std::vector<Move> greedy(Board board);
std::vector<Move> DFS(Board board, int total_cost = 0);
std::vector<Move> IDA(Board board);
std::vector<Move> BFS(Board board);

Node* findNodeOnList(std::set<Node*>& nodes_, Board board);
unsigned int heuristic(Board board);
void releaseNodes(std::set<Node*> & nodes_);



#endif //FEUP_IART_AI_H