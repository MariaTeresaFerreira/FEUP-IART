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
        //draw board on console
    }

    void Game::run(){

        while(true){

            this->draw();

            //read imput and process key
            
        }
    }



