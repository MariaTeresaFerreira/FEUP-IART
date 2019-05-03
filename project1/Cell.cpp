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

    bool operator== (const Cell& cell1, const Cell& cell2){
        return (cell1.x == cell2.x && cell1.y == cell2.y) ? true : false;
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

    unsigned int Cell::getCellDistance(Cell cell){
        if(cell.getX() == this->x)
            return std::abs(cell.getY() - this->y - 1);
        else if(cell.getY() == this->y)
            return std::abs(cell.getX() - this->x - 1);
        else
            return std::abs(cell.getY() - this->y) +  std::abs(cell.getX() - this->x) - 1;
    }

    

