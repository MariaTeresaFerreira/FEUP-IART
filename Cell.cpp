//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Cell.h"
    Cell::Cell(){};

    Cell::Cell(int x, int y){
        this.x = x;
        this.y = y;
    }

    int Cell::getX(){
        return this.x;
    }

    int Cell::getY(){
        return this.y;
    }

    void Cell::setX(int x){
        this.x = x;
    }

    void Cell::setY(int y){
        this.y = y;
    }

    

