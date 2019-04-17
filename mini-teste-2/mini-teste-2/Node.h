#ifndef MINI_TESTE_2_NODE_H
#define MINI_TESTE_2_NODE_H

#include <vector>
#include <string>
#include <iostream>
#include "Board.h"

class Node {
    public:
        Board board;
        Node* parent;
        char direction;
        int x;
        int y;
        unsigned int G;
        unsigned int H;

        Node(Board board, Node* parent = NULL, int x = -1, int y = -1, char direction = 'f');
        
        unsigned int getScore();

};

#endif //MINI_TESTE_2_AI_H