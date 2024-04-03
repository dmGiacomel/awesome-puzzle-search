#ifndef IDASTAR_HPP
#define IDASTAR_HPP
#include "SolvingAlgorithm.hpp"
#include "SearchNode.hpp"
#include "set"

class IDAStar : public SolvingAlgorithm{
public: 
    
    virtual std::list<moves> solve(const Puzzle& initial_state, 
                                   const Puzzle& goal_state,
                                   Heuristics* heuristic);

    IDAStar();
    virtual ~IDAStar();

private: 
    
    Heuristics* heuristics;
    Puzzle initial_state;
    Puzzle goal_state;

    std::list<moves> makeMovesList(const SearchNode& goal_state);
    std::list<moves> driverProcedure();
    std::list<moves> idaStar();
    std::set<SearchNode> generateSuccessors(const SearchNode& state);

};
#endif