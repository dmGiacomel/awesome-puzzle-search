#ifndef SEARCH_NODE_CPP
#define SEARCH_NODE_CPP
#include "SearchNode.hpp"

SearchNode::SearchNode(SearchNode* parent, const Puzzle& s, double f, double g, double h) 
        :parent(parent), state(std::move(s)), f(f), g(g), h(h)
{
}

SearchNode::SearchNode(const Puzzle& s)
        :state(std::move(s))
{
}

SearchNode::SearchNode(const SearchNode& other)
    : parent(other.parent), state(other.state), f(other.f), g(other.g), h(other.h) {}

#endif