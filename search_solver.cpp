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

    Puzzle initial_state(4,4);
    Puzzle goal_state(4,4);

    unsigned int seed = 42;
    srand(seed);
    int random_moves = 1000000;
    
    for(int i = 0; i < random_moves; i++)
        initial_state.makeMove(moves(rand() % 4));

    PDB *pdb = new PDB();
    pdb->build(initial_state, goal_state, {11, 10, 9, 15, 14, 13, 12});

    //Manhattan *pdb = new Manhattan();
    std::cout << "Initial State: \n";
    initial_state.printBoard();
    std::cout << std::endl;

    std::cout << "GoalState: \n";
    goal_state.printBoard();
    std::cout << std::endl;

    IDAStar *ida = new IDAStar();

    std::list<std::string> sequence = MovementsHandler::
                                      getNames(ida->solve(initial_state, goal_state, pdb));
    std::cout << "Solution sequence: ";
    for (auto i : sequence){
        std::cout << i << " ";
        //p.makeMove(MovementsHandler::getOpposite());
    }
    std::cout << std::endl;

    delete pdb; 
    delete ida;
    return 0;
}