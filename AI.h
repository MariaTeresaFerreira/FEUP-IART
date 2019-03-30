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

typedef struct{
    int x;
    int y;
    char direction;
} Move;

std::vector<Move> AStar(Board board);
Node* findNodeOnList(std::set<Node*>& nodes_, Board board);
unsigned int heuristic(Board board);
void releaseNodes(std::set<Node*> & nodes_);



#endif //FEUP_IART_AI_H