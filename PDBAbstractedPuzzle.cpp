#ifndef PDB_ABSTRACTED_PUZZLE_CPP
#define PDB_ABSTRACTED_PUZZLE_CPP
#include "PDBAbstractedPuzzle.hpp"

PDBAbstraction::PDBAbstraction (const std::vector<unsigned char>& initial_tile_permutation,
                                const std::vector<unsigned char>& initial_tile_locations,
                                int puzzle_rows, int puzzle_columns)
    :tile_permutation(initial_tile_permutation), tile_locations(initial_tile_locations), Puzzle(puzzle_rows,puzzle_columns)
{
    //setting the tile vector to properly allocate a puzzle
    std::vector<unsigned char> tile_vector(getAbstractVector(puzzle_rows*puzzle_columns));

    //changing superclass atributes from within the derived class in order to properly set
    //Puzzle fields. This seems to be a not so ellegant solution, but will do for now without messing with
    //the current code structure (no time for testing for now, also)

    auto tile_vector_iterator = tile_vector.cbegin();
    for (int i = 0; i < puzzle_rows; i++){
        for (int j = 0; j < puzzle_columns; j++){
            board.setValueAt(i, j, *tile_vector_iterator);
            tile_vector_iterator++;
        }
    }    


}

PDBAbstraction::~PDBAbstraction(){}

std::vector<unsigned char> PDBAbstraction::getAbstractVector(int puzzle_size) const{
    std::vector<unsigned char> abstracted_board(puzzle_size);

    for(int i = 0; i < puzzle_size; i++){
        abstracted_board[i] = ABSTRACTED_TILE;
    }
    for(auto i: tile_locations){
        abstracted_board[i] = tile_permutation[i];
    }

    return std::move(abstracted_board);
}

std::vector<unsigned char> PDBAbstraction::getPermutation() const{
    return tile_permutation;
}
std::vector<unsigned char> PDBAbstraction::getLocations() const{
    return tile_locations;
}


void PDBAbstraction::printAbstraction(){

    auto rows = board.getRows();
    auto columns = board.getColumns();
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if (board.getValueAt(i,j) == ABSTRACTED_TILE){
                std::cout << "x\t";
            }else{
                std::cout << +board.getValueAt(i,j) << "\t";
            }
        }
        std::cout << std::endl;
    }
}


#endif