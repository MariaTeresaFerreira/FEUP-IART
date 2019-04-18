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

vector<Move> AStar(Game game, string heuristic_choice)
{
    Node* current = nullptr;
    set<Node*> openSet, closedSet;
    openSet.insert(new Node(game));
    vector<Move> path;


    
    char directions[] = {'w','a','s','d'};

    while (!openSet.empty()) {
        current = *openSet.begin();
        node_counter++;
        for (auto node : openSet) {
            if (node->getScore() <= current->getScore()) {
                current = node;
            }
        }

        if (current->game.isGameFinished()) {
            break;
        }

        closedSet.insert(current);


        openSet.erase(std::find(openSet.begin(), openSet.end(), current));

        for (unsigned int j = 0; j < current->board.getPieces().size(); j++){

            for (unsigned int i = 0; i < 4; ++i) {

                Game new_game = current->game;
                if (!new_game.is_move_valid(directions[i]) ||
                    findNodeOnList(closedSet, new_board)) {
                    continue;
                }
                new_game.make_move(directions[i]);

                unsigned int totalCost = current->G + 1;

                Node *successor = findNodeOnList(openSet, new_game);
                if (successor == nullptr) {
                    
                    successor = new Node(new_game, current, directions[i]);
                    successor->G = totalCost;
                    
                    if(heuristic_choice == "1"){
                    successor->H = heuristic_hamming(successor->game);
                    } else if(heuristic_choice == "2"){
                    successor->H = heuristic_2(successor->board);
                    }
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
    path.pop_back();

    //node_number = closedSet.size();


    reverse(path.begin(), path.end());


    return path;
}

vector<Move> greedy(Game game, string heuristic_choice)
{
    Node* current = nullptr;
    set<Node*> openSet, closedSet;
    openSet.insert(new Node(game));
    vector<Move> path;
    
    char directions[] = {'w','a','s','d'};

    while (!openSet.empty()) {
        current = *openSet.begin();
        node_counter++;
        for (auto node : openSet) {
            if (node->H <= current->H) {
                current = node;
            }
        }

        if (current-> game.isGameFinished()) {
            break;
        }

        closedSet.insert(current);
        openSet.erase(std::find(openSet.begin(), openSet.end(), current));

        for (unsigned int j = 0; j < current->board.getPieces().size(); j++){

            for (unsigned int i = 0; i < 4; ++i) {

                Game new_game = current->game;
                if (!new_game.is_move_valid(directions[i]) ||
                    findNodeOnList(closedSet, new_game)) {
                    continue;
                }

                new_game.make_move(directions[i]);


                Node *successor = findNodeOnList(openSet, new_game);
                if (successor == nullptr) {
                    
                    successor = new Node(new_game, current, directions[i]);
                                        
                    if(heuristic_choice == "1"){
                    successor->H = heuristic_hamming(successor->game);
                    } else if(heuristic_choice == "2"){
                    successor->H = heuristic_manhattan(successor->game);
                    }
                    openSet.insert(successor);
                }
                
            }
        }
        //cout << closedSet.size() << " - Greedy nodes" << endl;
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
    path.pop_back();

    std::reverse(path.begin(), path.end());
    return path;
}

//TODO
unsigned int heuristic_manhattan(Game game){

}
unsigned int heuristic_hamming(Game game){
    int side_size = this->current_board.get_side_size();
    int conflicts = 0;

    vector <vector <int> > board =  game.current_board.get_current_board();
    vector <vector <int> > final =  game.final_board.get_current_board();

    for(int i = 0; i< side_size; i++){
        for (int j = 0; j < side_size; j++){
            if(board[i][j] != final[i][j])conflicts++;
            else continue;
        }
    }
    return conflicts;
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