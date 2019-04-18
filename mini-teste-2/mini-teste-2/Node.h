#ifndef MINI_TESTE_2_NODE_H
#define MINI_TESTE_2_NODE_H

#include <vector>
#include <string>
#include <iostream>
#include "Board.h"
#include "Game.h"

class Node {
    public:
        Game game;
        Node* parent;
        char direction;
        unsigned int G;
        unsigned int H;

        Node(Game game, Node* parent = NULL, char direction = 'f');
        
        unsigned int getScore();

};

#endif //MINI_TESTE_2_AI_H