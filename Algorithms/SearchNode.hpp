#ifndef SEARCH_NODE_HPP
#define SEARCH_NODE_HPP
#include "../puzzle_n_minus_1.hpp"

typedef struct SearchNode{

    SearchNode* parent;
    Puzzle state;
    double f;
    double g; 
    double h;

    SearchNode(SearchNode* parent, const Puzzle& s, double f, double g, double h); 
    SearchNode(const Puzzle& s);
    SearchNode::SearchNode(const SearchNode& other);

}SearchNode;

#endif