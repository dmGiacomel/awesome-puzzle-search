#ifndef PDB_HPP
#define PDB_HPP
#include "Heuristics.hpp"

class PDB : public Heuristics{
public:

    virtual int evaluate (const Puzzle& puzzle_state);

    virtual bool build (const Puzzle& initial_state, const Puzzle& goal_state);

    PDB();

    virtual ~PDB();

private:

    unsigned char *pattern_values;

};
#endif