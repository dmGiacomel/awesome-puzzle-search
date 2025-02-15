#ifndef APDB_ABSTRACTION_PUZZLE_HPP
#define APDB_ABSTRACTION_PUZZLE_HPP 
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include "puzzle_n_minus_1.hpp"
#include "Utils/IndexFunctions.hpp"
#include <unordered_map>
#include <unordered_set>
#include "zero_tile_region_mapping.hpp"

//compile this test: g++ abstraction_test.cpp PDBAbstractedPuzzle.cpp puzzle_n_minus_1.cpp Utils/IndexFunctions.cpp -o abstraction_test.x

const unsigned char ABSTRACTED_TILE = 0xff;

class APDBAbstraction : public Puzzle {

public:

    APDBAbstraction (const std::vector<unsigned char>& initial_tile_permutation,
                    const std::vector<unsigned char>& initial_tile_locations,
                    int puzzle_rows, int puzzle_columns, std::tuple <unsigned char, unsigned char> zero_position);

    APDBAbstraction (const std::vector<unsigned char>& initial_tile_permutation,
                    const std::vector<unsigned char>& initial_tile_locations,
                    int puzzle_rows, int puzzle_columns, unsigned char zero_tile_region);

    APDBAbstraction (const Puzzle& state, const std::vector<unsigned char>& pdb_tiles);

    ~APDBAbstraction ();

    //copy constructor
    APDBAbstraction(const APDBAbstraction& other);

    //move consctructor
    APDBAbstraction(APDBAbstraction&& other) noexcept;

    //copy assignement operator
    APDBAbstraction& operator=(const APDBAbstraction& other);

    //move assignement operator
    APDBAbstraction& operator=(APDBAbstraction&& other) noexcept;

    void setBoard(const std::vector<unsigned char>& initial_tile_permutation,
                  const std::vector<unsigned char>& initial_tile_locations, std::tuple <unsigned char, unsigned char> zero_position);

    const std::vector<unsigned char>& getPermutation() const;
    const std::vector<unsigned char>& getLocations() const;

    virtual bool makeMove(moves move);
    void printAbstraction();

protected:

    std::vector<unsigned char> tile_permutation;
    std::vector<unsigned char> tile_permutation_dual;
    std::vector<unsigned char> tile_locations;
    ZeroRegionMapping zero_map;

    std::vector<unsigned char> getAbstractVector(int puzzle_size) const;
};

#endif