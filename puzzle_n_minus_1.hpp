#ifndef puzzle_n_minus_1_hpp
#define puzzle_n_minus_1_hpp
#include <iostream>
#include <tuple>
#include <set>
#include "Matrix.hpp"

enum moves: unsigned char {left, up, right, down};

class Puzzle{
public:

    //Default Constructor
    Puzzle(int rows, int columns);

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

    bool isSolved();
    bool makeMove(moves move);
    short getTileAt(int row, int column);
    void printBoard();
    const Matrix<short>& getBoard() const;
    std::set<moves> availableMoves();
    
    bool operator== (const Puzzle& other);
private:
    
    Matrix<short> board;
    std::tuple<int, int> position_of_empty;

    void moveUp();
    void moveLeft();
    void moveRight();
    void moveDown();
    
};


#endif