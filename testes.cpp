#include <iostream>
#include "puzzle_n_minus_1.hpp"
#include "Algorithms/AStar.hpp"
#include "Heuristics/Zero.hpp"

int main(){
    
    Puzzle p(3,3);
    Zero heuristica;
    
    std::cout << heuristica.evaluate(p) << std::endl;

    
    return 0;
}