#include "AI.h"

using namespace std;


#define DEPTH_LIMIT 15
#define IDA_LIMIT 20

int node_counter = 0;
int depth_cost = DEPTH_LIMIT;


vector<Move> BFS(Game game)
{


    queue<Node*> q;
    Node *current = new Node(game);

    current->G = 0;

    q.push(current);
    vector<Move> path;



    char directions[] = {'w','a','s','d'};


    while(!q.empty()){


        current = q.front();
        node_counter++;


        q.pop();


        if(current->game.isGameFinished()){
            break;
        }

        for(unsigned int i = 0; i < 4; i++){

            Game new_game = current->game;

            if(!new_game.is_move_valid(directions[i])){
                continue;
            }

            new_game.make_move(directions[i]);


            Node *current_temp = new Node(new_game, current, directions[i]);
            current_temp->G = current->G+1;


            q.push(current_temp);


        }

    }

    while (current != nullptr) {
        Move m;
        m.direction = current->direction;
        path.push_back(m);
        current = current->parent;
    }



    path.pop_back();
    reverse(path.begin(), path.end());

    return path;
}
//
//vector<Move> DFS(Board board, int total_cost){
//
//    char directions[] = {'w','a','s','d'};
//    vector<Move> path;
//
//    if(total_cost > depth_cost){
//        return path;
//    }
//
//    cout << "TOTAL cost: " << total_cost << endl;
//
//    for(unsigned int i = 0; i < board.getPieces().size(); i++){
//        for(unsigned int j = 0; j < 4; ++j){
//            Move new_move;
//            new_move.x = board.getPieces().at(i).getCells().at(0).getX();
//            new_move.y = board.getPieces().at(i).getCells().at(0).getY();
//            new_move.direction = directions[j];
//
//
//
//
//                Board new_board = board;
//                Cell c = board.getPieces().at(i).getCells().at(0);
//                new_board.movePiece(c, directions[j]);
//                if (!board.possibleMove(c, directions[j])){
//                    continue;
//                }
//
//
//                new_board.cellsAdjacent();
//                new_board.putMatrixEmpty();
//                new_board.putPiecesMatrix();
//
//
//            if(new_board.isGameFinished()){
//                path.push_back(new_move);
//                return path;
//            }
//
//            node_counter++;
//            vector<Move> returning_path = DFS(new_board, total_cost + 1);
//
//            if(returning_path.empty())
//                continue;
//
//            path.push_back(new_move);
//            path.insert(path.end(), returning_path.begin(), returning_path.end());
//
//            return path;
//        }
//    }
//
//    return path;
//}
//
//vector<Move> AStar(Board board, string heuristic_choice)
//{
//    Node* current = nullptr;
//    set<Node*> openSet, closedSet;
//    openSet.insert(new Node(board));
//    vector<Move> path;
//
//
//
//    char directions[] = {'w','a','s','d'};
//
//    while (!openSet.empty()) {
//        current = *openSet.begin();
//        node_counter++;
//        for (auto node : openSet) {
//            if (node->getScore() <= current->getScore()) {
//                current = node;
//            }
//        }
//
//        if (current->board.isGameFinished()) {
//            break;
//        }
//
//        closedSet.insert(current);
//
//
//        openSet.erase(std::find(openSet.begin(), openSet.end(), current));
//
//        for (unsigned int j = 0; j < current->board.getPieces().size(); j++){
//
//            for (unsigned int i = 0; i < 4; ++i) {
//
//                Board new_board = current->board;
//                Cell c = current->board.getPieces().at(j).getCells().at(0);
//                new_board.movePiece(c, directions[i]);
//                if (!current->board.possibleMove(c, directions[i]) ||
//                    findNodeOnList(closedSet, new_board)) {
//                    continue;
//                }
//                new_board.cellsAdjacent();
//                new_board.putMatrixEmpty();
//                new_board.putPiecesMatrix();
//
//                unsigned int totalCost = current->G + 1;
//
//                Node *successor = findNodeOnList(openSet, new_board);
//                if (successor == nullptr) {
//
//                    successor = new Node(new_board, current, c.getX(), c.getY(), directions[i]);
//                    successor->G = totalCost;
//
//                    if(heuristic_choice == "1"){
//                    successor->H = heuristic(successor->board);
//                    } else if(heuristic_choice == "2"){
//                    successor->H = heuristic_2(successor->board);
//                    } else if(heuristic_choice == "3"){
//                    successor->H = heuristic_3(successor->board);
//                    }
//                    openSet.insert(successor);
//                }
//                else if (totalCost < successor->G) {
//                    successor->parent = current;
//                    successor->G = totalCost;
//                }
//            }
//        }
//    }
//
//
//    while (current != nullptr) {
//
//
//
//        Move m;
//        m.x = current->x;
//        m.y = current->y;
//        m.direction = current->direction;
//        path.push_back(m);
//        current = current->parent;
//    }
//
//    releaseNodes(openSet);
//    releaseNodes(closedSet);
//    path.pop_back();
//
//    //node_number = closedSet.size();
//
//
//    reverse(path.begin(), path.end());
//
//
//    return path;
//}
//
//vector<Move> greedy(Board board, string heuristic_choice)
//{
//    Node* current = nullptr;
//    set<Node*> openSet, closedSet;
//    openSet.insert(new Node(board));
//    vector<Move> path;
//
//    char directions[] = {'w','a','s','d'};
//
//    while (!openSet.empty()) {
//        current = *openSet.begin();
//        node_counter++;
//        for (auto node : openSet) {
//            if (node->H <= current->H) {
//                current = node;
//            }
//        }
//
//        if (current->board.isGameFinished()) {
//            break;
//        }
//
//        closedSet.insert(current);
//        openSet.erase(std::find(openSet.begin(), openSet.end(), current));
//
//        for (unsigned int j = 0; j < current->board.getPieces().size(); j++){
//
//            for (unsigned int i = 0; i < 4; ++i) {
//
//                Board new_board = current->board;
//                Cell c = current->board.getPieces().at(j).getCells().at(0);
//                new_board.movePiece(c, directions[i]);
//                if (!current->board.possibleMove(c, directions[i]) ||
//                    findNodeOnList(closedSet, new_board)) {
//                    continue;
//                }
//                new_board.cellsAdjacent();
//                new_board.putMatrixEmpty();
//                new_board.putPiecesMatrix();
//
//
//                Node *successor = findNodeOnList(openSet, new_board);
//                if (successor == nullptr) {
//
//                    successor = new Node(new_board, current, c.getX(), c.getY(), directions[i]);
//
//                    if(heuristic_choice == "1"){
//                    successor->H = heuristic(successor->board);
//                    } else if(heuristic_choice == "2"){
//                    successor->H = heuristic_2(successor->board);
//                    } else if(heuristic_choice == "3"){
//                    successor->H = heuristic_3(successor->board);
//                    }
//                    openSet.insert(successor);
//                }
//
//            }
//        }
//        //cout << closedSet.size() << " - Greedy nodes" << endl;
//    }
//
//
//
//    while (current != nullptr) {
//
//
//
//        Move m;
//        m.x = current->x;
//        m.y = current->y;
//        m.direction = current->direction;
//        path.push_back(m);
//        current = current->parent;
//    }
//
//
//    releaseNodes(openSet);
//    releaseNodes(closedSet);
//    path.pop_back();
//
//    std::reverse(path.begin(), path.end());
//    return path;
//}
//
////TODO
//unsigned int heuristic_manhattan(Board board){
//
//}
////TODO
//unsigned int heuristic_hamming(Board board){
//
//}
//
//Node* findNodeOnList(set<Node*> & nodes_, Board board)
//{
//    for (auto node : nodes_) {
//        if (node->board.getPieces() == board.getPieces()) {
//            return node;
//        }
//    }
//    return nullptr;
//}
//
//void releaseNodes(set<Node*> & nodes_)
//{
//    for (auto it = nodes_.begin(); it != nodes_.end();) {
//        delete *it;
//        it = nodes_.erase(it);
//    }
//}