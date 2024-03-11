
//Compiling this test (inside Heuristics folder): 
//g++ tests.cpp Zero.cpp ../puzzle_n_minus_1.cpp -o test

#include <iostream>
#include "../puzzle_n_minus_1.hpp"
#include "Heuristics.hpp"
#include "Zero.hpp"

int main(){

    Puzzle puzzle_sample(3,3);
    Heuristics* zero = new Zero();

    std::cout << zero->evaluate(puzzle_sample);

    delete zero;
    return 0;
}