#include "Node.h"

Node::Node(Board board, Node* parent, int x, int y, char direction){
    this->board = board;
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->direction = direction;
}
unsigned int Node::getScore(){
    return this->G + this->H;
}