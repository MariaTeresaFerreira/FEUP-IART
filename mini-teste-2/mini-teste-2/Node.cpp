#include "Node.h"

Node::Node(Game game, Node* parent, char direction){
    this->game = game;
    this->parent = parent;
    this->direction = direction;
}
unsigned int Node::getScore(){
    return this->G + this->H;
}