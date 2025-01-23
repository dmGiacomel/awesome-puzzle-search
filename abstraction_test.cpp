#include "PDBAbstractedPuzzle.hpp"
#include <iostream>

int main(){
    PDBAbstraction abs({2,1,0,3}, 
                       {0,9,12,14},
                       4, 4);

    abs.printAbstraction();

    std::cout << std::endl;

    abs.makeMove(up);
    abs.makeMove(right);
    abs.makeMove(down);

    abs.printAbstraction();

    std::cout << std::endl;

    abs.makeMove(up);
    abs.makeMove(up);
    abs.makeMove(up);
    abs.makeMove(left);

    abs.printAbstraction();
    std::cout << std::endl;

        abs.makeMove(right);
            abs.printAbstraction();


}
