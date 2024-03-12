#ifndef SEARCH_NODE_HPP
#define SEARCH_NODE_HPP
#include "../puzzle_n_minus_1.hpp"

typedef struct SearchNode{

    SearchNode* parent;
    Puzzle state;
    double f;
    double g; 
    double h;

    //default constructor
    //Puzzle must be a copy
    SearchNode(SearchNode* parent, const Puzzle& s, double f, double g, double h); 
    //SearchNode();

    //copy constructor
    SearchNode(const SearchNode& other);

    //copy assignement operator
    SearchNode& operator= (const SearchNode& other);
    
    //destructor
    //parent should take care of it's own mem., since this will mimic linked lists
    ~SearchNode();

}SearchNode;

#endif