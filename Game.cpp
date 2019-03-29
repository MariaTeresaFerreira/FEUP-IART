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

            Cell imputCell;
            while(true){
                std::cout << "Imput a Valid Cell to play" << std::endl;
                imputCell = this->imputCell();
                
                if(board.hasPieceWithCell(imputCell))
                    break;
            }

            char direction = this->imputDirection();

            if(this->board.possibleMove(imputCell, direction)){
                this->board.movePiece(imputCell, direction);
                this->board.putMatrixEmpty();
                this->board.putPiecesMatrix();
            }
            else{
                continue;
            }
            
            //check if game ended
        }
    }

    Cell Game::imputCell(){
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

    char Game::imputDirection(){
        char direction;

        while(true){
            std::cout << "Press 'a' for left, 'w' for up, 'd for right or 's' for down" << std::endl;
            std::cin >> direction;

            if(direction == 'd' || direction == 'w' || direction == 'a' || direction == 's')
                break;
        }
       
        return direction;
    }

    


