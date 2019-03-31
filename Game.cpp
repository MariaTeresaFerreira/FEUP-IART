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

        int gameMode;

        while(true){
            std::cout << "Select game mode: " << std::endl << "1 - Human" << std::endl << "2 - AI" << std::endl;
            std::cin >> gameMode;
            if(gameMode == 1){
                break;
                //Jogo humano normal
            } else if(gameMode == 2){
                AIGame(this->board);
                //Jogo AI
                return;
            }
        }

        while(true){

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

    int algorithm;
    std::vector<Move> path;

    while(true){
        std::cout << "Select algorithm: " << std::endl << "1 - AStar" << std::endl << "2 - Greedy" << std::endl << "3 - DFS (Depth-First Search)" << std::endl;
        std::cin >> algorithm;
        if(algorithm == 1){
            path = AStar(this->getBoardGame());

            break;
        } else if(algorithm == 2){
            path = greedy(this->getBoardGame());
            
            break;
        } else if(algorithm == 3){
            path = DFS(this->getBoardGame());

            for(auto move: path){
                std::cout << move.x << " " << move.y << " " << move.direction << std::endl;
            }
            break;
        }
    }

    for(unsigned int i = 0; i < path.size(); i++){


        Cell inputCell(path.at(i).x, path.at(i).y);
        char direction = path.at(i).direction;

        std::cout << "play " << i << ": " << std::endl;
        std::cout << inputCell.getX() << " " << inputCell.getY() << " " << direction << std::endl;



        this->board.movePiece(inputCell, direction);
        this->board.cellsAdjacent();
        this->board.putMatrixEmpty();
        this->board.putPiecesMatrix();

        this->board.printBoard();



    }

}

Board Game::getBoardGame() {
    return this->board;


}
