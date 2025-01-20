#ifndef PDB_ABSTRACTED_PUZZLE_CPP
#define PDB_ABSTRACTED_PUZZLE_CPP
#include "PDBAbstractedPuzzle.hpp"


//the class object can be reused in order to avoid Puzzle object allocations
//
PDBAbstraction::PDBAbstraction (const std::vector<unsigned char>& initial_tile_permutation,
                                const std::vector<unsigned char>& initial_tile_locations,
                                int puzzle_rows, int puzzle_columns)
    :tile_permutation(initial_tile_permutation), tile_permutation_dual(IndexingFunctions::getDual(initial_tile_permutation)), 
    tile_locations(initial_tile_locations), Puzzle(puzzle_rows,puzzle_columns)
{
    setBoard(initial_tile_locations, initial_tile_permutation);
}

PDBAbstraction::~PDBAbstraction(){}

void PDBAbstraction::setBoard(const std::vector<unsigned char>& initial_tile_permutation,
                              const std::vector<unsigned char>& initial_tile_locations){

    auto puzzle_rows = this->board.getRows();
    auto puzzle_columns = this->board.getColumns();
    //setting the tile vector to properly allocate a puzzle
    std::vector<unsigned char> tile_vector(puzzle_rows * puzzle_columns);

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

    //not checking for errors at all. use it perfectly under the proper conditions
    auto position_of_empty_in_tile_vector = tile_permutation_dual[0];

    position_of_empty = std::make_tuple((unsigned char)(position_of_empty_in_tile_vector / puzzle_columns), 
                                        (unsigned char)(position_of_empty_in_tile_vector % puzzle_columns));
}

std::vector<unsigned char> PDBAbstraction::getAbstractVector(int puzzle_size) const{
    std::vector<unsigned char> abstracted_board(puzzle_size);

    for(int i = 0; i < puzzle_size; i++){
        abstracted_board[i] = ABSTRACTED_TILE;
    }

    int tile_perm_index = 0;
    for(auto i: tile_locations){
        abstracted_board[i] = tile_permutation[tile_perm_index++];
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

bool PDBAbstraction::makeMove(moves move){

    auto old_zero_tile_row = std::get<0>(position_of_empty);
    auto old_zero_tile_column = std::get<1>(position_of_empty);
    bool move_succesful = Puzzle::makeMove(move);

    if (move_succesful){
        //get tile that was swaped with zero
        auto swaped_tile = board.getValueAt(old_zero_tile_row, old_zero_tile_column);       
        if (swaped_tile != ABSTRACTED_TILE){
            
            //LOT'S of variables in the hope it reduces memory access with proper optimization due
            //to most of it being dependendent on accessing object fields through the same functions
            //each variable is also used more than once

            auto puzzle_columns = this->board.getColumns();

            auto new_zero_tile_row = std::get<0>(position_of_empty);
            auto new_zero_tile_column = std::get<1>(position_of_empty);

            auto new_moved_tile_vector_position = old_zero_tile_row * puzzle_columns + old_zero_tile_column;
            auto new_zero_tile_vector_position = new_zero_tile_row * puzzle_columns + new_zero_tile_column;

            tile_permutation_dual[swaped_tile] = new_moved_tile_vector_position;
            tile_permutation_dual[0] = new_zero_tile_vector_position;

            tile_permutation[new_moved_tile_vector_position] = swaped_tile;
            tile_permutation[new_zero_tile_vector_position] = 0;


        }else{

        }
    }
}

#endif