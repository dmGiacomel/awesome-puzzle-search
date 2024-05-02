#include "puzzle_n_minus_1.hpp"

#include "Utils/MovementsHandler.hpp"
#include "Utils/IndexFunctions.hpp"

#include "Heuristics/PDB.hpp"
#include "Heuristics/Manhattan.hpp"
#include "Heuristics/MisplacedTileCount.hpp"
#include "Heuristics/Zero.hpp"

#include "Algorithms/AStar.hpp"
#include "Algorithms/IDAStar.hpp"


int main (int argc, char **argv){

    Puzzle initial_state(3,3);
    Puzzle goal_state(3,3);

    unsigned int seed = 42;
    srand(seed);
    int random_moves = 1111;
    
    for(int i = 0; i < random_moves; i++)
        initial_state.makeMove(moves(rand() % 4));

    Heuristics *pdb = new PDB();

    return 0;
}