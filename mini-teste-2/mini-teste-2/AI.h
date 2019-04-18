#ifndef MINI_TESTE_2_AI_H
#define MINI_TESTE_2_AI_H

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <queue>

#include "Node.h"

extern int node_counter;

typedef struct{
    int x;
    int y;
    char direction;
} Move;

std::vector<Move> AStar(Board board, std::string heuristic_choice);
std::vector<Move> greedy(Game game, std::string heuristic_choice);
std::vector<Move> BFS(Game game);

Node* findNodeOnList(std::set<Node*>& nodes_, Board board);
unsigned int heuristic_hamming(Game game);
//unsigned int heuristic_2(Board board); Manhattan
void releaseNodes(std::set<Node*> & nodes_);


#endif //MINI_TESTE_2_AI_H