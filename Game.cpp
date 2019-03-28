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

            this->draw();

            std::cout << this->imputCell();            
        }
    }

    Cell Game::imputCell(){
        int x;
        int y;
        while(true){
            std::cout << "Insert X of the Cell" << std::endl;
            std::cin >> x;
            if(x < 0 || x >= board.getColumns()){
                continue;
            } 
            std::cout << std::endl;

            std::cout << "Insert Y of the Cell" << std::endl;
            std::cin >> y;
            if(y < 0 || x >= board.getLines()){
                continue;
            }
            std::cout << std::endl;

            break;
        }

        return Cell(x,y);
    }



