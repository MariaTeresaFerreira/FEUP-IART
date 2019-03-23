//
// Created by Teresa Ferreira on 22/03/2019.
//

#ifndef FEUP_IART_CELL_H
#define FEUP_IART_CELL_H


class Cell {
    protected:
        int x;
        int y;

    public:
        Cell();

        Cell(int x, int y);

        int getX();

        int getY();

        void setX(int x);

        void setY(int y);

};


#endif //FEUP_IART_CELL_H
