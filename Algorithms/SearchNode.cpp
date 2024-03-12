#ifndef SEARCH_NODE_CPP
#define SEARCH_NODE_CPP
#include "SearchNode.hpp"

//default constructor
    SearchNode::SearchNode(SearchNode* parent, const Puzzle& state, double f, double g, double h)
        :parent(parent), state(state), f(f), g(g), h(h)
    {
    }

    //copy constructor
    SearchNode::SearchNode(const SearchNode& other)
        :parent(other.parent), state(other.state), f(other.f), g(other.g), h(other.h)
    {
    }

    //copy assignement operator
    SearchNode& SearchNode::operator= (const SearchNode& other)
    {
        if (this != &other){
            parent = other.parent;
            state = other.state;
            f = other.f;
            g = other.g; 
            h = other.h;
        }

        return *this;
    }

    //destructor
    //parent should take care of it's own allocation, since this will mimic linked lists
    SearchNode::~SearchNode(){}


#endif