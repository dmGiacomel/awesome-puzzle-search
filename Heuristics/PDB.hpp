#ifndef PDB_HPP
#define PDB_HPP
#include "Heuristics.hpp"
#include "../Utils/IndexFunctions.hpp"
#include <queue>
#include <set>
#include <tuple>
#include <list>
#include <vector>

class PDB : public Heuristics{
public:

    virtual int evaluate (const Puzzle& puzzle_state);

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state, const std::vector<unsigned char>& pdb_tiles);

    PDB();

    virtual ~PDB();

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state);

private:

    void shapePatternArray();
    void fillPatternArray();

    std::set<Puzzle> expand(const Puzzle& p);
    std::vector<unsigned char> getTileLocations(const Puzzle& p);
    unsigned char* tableLocation(const Puzzle& p);

    int rows;
    int columns;
    
    std::vector<unsigned char> pdb_tiles;
    std::vector<std::vector<unsigned char>> pattern_values;

};
#endif