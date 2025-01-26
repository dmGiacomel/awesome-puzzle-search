#ifndef PDB_HPP
#define PDB_HPP
#include "Heuristics.hpp"
#include "../Utils/IndexFunctions.hpp"
#include <queue>
#include <set>
#include <tuple>
#include <list>
#include <vector>
#include "../puzzle_n_minus_1.hpp"
#include <map>
#include "../PDBAbstractedPuzzle.hpp"

const unsigned char INFINITY = UCHAR_MAX;

class PDB : public Heuristics{
public:

    virtual int evaluate (const Puzzle& puzzle_state);
 
    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state, const std::vector<unsigned char>& pdb_tiles);

    PDB();

    virtual ~PDB();

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state);

    void histogram();

private:

    void shapePatternArray();
    void fillPatternArray();

    std::vector<size_t> getTileLocations(const Puzzle& p);

    // unsigned char* tableLocation(const Puzzle& p);
    std::tuple<size_t, size_t> tableIndexes(const Puzzle& p);

    std::list<Puzzle> expand(const Puzzle& p);
    size_t verify();

    int rows;
    int columns;

    size_t total_tile_locations;
    size_t total_tile_permutations;
    
    std::vector<unsigned char> pdb_tiles;
    std::vector<std::vector<unsigned char>> pattern_values;

};
#endif