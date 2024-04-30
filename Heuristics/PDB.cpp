#ifndef PDB_CPP
#define PDB_CPP
#include "PDB.hpp"

int PDB::evaluate (const Puzzle& puzzle_state){

}

//tile_locations is always in ascending order
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

// this can be improved by using a abstracted version of the puzzle
// no time for now!
void PDB::fillPatternArray(){
    Puzzle p(rows, columns);
    std::vector<unsigned char> pdb_dual = getTileLocations(p);

    getTileLocations(tile_location);
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