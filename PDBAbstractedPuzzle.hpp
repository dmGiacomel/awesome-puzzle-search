#ifndef PDB_ABSTRACTED_PUZZLE_HPP
#define PDB_ABSTRACTED_PUZZLE_HPP
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include "puzzle_n_minus_1.hpp"
#include "Matrix.hpp"
#include "Utils/IndexFunctions.hpp"

const unsigned char ABSTRACTED_TILE = 0xff;

class PDBAbstraction : public Puzzle {

public:

    PDBAbstraction (const std::vector<unsigned char>& initial_tile_permutation,
                    const std::vector<unsigned char>& initial_tile_locations,
                    int puzzle_rows, int puzzle_columns);

    ~PDBAbstraction ();

    void setBoard(const std::vector<unsigned char>& initial_tile_permutation,
                  const std::vector<unsigned char>& initial_tile_locations);


    std::vector<unsigned char> getPermutation() const;
    std::vector<unsigned char> getLocations() const;

    virtual bool makeMove(moves move);
    void printAbstraction();

protected:

    std::vector<unsigned char> tile_permutation;
    std::vector<unsigned char> tile_permutation_dual;
    std::vector<unsigned char> tile_locations;

    std::vector<unsigned char> getAbstractVector(int puzzle_size) const;

};

#endif