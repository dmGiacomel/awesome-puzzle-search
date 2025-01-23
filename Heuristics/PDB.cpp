#ifndef PDB_CPP
#define PDB_CPP
#include "PDB.hpp"

int PDB::evaluate (const Puzzle& puzzle_state){
    auto indexes = tableIndexes(puzzle_state);
    return pattern_values[std::get<0>(indexes)][std::get<1>(indexes)];
}

bool PDB::build (const Puzzle& initial_state, const Puzzle& goal_state){
    return true;
}

// tile_locations is always in ascending order in relation to tiles
// location tile a - location tile b - location tile c - ... with a = 0 < b < c < ...
std::vector<size_t> PDB::getTileLocations(const Puzzle& p){
    size_t pdb_tiles_size = pdb_tiles.size();

    std::vector<size_t> tile_locations(pdb_tiles_size + 1); //+1 because pdb_tiles disregard zero;
    std::vector<unsigned char> dual_state(IndexingFunctions::getDual(p.getPuzzleAsString()));

    //0 is not a part of pdb_tiles, therefore this needs to be done outside of for loop
    tile_locations[0] = dual_state[0];
    for(size_t i = 0; i < pdb_tiles_size; i++){
        tile_locations[i + 1] = dual_state[pdb_tiles[i]];
    }

    return std::move(tile_locations);
}

//--------- QUE FEIO, QUE FEEEEEIO, nao precisaria se tivesse sido mais esperto no passado -------------------------------------
// std::vector<unsigned char> gambiarra(const std::vector<size_t>& perm){
//     std::vector<unsigned char> vetordotipocerto(perm.size());
//     auto perm_size = perm.size();
//     for (size_t i = 0; i < perm_size; i++){
//         vetordotipocerto[i] = perm[i];
//     }
//     return std::move(vetordotipocerto);
// }
//------------------------------------------------------------------------
// // takes care of all the indexation logic
// // returns an iterator to the pdb table for a specific state

// unsigned char* PDB::tableLocation(const Puzzle& p){
//     std::vector<size_t> sorted_tile_locations = getTileLocations(p);

//     auto permutation = IndexingFunctions::sortPermutation(sorted_tile_locations);
//     //apply permutation so we don't have to sort it
//     //ahead of time optimization, but ...
//     sorted_tile_locations = IndexingFunctions::applyPermutation(sorted_tile_locations, permutation);

//     auto rank_tile_locations = IndexingFunctions::toCombinadicBase(sorted_tile_locations);
//     auto rank_permutation = IndexingFunctions::rank(permutation);

//     return (&pattern_values[rank_tile_locations][rank_permutation]);
// }

std::tuple<size_t, size_t> PDB::tableIndexes(const Puzzle& p){
    std::vector<size_t> sorted_tile_locations = getTileLocations(p);

    auto permutation = IndexingFunctions::sortPermutation(sorted_tile_locations);
    //apply permutation so we don't have to sort it
    //ahead of time optimization, but ...
    sorted_tile_locations = IndexingFunctions::applyPermutation(sorted_tile_locations, permutation);

    auto rank_tile_locations = IndexingFunctions::toCombinadicBase(sorted_tile_locations);
    auto rank_permutation = IndexingFunctions::rank(permutation);

    return std::make_tuple(rank_tile_locations, rank_permutation);
}


//---------------------------------------------------------------------------------------
// this can be improved by using a abstracted version of the puzzle
// no time for now!
void PDB::fillPatternArray(){
    auto goal_state = Puzzle(rows, columns); 
    
}

std::list<Puzzle> PDB::expand(const Puzzle& p){
    std::list<Puzzle> neighbours;

    auto available_moves = p.availableMoves();
    for (auto i : available_moves){
        Puzzle temp = p;
        temp.makeMove(i);
        neighbours.push_back(std::move(temp));
    }
    return std::move(neighbours);
}

void PDB::shapePatternArray(){

    size_t tile_combinations  = IndexingFunctions::binomialCoef(rows * columns, pdb_tiles.size() + 1); //+1 because pdb_tiles disregard zero;
    size_t tile_perms_per_combination = IndexingFunctions::factorial(pdb_tiles.size() + 1);

    pattern_values = std::vector<std::vector<unsigned char>>(
        tile_combinations,
        std::vector<unsigned char>(tile_perms_per_combination, INFINITY)
    );
}

size_t PDB::verify(){
    size_t slots_not_reached = 0;
    for (auto &i : pattern_values){
        for (auto j : i){
            if(j == UCHAR_MAX){
                slots_not_reached++;        
            }
        }
    }

    return slots_not_reached;
}


    void PDB::histogram(){
        
        std::map<unsigned char, size_t> hist;

        for (const auto& innerVec : pattern_values) {
            for (unsigned char value : innerVec) {
                hist[value]++;
            }
        }

        // Print the histogram
        std::cout << "Histogram:" << std::endl;
        for (const auto& pair : hist) {
            std::cout << static_cast<int>(pair.first) << ": " << pair.second << std::endl;
        }

    }
//---------------------------- DO NOT PASS 0 AS ARGUMENT INSIDE OF PDB_TILES ------------------
//---------------------------- please ---------------------------------------------------------
bool PDB::build (const Puzzle& initial_state, const Puzzle& goal_state, const std::vector<unsigned char>& pdb_tiles){
    rows = initial_state.getBoard().getRows();
    columns = initial_state.getBoard().getColumns();

    //pdb tiles should disregard zero
    this->pdb_tiles = pdb_tiles;
    std::sort(this->pdb_tiles.begin(), this->pdb_tiles.end());

    shapePatternArray();
    fillPatternArray();
    histogram();

    return true;
}

PDB::PDB(){

}

PDB::~PDB(){

}
#endif







// void PDB::fillPatternArray(){

//     //initial state (goal state for the search method)
//     size_t states = 0;
//     Puzzle p(rows, columns);
//     *tableLocation(p) = 0;

//     std::queue<Puzzle> open;
//     open.push(std::move(p));

//     while (!open.empty()){
//         Puzzle current = std::move(open.front());
//         open.pop();

//         //std::cout << "examining state: " << states++ << "with value: " << +*tableLocation(current) << "\n";
//         //std::cout << "queue states: " << open.size()<< "\n";
//         std::list<Puzzle> neighbours = expand(current);
//         for (Puzzle &i : neighbours){
//             auto current_table_position = tableLocation(i);
//             if (*current_table_position == UCHAR_MAX){
//                 *current_table_position = *tableLocation(current) + 1;
//                 open.push(std::move(i));
//             }
//         }
//     }
// }