#ifndef PDB_CPP
#define PDB_CPP
#include "PDB.hpp"

int PDB::evaluate (const Puzzle& puzzle_state){
    return (*tableLocation(puzzle_state));
}

// tile_locations is always in ascending order in relation to tiles
// location tile a - location tile b - location tile c - ... with a = 0 < b < c < ...
std::vector<unsigned char> PDB::getTileLocations(const Puzzle& p){
    size_t pdb_tiles_size = pdb_tiles.size();

    std::vector<unsigned char> tile_locations(pdb_tiles_size + 1); //+1 because pdb_tiles disregard zero;
    std::vector<unsigned char> dual_state(IndexingFunctions::getDual(p.getPuzzleAsString()));

    //0 is not a part of pdb_tiles, therefore this needs to be done outside of for loop
    tile_locations[0] = dual_state[0];
    for(size_t i = 0; i < pdb_tiles_size; i++){
        tile_locations[i + 1] = dual_state[pdb_tiles[i]];
    }

    return tile_locations;
}

//--------- QUE FEIO, QUE FEEEEEIO, nao precisaria se tivesse sido mais esperto no passado -------------------------------------
std::vector<unsigned char> gambiarra(const std::vector<size_t>& perm){
    std::vector<unsigned char> vetordotipocerto(perm.size());
    auto perm_size = perm.size();
    for (size_t i = 0; i < perm_size; i++){
        vetordotipocerto[i] = perm[i];
    }
    return std::move(vetordotipocerto);
}
//------------------------------------------------------------------------
// takes care of all the indexation logic
// returns an iterator to the pdb table for a specific state

unsigned char* PDB::tableLocation(const Puzzle& p){
    std::vector<unsigned char> tile_locations = getTileLocations(p);
    std::vector<unsigned char> sorted_tile_locations = tile_locations;

    std::function compare = [](const unsigned char& a, const unsigned char& b){ return a < b;};
    auto permutation = IndexingFunctions::sortPermutation(tile_locations, compare);
    sorted_tile_locations = IndexingFunctions::applyPermutation(sorted_tile_locations, permutation);

    auto rank_tile_locations = IndexingFunctions::toCombinadicBase(sorted_tile_locations);
    auto rank_permutation = IndexingFunctions::rank(gambiarra(permutation));

    return (&pattern_values[rank_tile_locations][rank_permutation]);
}

//---------------------------------------------------------------------------------------
// this can be improved by using a abstracted version of the puzzle
// no time for now!
void PDB::fillPatternArray(){

    //initial state (goal state for the search method)
    Puzzle p(rows, columns);
    *tableLocation(p) = 0;

    std::queue<Puzzle> open;
    open.emplace(p);

    while (!open.empty()){
        auto current = open.front();
        open.pop();

        auto neighbours = expand(current);
        for (auto i : neighbours){
            if (*tableLocation(i) == ULONG_MAX){
                *tableLocation(i) = *tableLocation(current) + 1;
                open.emplace(i);
            }
        }
    }
}

std::list<Puzzle> expand(const Puzzle& p){
    std::list<Puzzle> neighbours;

    auto available_moves = p.availableMoves();
    for (auto i : available_moves){
        Puzzle temp = p;
        temp.makeMove(i);
        neighbours.emplace_back(temp);
    }
    return std::move(neighbours);
}

void PDB::shapePatternArray(){

    size_t tile_combinations  = IndexingFunctions::binomialCoef(rows * columns, pdb_tiles.size() + 1); //+1 because pdb_tiles disregard zero;
    size_t tile_perms_per_combination = IndexingFunctions::factorial(tile_combinations);

    pattern_values = std::vector<std::vector<unsigned char>>(
        tile_combinations,
        std::vector<unsigned char>(IndexingFunctions::factorial(tile_perms_per_combination), ULONG_MAX)
    );
}

//---------------------------- DO NOT PASS 0 AS ARGUMENT INSIDE OF PDB_TILES ------------------
//---------------------------- please ---------------------------------------------------------
bool PDB::build (const Puzzle& initial_state, const Puzzle& goal_state, const std::vector<unsigned char>& pdb_tiles){
    rows = initial_state.getBoard().getRows();
    columns = initial_state.getBoard().getColumns();

    //pdb tiles should disregard zero
    this->pdb_tiles = pdb_tiles;
    std::sort(pdb_tiles.begin(), pdb_tiles.end());

    shapePatternArray();
    fillPatternArray();
}

PDB::PDB(){

}

PDB::~PDB(){

}
#endif