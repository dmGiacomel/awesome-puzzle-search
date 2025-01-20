#include "PDBAbstractedPuzzle.hpp"
#include <iostream>

int main(){
    PDBAbstraction abs({3,1,0,4}, 
                       {0,9,12,14},
                       4, 4);

    abs.printAbstraction();

    std::cout << std::endl;

    abs.makeMove(up);
    abs.makeMove(right);
    abs.makeMove(down);

    abs.printAbstraction();

    auto position_of_empty = abs.getPositionOfEmpty();

    std::cout << "position_of_empty: " << +std::get<0>(position_of_empty) << "\t"<< +std::get<1>(position_of_empty) << std::endl;
}