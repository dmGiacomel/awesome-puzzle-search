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

    std::tuple<size_t, size_t> getIndexes(const PDBAbstraction& abs);
    PDBAbstraction unindex (size_t locations, size_t permutation); 
    PDBAbstraction unindex (const std::tuple<size_t, size_t>& indexes); 

    unsigned char patternValueAt(const std::tuple<size_t, size_t>& indexes);
    unsigned char patternValueAt(size_t locations, size_t permutation);

    void setPatternValueAt(const std::tuple<size_t, size_t>& indexes, unsigned char value);
    void setPatternValueAt(size_t locations, size_t permutation, unsigned char value);

    std::list<PDBAbstraction> expand(const PDBAbstraction& p);

    size_t verify();

    int rows;
    int columns;
    unsigned char n_pdb_tiles;
    size_t total_tile_locations;
    size_t total_tile_permutations;
    
    std::vector<unsigned char> pdb_tiles;
    std::vector<std::vector<unsigned char>> pattern_values;

};
#endif