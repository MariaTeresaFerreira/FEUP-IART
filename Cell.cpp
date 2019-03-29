//
// Created by Teresa Ferreira on 22/03/2019.
//

#include "Cell.h"

    Cell::Cell(){};

    Cell::Cell(int x, int y){
        this->x = x;
        this->y = y;
    }

    int Cell::getX(){
        return this->x;

    }

    int Cell::getY(){

        return this->y;

    }

    void Cell::setX(int x){

        this->x = x;
    }

    void Cell::setY(int y){
        this->y = y;
    }

    void Cell::printCellInfo(Cell cell){
        std::cout << "X value:" << this->getX() << std::endl << "Y value:" << this->getY() << std::endl;
    }

    std::ostream& operator<< (std::ostream& stream, const Cell& cell){
        stream << cell.x << " " << cell.y << "\n";
        return stream;
    }

    bool Cell::isAdjacent(Cell cell){
        
        if(this->getX() - 1 == cell.getX() && this->getY() == cell.getY())
            return true;
        else if(this->getX() + 1 == cell.getX() && this->getY() == cell.getY())
            return true;
        else if(this->getY() - 1 == cell.getY() && this->getX() == cell.getX())
            return true;
        else if(this->getY() + 1 == cell.getY() && this->getX() == cell.getX())
            return true;

        return false;
    }

    

