#ifndef APDB_HPP
#define APDB_HPP
#include "Heuristics.hpp"
#include "../Utils/IndexFunctions.hpp"
#include <queue>
#include <set>
#include <tuple>
#include <list>
#include <string>
#include <unordered_set>
#include <functional>
#include <vector>
#include "../puzzle_n_minus_1.hpp"
#include <bitset>
#include <chrono>

class APDB : public Heuristics{
public:

    virtual int evaluate (const Puzzle& puzzle_state);

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state, const std::vector<unsigned char>& pdb_tiles);

    APDB();

    virtual ~APDB();

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state);

private:

    void shapePatternArray();
    void shapePdbPatternArray();
    void shapePdbAcumulator();
    void fillPatternArray();

    std::vector<size_t> getTileLocations(const Puzzle& p);
    unsigned char* tableLocation(const Puzzle& p);

    std::pair<size_t, size_t> pdbTableLocation(const Puzzle& p);
    std::vector<size_t> getPdbTileLocations(const Puzzle& p);
    

    std::list<Puzzle> expand(const Puzzle& p);
    std::list<Puzzle> transitiveHullOfZeroCostActions(const Puzzle& p);
    size_t verify();
    
    int rows;
    int columns;
    
    std::vector<std::vector<bool>> pdb_bitmap;
    std::vector<std::vector<std::vector<unsigned char>>> pdb_acumulator;
    std::vector<unsigned char> pdb_tiles;
    std::vector<std::vector<unsigned char>> pattern_values;

};

#endif