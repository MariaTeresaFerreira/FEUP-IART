#include "AI.h"

using namespace std;

vector<Move> AStar(Board board)
{
    Node *current = nullptr;
    set<Node*> openSet, closedSet;
    openSet.insert(new Node(board));
    vector<Move> path;
    
    int directions[] = {'w','a','s','d'};

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
                
                if (new_board.possibleMove(c, directions[i]) ||
                    findNodeOnList(closedSet, new_board)) {
                    continue;
                }

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

    return path;
}

unsigned int heuristic(Board board){
    return 0;
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
