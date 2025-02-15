#include "APDBAbstractedPuzzle.hpp"

int main (){

    ZeroRegionMapping zero_map(4,4,6);
    Puzzle puzzle({7,8,5,4,1,2,0,3,12,15,10,9,6,11,14,13}, 4, 4);
    APDBAbstraction abs(puzzle, {1, 6, 7, 8, 11, 13, 14});

    // ZeroRegionMapping zero_map(4,4,6);
    // APDBAbstraction abs({0, 1}, {2,7}, 4, 4, std::make_tuple<unsigned char, unsigned char>(1,2));
    
    // abs.makeMove(up);
    // abs.makeMove(down);
    // abs.makeMove(down);


    abs.printAbstraction();
}