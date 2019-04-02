//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Game.h"
#include <string>
#include <vector>

    Game::Game(){};

    Game::Game(Board board){
        this->board = board;
    }

    void Game::draw(){
        board.printBoard();
    }

    void Game::run(){

        std::string gameMode;

        while(true){
            std::cout << "Select game mode: " << std::endl << "1 - Human" << std::endl << "2 - AI" << std::endl;
            std::cin >> gameMode;
            if(gameMode == "1"){
                break;
                //Jogo humano normal
            } else if(gameMode == "2"){
                AIGame(this->board);
                //Jogo AI
                return;
            }
        }

        while(true){

            std::string input;

            while(true){
                std::cout << "Do you want a hint? (y/n)" << std::endl;
                std::cin >> input;

                if(input == "y"){
                    std::vector<Move> path = AStar(this->getBoardGame(), "3");

                    int x = path.at(0).x;
                    int y = path.at(0).y;
                    char direction = path.at(0).direction;
                    std::cout << "Try the move x: " << x
                              << " y: " << y
                              << " direction: " << direction << std::endl;
                    break;

                }else if( input == "n"){
                    break;
                }

            }





            Cell inputCell;
            while(true){
                std::cout << "Input a Valid Cell to play" << std::endl;
                inputCell = this->inputCell();

                if(board.hasPieceWithCell(inputCell))
                    break;
            }

            char direction = this->inputDirection();

            if(this->board.possibleMove(inputCell, direction)){
                this->board.movePiece(inputCell, direction);
                this->board.cellsAdjacent();
                this->board.putMatrixEmpty();
                this->board.putPiecesMatrix();
            }
            else{
                continue;
            }

            if(this->board.isGameFinished()){
                std::cout << "Good game!" << std::endl;
                break;
            }


        }
    }

    Cell Game::inputCell(){
        int x;
        int y;
        while(true){
            this->draw();
            std::cout << std::endl;

            std::cout << "Insert X of the Cell" << std::endl;
            std::cin >> x;
            if(x < 0 || x >= board.getColumns()){
                std::cout << "Invalid X" << std::endl;
                continue;
            }
            std::cout << std::endl;

            std::cout << "Insert Y of the Cell" << std::endl;
            std::cin >> y;
            if(y < 0 || x >= board.getLines()){
                std::cout << "Invalid Y" << std::endl;
                continue;
            }
            std::cout << std::endl;

            break;
        }
        return Cell(x,y);
    }

    char Game::inputDirection(){
        char direction;

        while(true){
            std::cout << "Press 'a' for left, 'w' for up, 'd for right or 's' for down" << std::endl;
            std::cin >> direction;

            if(direction == 'd' || direction == 'w' || direction == 'a' || direction == 's')
                break;
        }

        return direction;
    }

    std::vector<char> Game::inputAIDirection(Piece piece){
        char directions[] = {'w','a','s','d'};
        std::vector<char> possibleMoves;
        Cell cell = piece.getCells()[0];

        for(unsigned int i = 0; i < sizeof(directions); i++)
        {
            if(this->board.possibleMove(cell,directions[i]))
            possibleMoves.push_back(directions[i]);
        }
        return possibleMoves;
    }

void Game::AIGame(Board b){

    std::string algorithm;
    std::string heuristic_choice;
    std::vector<Move> path;
    std::chrono::duration<double> time_span;



    while(true){
        std::cout << "Select algorithm: " << std::endl
                  << "1 - AStar" << std::endl
                  << "2 - Greedy" << std::endl
                  << "3 - DFS (Depth-First Search)" << std::endl
                  << "4 - IDA (Iterative Deepening Algorithm)" << std::endl
                  << "5 - BFS (Breadth First Search)";
        std::cin >> algorithm;

            std::cout << "Select Heuristic: " << std::endl
                    << "1 - Distance of blocks from SAME COLOR" << std::endl
                    << "2 - Blocks(from same color) BIGGER THAN 1" << std::endl
                    << "3 - Distance from blocks w/ SAME COLOR BIGGER THAN 1" << std::endl;

            std::cin >> heuristic_choice;

            if(algorithm == "1"){

                std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
                path = AStar(this->getBoardGame(), heuristic_choice);
                std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);


                break;
            } else if(algorithm == "2"){

                std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
                path = greedy(this->getBoardGame(), heuristic_choice);
                std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);


                
                break;
            } else if(algorithm == "3"){


                std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
                path = DFS(this->getBoardGame());
                std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);

                break;
            }else if(algorithm == "4"){

                std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
                path = IDA(this->getBoardGame());
                std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
                time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);


                break;
            }else if(algorithm == "5"){

            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            path = BFS(this->getBoardGame());
            std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
            time_span = std::chrono::duration_cast<std::chrono::duration<double> >(t2 - t1);


            break;
            }

            
            }

    for(unsigned int i = 0; i < path.size(); i++){


        Cell inputCell(path.at(i).x, path.at(i).y);
        char direction = path.at(i).direction;

        std::cout << "play " << i+1 << ": " << std::endl;
        std::cout << inputCell.getX() << " " << inputCell.getY() << " " << direction << std::endl;



        this->board.movePiece(inputCell, direction);
        this->board.cellsAdjacent();
        this->board.putMatrixEmpty();
        this->board.putPiecesMatrix();

        this->board.printBoard();



    }
    std::cout << "Node number: " << node_counter << std::endl;
    std::cout << "Execution time:  " << time_span.count() << " seconds."<< std::endl;

}


Board Game::getBoardGame() {
    return this->board;


}
