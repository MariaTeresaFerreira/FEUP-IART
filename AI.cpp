#include "AI.h"

using namespace std;


vector<Move> DFS(Board board, int total_cost){

    char directions[] = {'w','a','s','d'};
    vector<Move> path;

    if(total_cost > DEPTH_LIMIT){
        return path;
    }

    for(unsigned int i = 0; i < board.getPieces().size(); i++){
        for(unsigned int j = 0; j < 4; ++j){
            Move new_move;
            new_move.x = board.getPieces().at(i).getCells().at(0).getX(); 
            new_move.y = board.getPieces().at(i).getCells().at(0).getY();
            new_move.direction = directions[j];

                
                

                Board new_board = board;
                Cell c = board.getPieces().at(i).getCells().at(0);
                
                if (!board.possibleMove(c, directions[j])){
                    cout << "not possible move" << endl;
                    cout << c << directions[j]<< endl;
                    continue;
                }
                new_board.movePiece(c, directions[j]);
                
                new_board.cellsAdjacent();
                new_board.putMatrixEmpty();
                new_board.putPiecesMatrix();

                path.push_back(new_move);

            if(new_board.isGameFinished()){
                return path;
            }

            vector<Move> returning_path = DFS(new_board, total_cost + 1);

            path.insert(path.end(), returning_path.begin(), returning_path.end());

            return path;
        }
    }

    return path;
}

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

    cout << closedSet.size() << " - Astar nodes" << endl;

    releaseNodes(openSet);
    releaseNodes(closedSet);

    reverse(path.begin(), path.end());
    return path;
}

vector<Move> greedy(Board board)
{
    Node* current = nullptr;
    set<Node*> openSet, closedSet;
    openSet.insert(new Node(board));
    vector<Move> path;
    
    char directions[] = {'w','a','s','d'};

    while (!openSet.empty()) {
        current = *openSet.begin();
        for (auto node : openSet) {
            if (node->H <= current->H) {
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


                Node *successor = findNodeOnList(openSet, new_board);
                if (successor == nullptr) {
                    
                    successor = new Node(new_board, current, c.getX(), c.getY(), directions[i]);
                    successor->H = heuristic(successor->board);
                    openSet.insert(successor);
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
    cout << closedSet.size() << " - Greedy nodes" << endl;

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
