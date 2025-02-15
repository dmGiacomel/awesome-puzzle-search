#ifndef ADDITIVE_PDB_HPP
#define ADDITIVE_PDH_HPP
#include "Heuristics.hpp"
#include "../Utils/IndexFunctions.hpp"
#include "../Utils/MovementsHandler.hpp"
#include <queue>
#include <set>
#include <tuple>
#include <list>
#include <vector>
#include "../puzzle_n_minus_1.hpp"
#include <map>
#include "../APDBAbstractedPuzzle.hpp"
#include <omp.h>

const unsigned char INFINITY = UCHAR_MAX;

class APDB : public Heuristics{
public:

    virtual int evaluate (const Puzzle& puzzle_state);
 
    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state, const std::vector<unsigned char>& pdb_tiles);

    APDB();

    virtual ~APDB();

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state);

    void histogram();

    size_t verify();

private:

    void shapePatternArray();
    void shapeTempZpd();
    void fillPatternArray();

    std::tuple<size_t, size_t> getIndexes(const APDBAbstraction& abs);
    APDBAbstraction unindex (size_t locations, size_t permutation); 
    APDBAbstraction unindex (const std::tuple<size_t, size_t>& indexes); 

    unsigned char patternValueAt(const std::tuple<size_t, size_t>& indexes);
    unsigned char patternValueAt(size_t locations, size_t permutation);

    void setPatternValueAt(const std::tuple<size_t, size_t>& indexes, unsigned char value);
    void setPatternValueAt(size_t locations, size_t permutation, unsigned char value);

    size_t expandAndUpdate(APDBAbstraction& p, unsigned char current_level);

    int rows;
    int columns;
    unsigned char n_pdb_tiles;
    size_t total_tile_locations;
    size_t total_tile_permutations;
    
    std::vector<unsigned char> pdb_tiles;
    std::vector<std::vector<unsigned char>> pattern_values;
    std::vector<std::vector<std::vector<unsigned char>>> temp_zpd;

};
#endif