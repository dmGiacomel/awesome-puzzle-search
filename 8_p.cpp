#include "puzzle_n_minus_1.hpp"

#include "Utils/MovementsHandler.hpp"
#include "Utils/IndexFunctions.hpp"

#include "Heuristics/PDB.hpp"
#include "Heuristics/APDB.hpp"
#include "Heuristics/APDBSet.hpp"
#include "Heuristics/Manhattan.hpp"
#include "Heuristics/MisplacedTileCount.hpp"
#include "Heuristics/Zero.hpp"

#include "Algorithms/AStar.hpp"
#include "Algorithms/IDAStar.hpp"

const size_t N_RANDOM_INSTANCES = 100000;
const int rows = 3;
const int columns = 3;
const int N_RANDOM_MOVES = 10000;
const int seed_value = 42;

Puzzle getRandomPuzzleInstance(){
    Puzzle p(rows, columns); 

    for(int i = 0; i < N_RANDOM_MOVES; i++)
        p.makeMove(moves(rand() % 4));

    return p;
}

int main (int argc, char **argv){

    Puzzle initial_state(rows, columns);
    Puzzle goal_state(rows, columns);

    srand(seed_value);

    PDB *pdb = new PDB();
    pdb->build(initial_state, goal_state, {7, 6, 5, 4, 1});

    AStar *a = new AStar();
    IDAStar *ida = new IDAStar();
    // saida em linha separado por espaços, uma linha para cada execucao
    // <iteracao> <runtime> <estados gerados> <heuristica media> <sol_size> 
    for (size_t i = 0; i < N_RANDOM_INSTANCES; i++){

        initial_state = getRandomPuzzleInstance();
        std::cout << i << " ";
        auto result = a->solve(initial_state, goal_state, pdb);
        std::cout << result.size();
        std::cout << std::endl;
        std::cin.get();
    }

    std::cout << "-" << std::endl;
    srand(seed_value);

    for (size_t i = 0; i < N_RANDOM_INSTANCES; i++){

        initial_state = getRandomPuzzleInstance();
        std::cout << i << " ";
        auto result = ida->solve(initial_state, goal_state, pdb);
        std::cout << result.size();
        std::cout << std::endl;
        std::cin.get();
    }

    delete pdb; 
    delete ida;
    delete a;
    return 0;
}