#include "PDB.hpp"

int main(){
    PDB h;

    h.build(Puzzle(4,4), Puzzle(4,4), {12, 13, 14, 15});

    // h.build(Puzzle(4,4), Puzzle(4,4), {9, 10, 11, 12, 13, 14, 15});

    std::cout << "slots not reached: " << h.verify() << std::endl;
    
}