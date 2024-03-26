#include <iostream>
#include "puzzle_n_minus_1.hpp"
#include "Algorithms/AStar.hpp"
#include "Heuristics/Zero.hpp"

int main(){
    
    Puzzle p(3,3);

        p.printBoard();

    Heuristics* zero = new Zero();
    AStar a_estrela;

    p.makeMove(right);
    p.makeMove(down);
    p.makeMove(left);
    p.makeMove(up);

    p.printBoard();

    std::cout << "\n";

    std::cout << "Before calling solve method\n";
    std::list<moves> sequence = a_estrela.solve(Puzzle(3,3), p, zero);

    for (auto i : sequence){
        std::cout << i;
    }
    
    return 0;
}