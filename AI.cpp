#include "AI.h"

using namespace std;

int depth_cost = DEPTH_LIMIT;


vector<Move> BFS(Board board)
{

    //-----------------FINAL BOARD----------------------
    Cell cellb1 = Cell(0,0);
    Cell cellb2 = Cell(1,0);
    Cell cellb3 = Cell(0,1);

    Cell cellg1 = Cell(1,1);
    Cell cellg2 = Cell(1,2);
    Cell cellg3 = Cell(1,3);
    Cell cellg4 = Cell(2,3);

    Cell cellr1 = Cell(2,1);
    Cell cellr2 = Cell(3,1);
    Cell cellr3 = Cell(3,2);
    Cell cellr4 = Cell(3,3);

    std::vector<Cell> cells1;
    std::vector<Cell> cells2;
    std::vector<Cell> cells3;

    cells1.push_back(cellb1);
    cells1.push_back(cellb2);
    cells1.push_back(cellb3);

    cells2.push_back(cellg1);
    cells2.push_back(cellg2);
    cells2.push_back(cellg3);
    cells2.push_back(cellg4);

    cells3.push_back(cellr1);
    cells3.push_back(cellr2);
    cells3.push_back(cellr3);
    cells3.push_back(cellr4);

    Piece piece1 = Piece("blue", cells1);
    Piece piece2 = Piece("green", cells2);
    Piece piece3 = Piece("red", cells3);

    std::vector<Piece> pieces;

    pieces.push_back(piece1);
    pieces.push_back(piece2);
    pieces.push_back(piece3);

    Board final_board = Board(4,4,pieces);

    //-----------------FINAL BOARD----------------------

    int level = 0;
    queue<Node*> q;
    Node *n = new Node(board);
    Node *current = n;
    current->G = 0;

    q.push(current);
    vector<Move> path;


    char directions[] = {'w','a','s','d'};


    while(!q.empty()){

        current = q.front();
        q.pop();

        if(current->board.isGameFinished()){
        //if(current->board.getPieces() == final_board.getPieces()){
            break;
        }

        if(current->G > level){
            level++;
            cout << "depth level: " << level << endl;
        }

        for(unsigned int i = 0; i < current->board.getPieces().size(); i++) {
            for (unsigned int j = 0; j < 4; j++) {
                Board new_board = current->board;
                Cell c = board.getPieces().at(i).getCells().at(0);

                if (!board.possibleMove(c, directions[j])) {
                    continue;
                }

                new_board.movePiece(c, directions[j]);



                new_board.cellsAdjacent();
                new_board.putMatrixEmpty();
                new_board.putPiecesMatrix();

                Node *current_temp = new Node(new_board, current, c.getX(), c.getY(), directions[j]);
                current_temp->G = current->G+1;

                q.push(current_temp);
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

    path.pop_back();
    reverse(path.begin(), path.begin());
    return path;
}



vector<Move> IDA(Board board){

    depth_cost = 0;
    vector<Move> path;

    while(path.empty() && depth_cost <= IDA_LIMIT){

        path = DFS(board);
        cout << "DEPTH cost: " << depth_cost << endl;
        depth_cost++;

    }

    return path;
}



vector<Move> DFS(Board board, int total_cost){

    char directions[] = {'w','a','s','d'};
    vector<Move> path;

    if(total_cost > depth_cost){
        return path;
    }

    cout << "TOTAL cost: " << total_cost << endl;

    for(unsigned int i = 0; i < board.getPieces().size(); i++){
        for(unsigned int j = 0; j < 4; ++j){
            Move new_move;
            new_move.x = board.getPieces().at(i).getCells().at(0).getX(); 
            new_move.y = board.getPieces().at(i).getCells().at(0).getY();
            new_move.direction = directions[j];

                
                

                Board new_board = board;
                Cell c = board.getPieces().at(i).getCells().at(0);
                new_board.movePiece(c, directions[j]);
                if (!board.possibleMove(c, directions[j])){
                    continue;
                }

                
                new_board.cellsAdjacent();
                new_board.putMatrixEmpty();
                new_board.putPiecesMatrix();


            if(new_board.isGameFinished()){
                path.push_back(new_move);
                return path;
            }

            vector<Move> returning_path = DFS(new_board, total_cost + 1);

            if(returning_path.empty())
                continue;

            path.push_back(new_move);
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
    path.pop_back();

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
    path.pop_back();

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