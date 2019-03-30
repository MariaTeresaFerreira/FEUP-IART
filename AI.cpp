#include "AI.h"

using namespace std;

vector<Move> AStar(Board board)
{
    Node* current = nullptr;
    set<Node*> openSet, closedSet;
    openSet.insert(new Node(board));
    vector<Move> path;
    
    char directions[] = {'w','a','s','d'};

    while (!openSet.empty()) {
        current = *openSet.begin();
        for (auto node : openSet) {
            if (node->getScore() <= current->getScore()) {
                current = node;
            }
        }

        if (current->board.isGameFinished()) {
            break;
        }

        closedSet.insert(current);
        openSet.erase(std::find(openSet.begin(), openSet.end(), current));

        for (unsigned int j = 0; j < current->board.getPieces().size(); j++){

            for (unsigned int i = 0; i < 4; ++i) {

                Board new_board = current->board;
                Cell c = current->board.getPieces().at(j).getCells().at(0);
                new_board.movePiece(c, directions[i]);
                if (!current->board.possibleMove(c, directions[i]) ||
                    findNodeOnList(closedSet, new_board)) {
                    continue;
                }
                new_board.cellsAdjacent();
                new_board.putMatrixEmpty();
                new_board.putPiecesMatrix();
                std::cout << "ola 2" << std::endl;

                unsigned int totalCost = current->G + 1;

                Node *successor = findNodeOnList(openSet, new_board);
                if (successor == nullptr) {
                    
                    successor = new Node(new_board, current, c.getX(), c.getY(), directions[i]);
                    successor->G = totalCost;
                    successor->H = heuristic(successor->board);
                    openSet.insert(successor);
                }
                else if (totalCost < successor->G) {
                    successor->parent = current;
                    successor->G = totalCost;
                }
            }
        }
    }

    std::cout << "current board: " << current->board << std::endl;

    while (current != nullptr) {



        Move m;
        m.x = current->x;
        m.y = current->y;
        m.direction = current->direction;
        path.push_back(m);
        current = current->parent;
    }

    releaseNodes(openSet);
    releaseNodes(closedSet);

    std::reverse(path.begin(), path.end());
    return path;
}

unsigned int heuristic(Board board){
    vector<Piece> red;
    vector<Piece> green;
    vector<Piece> blue;
    vector<Piece> yellow;
    unsigned int heu = 0;

    for(unsigned int i = 0; i < board.getPieces().size(); i++){
        if(board.getPieces()[i].getColor() == "red")
            red.push_back(board.getPieces()[i]);
        else if(board.getPieces()[i].getColor() == "blue")
            blue.push_back(board.getPieces()[i]);
        else if(board.getPieces()[i].getColor() == "green")
            green.push_back(board.getPieces()[i]);
        else if(board.getPieces()[i].getColor() == "yellow")
            yellow.push_back(board.getPieces()[i]);
    }

    if(red.size() > 1 ){
        for(unsigned int i = 0; i < red.size(); i++){
            for(unsigned int j = (i + 1); j < red.size(); j++){
                heu += red[i].getPieceDistance(red[j]);
            }               
        }
    }

    if(blue.size() > 1){
        for(unsigned int i = 0; i < blue.size(); i++){
            for(unsigned int j = (i + 1); j < blue.size(); j++){
                heu += blue[i].getPieceDistance(blue[j]);
            }               
        }
    }

    if(green.size() > 1){
        for(unsigned int i = 0; i < green.size(); i++){
            for(unsigned int j = (i + 1); j < green.size(); j++){
                heu += green[i].getPieceDistance(green[j]);
            }               
        }
    }

    if(yellow.size() > 1){
        for(unsigned int i = 0; i < yellow.size(); i++){
            for(unsigned int j = (i + 1); j < yellow.size(); j++){
                heu += yellow[i].getPieceDistance(yellow[j]);
            }               
        }
    }
    return heu;
}
        
Node* findNodeOnList(set<Node*> & nodes_, Board board)
{
    for (auto node : nodes_) {
        if (node->board.getPieces() == board.getPieces()) {
            return node;
        }
    }
    return nullptr;
}

void releaseNodes(set<Node*> & nodes_)
{
    for (auto it = nodes_.begin(); it != nodes_.end();) {
        delete *it;
        it = nodes_.erase(it);
    }
}
