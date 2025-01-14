#ifndef PDB_ABSTRACTED_PUZZLE_HPP
#define PDB_ABSTRACTED_PUZZLE_HPP
#include <unordered_set>
#include <vector>
#include "puzzle_n_minus_1.hpp"
#include "Matrix.hpp"

const unsigned char ABSTRACTED_TILE = 0xff;

class PDBAbstraction : protected Puzzle {

public:

    PDBAbstraction (const std::vector<unsigned char>& initial_tile_permutation,
                    const std::vector<unsigned char>& initial_tile_locations,
                    int puzzle_rows, int puzzle_columns);

    ~PDBAbstraction ();

    void setBoard(const std::vector<unsigned char>& initial_tile_permutation,
                  const std::vector<unsigned char>& initial_tile_locations);


    std::vector<unsigned char> getPermutation() const;
    std::vector<unsigned char> getLocations() const;

    void printAbstraction();

protected:

    std::vector<unsigned char> tile_permutation;
    std::vector<unsigned char> tile_locations;

    std::vector<unsigned char> getAbstractVector(int puzzle_size) const;

};

#endif