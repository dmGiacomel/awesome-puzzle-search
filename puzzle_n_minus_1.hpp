#ifndef puzzle_n_minus_1_hpp
#define puzzle_n_minus_1_hpp
#include <iostream>
#include <tuple>
#include <set>
#include "Matrix.hpp"

enum moves: unsigned char {left, up, right, down, none};
enum move_contraries: unsigned char {r, d, l, u, n};

class Puzzle{
public:

    //Really Default Constructor
    Puzzle();

    //Default Constructor
    Puzzle(unsigned char rows, unsigned char columns);

    //copy constructor
    Puzzle(const Puzzle& other);

    //move consctructor
    Puzzle(Puzzle&& other) noexcept;

    //copy assignement operator
    Puzzle& operator=(const Puzzle& other);

    //move assignement operator
    Puzzle& operator=(Puzzle&& other) noexcept;

    //destructor
    ~Puzzle();

    bool isSolved() const;
    bool makeMove(moves move);
    unsigned char getTileAt(unsigned char row, unsigned char column) const;
    void printBoard() const;
    const Matrix<unsigned char>& getBoard() const;
    std::set<moves> availableMoves() const;

    std::vector<unsigned char> getPuzzleAsString () const;
    bool operator== (const Puzzle& other) const;
private:
    
    Matrix<unsigned char> board;
    std::tuple<unsigned char, unsigned char> position_of_empty;

    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    
};
#endif