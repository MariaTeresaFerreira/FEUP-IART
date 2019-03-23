#include <iostream>
#include "Cell.h"

int main() {
    Cell cell = Cell(1,2);
    
    std::cout << "Hello, World!" << std::endl;
    std::cout << "X!" << cell.getX() <<  std::endl;
    std::cout << "Y!" << cell.getY() <<  std::endl;
    return 0;
}