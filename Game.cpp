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

        while(true){

            Cell inputCell;
            while(true){
                std::cout << "input a Valid Cell to play" << std::endl;
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
