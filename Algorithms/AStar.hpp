#ifndef A_STAR_HPP
#define A_STAR_HPP
#include "../puzzle_n_minus_1.hpp"
#include "SolvingAlgorithm.hpp"
#include "../Heuristics/Heuristics.hpp"
#include "SearchNode.hpp"
#include <queue>
#include <list>
#include <set>

class AStar : SolvingAlgorithm{   

public:
    std::list<moves> solve(const Puzzle& initial_state, 
                           const Puzzle& goal_state,
                           Heuristics* heuristic = nullptr);

private:
    Heuristics* heuristics;
    Puzzle initial_state;
    Puzzle goal_state;

    //open and closed set
    struct GreaterF {
        bool operator()(const SearchNode& s1, const SearchNode& s2) const;
    };

    std::priority_queue<SearchNode, std::vector<SearchNode>, GreaterF> open;
    std::set<SearchNode> closed;


    std::list<moves> makeMovesList(SearchNode& goal_state); 
    std::list<moves> driverProcedure();
    void update(SearchNode& state);



};

#endif